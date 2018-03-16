#include <string>
#include <map>
#include <memory>

#include <boost/preprocessor.hpp>
#include <boost/filesystem.hpp>
#include <boost/vmd/vmd.hpp>

#define REFPROP_ONLY_MACROS
#include "REFPROP_lib.h"
#undef REFPROP_ONLY_MACROS

class InvalidHandle : public std::exception {
private:
    std::size_t m_code;
    std::string m_errstr;
    virtual const char* what() const throw() override {
        return m_errstr.c_str();
    };
public:
    InvalidHandle(const std::string &errstr, std::size_t code) throw() : m_errstr(errstr), m_code(code) {};
};

void HandleException(int *errcode, char *message_buffer, const int buffer_length)
{
    try {
        throw; // Rethrow the error, and here we handle the error
    }
    catch (std::exception &e) {
        std::string errmsg = std::string("exception: ") + e.what();
        if (errmsg.size() < static_cast<std::size_t>(buffer_length)) {
            *errcode = 1;
            strcpy(message_buffer, errmsg.c_str());
        }
        else {
            *errcode = 2;
        }
    }
    catch (...) {
        *errcode = 3;
    }
}

void HandleExceptionNoMsg(int *errcode)
{
    try {
        throw; // Rethrow the error, and here we handle the error
    }
    catch (InvalidHandle &e){
        *errcode = 1;
    }
    catch (...) {
        *errcode = -1;
    }
}

#include "manyso/native.h"
#include "manyso/exceptions.h"

static std::string REFPROP_PATH = "";

#if defined(NOT_DLL)
#define EXPORT_CODE
#define CONVENTION 
#else
#include "EXPORTS.h"
#endif

class REFPROPInstance
{
private:
#define X(name) typedef void (RPCALLCONV name ## _TYPE)(name ## _ARGS);
    LIST_OF_REFPROP_FUNCTION_NAMES
#undef X
#define X(name) typedef name ## _TYPE * name ## _POINTER;
        LIST_OF_REFPROP_FUNCTION_NAMES
#undef X

        std::unique_ptr<NativeSharedLibraryWrapper> RP;
public:
    REFPROPInstance(const std::string &path, const std::string &shared_library_filename)
    {
        namespace fs = boost::filesystem;
        // See https://stackoverflow.com/a/8725664/1360263
        fs::path joined = (fs::path(path) / fs::path(shared_library_filename)).make_preferred();
        std::string shared_library_path = joined.string();
        if (!fs::is_regular_file(joined)) {
            throw std::invalid_argument("Constructed path to shared library is invalid:"+shared_library_path);
        }

        auto load_method = AbstractSharedLibraryWrapper::load_method::FROM_FILE;
        RP.reset(new NativeSharedLibraryWrapper(shared_library_path, load_method));

        // Check that the load was a success
        bool loaded_properly = std::get<0>(RP->is_locked());
        if (!loaded_properly) {
            throw InvalidLoad("Unable to load the shared library", 0);
        }

        // Set the path in REFPROP
        char * c_path = const_cast<char *>(path.c_str());
        SETPATHdll(c_path, path.size());
    }
    ~REFPROPInstance() {
        RP.release();
    }

    // And now, totally magical, the use of variadic function arguments in concert with type macros
    // Add many methods, each corresponding to a 1-to-1 wrapper of a function from the shared library
    #define X(name) template<class ...Args> void name(Args&&... args){ return RP->getAddress<name ## _POINTER>(#name)(std::forward<Args>(args)...); };
        LIST_OF_REFPROP_FUNCTION_NAMES
    #undef X
};

std::map<int, REFPROPInstance> handle_map;

/**
 @param path The path to the folder that contains the REFPROP shared library, as well as fluids and mixtures directories
 @param DLL_filename The filename (e.g., "REFPROP.dll") of the shared library that is to be loaded.  Make sure it matches the bitness of application
 @returns handle The handle to the returned DLL
 */
EXPORT_CODE int CONVENTION construct_handle(const char *path, const char *DLL_filename, int *errcode, char *errmsg, const int buffer_length) {
    try{
        int next_handle = static_cast<int>(handle_map.size()) + 1;
        handle_map.emplace(std::piecewise_construct,
                           std::forward_as_tuple(next_handle),
                           std::forward_as_tuple(path, DLL_filename));
        return next_handle;
    }
    catch (...) {
        HandleException(errcode, errmsg, buffer_length);
        return -1;
    }
}

REFPROPInstance & get_instance(int handle) {
    auto it = handle_map.find(handle);
    if (it != handle_map.end()) {
        return it->second;
    }
    else {
        throw InvalidHandle("Could not get handle:" + std::to_string(handle) + " for pool of size ", 0);
    }
}

EXPORT_CODE void CONVENTION free_handle(int handle, int *errcode, char *errmsg, const int buffer_length) {
    try {
        auto it = handle_map.find(handle);
        if (it != handle_map.end()) {
            handle_map.erase(it);
        }
        else {
            throw InvalidLoad("Could not free handle:" + std::to_string(handle) + " for pool of size ", 0);
        }
    }
    catch (...) {
        HandleException(errcode, errmsg, buffer_length);
    }
}

// generates for each Refprop-function something like
// extern "C" __declspec(dllexport) void __stdcall ABFL1dll(int handle, int *errcode, double &  arg_0, ... , std::size_t  arg_13) 
// { 
// 	try{ get_instance(handle).ABFL1dll(arg_0, ..., arg_13); } catch(...) { HandleExceptionNoMsg(errcode); }
// };
// ...

#define RP_FUNCTION_PARAM_GENERATOR_MACRO(r, data, i, elem)          \
	BOOST_PP_COMMA() elem arg_##i 

#define RP_FUNCTION_ARG_GENERATOR_MACRO(r, data, i, elem)          \
	BOOST_PP_COMMA_IF(i) arg_##i 

#define RP_FUNCTION_GENERATOR_MACRO(r, data, elem)          \
	EXPORT_CODE void CONVENTION elem\
( int handle, int *errcode \
BOOST_PP_SEQ_FOR_EACH_I(RP_FUNCTION_PARAM_GENERATOR_MACRO,_,BOOST_PP_IF(BOOST_VMD_IS_EMPTY(BOOST_PP_CAT(elem,_ARGS)),,BOOST_PP_TUPLE_TO_SEQ((BOOST_PP_CAT(elem,_ARGS))))) \
)\
{ try{ get_instance(handle).elem( \
BOOST_PP_SEQ_FOR_EACH_I(RP_FUNCTION_ARG_GENERATOR_MACRO,_,BOOST_PP_IF(BOOST_VMD_IS_EMPTY(BOOST_PP_CAT(elem,_ARGS)),,BOOST_PP_TUPLE_TO_SEQ((BOOST_PP_CAT(elem,_ARGS))))) \
); } catch(...) { HandleExceptionNoMsg(errcode);} };

// export all functions
#define X(arg) (arg)
BOOST_PP_SEQ_FOR_EACH(RP_FUNCTION_GENERATOR_MACRO, _, LIST_OF_REFPROP_FUNCTION_NAMES)
#undef X

#if defined(REFMAN_TEST)
int main() {

    char errmsg[255];
    int handle_errcode = 0; 
    int handle = construct_handle("D:/Code/REFPROP-cmake/build/10/Release/","REFPRP64.dll", &handle_errcode, errmsg, 255);

    int nc = 1;
    int ierr = 0;
    char herr[255], hfld[] = "WATER.FLD", hhmx[] = "HMX.BNC", href[] = "DEF";
    SETUPdll(handle, &handle_errcode, nc, hfld, hhmx, href, ierr, herr, 10000, 255, 3, 255);

    int kq = 1;
    double z[] = { 1.0 }, x[] = { 1.0 }, y[] = { 1.0 }, T = 300, p = 101.325, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
    PQFLSHdll(handle, &handle_errcode, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);

    return EXIT_SUCCESS;
}
#endif