#ifndef REFPROP_MANAGER_HPP
#define REFPROP_MANAGER_HPP

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

static void HandleException(int *errcode, char *message_buffer, const int buffer_length)
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

static void HandleExceptionNoMsg(int *errcode)
{
    try {
        throw; // Rethrow the error, and here we handle the error
    }
    catch (InvalidHandle &e) {
        *errcode = 1;
    }
    catch (...) {
        *errcode = -1;
    }
}

#include "manyso/native.h"
#include "manyso/exceptions.h"

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
            throw std::invalid_argument("Constructed path to shared library is invalid:" + shared_library_path);
        }

        auto load_method = AbstractSharedLibraryWrapper::load_method::LOAD_LIBRARY_PRISTINE;
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
    REFPROPInstance(REFPROPInstance&& data): RP(std::move(data.RP)) {}
    ~REFPROPInstance() {
        RP.release();
    }

    // And now, totally magical, the use of variadic function arguments in concert with type macros
    // Add many methods, each corresponding to a 1-to-1 wrapper of a function from the shared library
#define X(name) template<class ...Args> void name(Args&&... args){ return ((name ## _POINTER) RP->get_method_pointer(#name))(std::forward<Args>(args)...); };
    LIST_OF_REFPROP_FUNCTION_NAMES
#undef X
};

EXPORT_CODE int CONVENTION construct_handle(const char *path, const char *DLL_filename, int *errcode, char *errmsg, const int buffer_length);
EXPORT_CODE void CONVENTION free_handle(int handle, int *errcode, char *errmsg, const int buffer_length);

#define RP_FUNCTION_PARAM_GENERATOR_MACRO(r, data, i, elem) BOOST_PP_COMMA() elem arg_##i 

#define RP_FUNCTION_ARG_GENERATOR_MACRO(r, data, i, elem) BOOST_PP_COMMA_IF(i) arg_##i 

// Prototypes for each function exported from the REFPROP DLL
// 
// Generates for each REFPROP-function something like
// extern "C" __declspec(dllexport) void __stdcall ABFL1dll(int handle, int *errcode, double &  arg_0, ... , std::size_t  arg_13); 
#define RP_FUNCTION_GENERATOR_MACRO(r, data, elem)          \
	EXPORT_CODE void CONVENTION elem\
( int handle, int *errcode \
BOOST_PP_SEQ_FOR_EACH_I(RP_FUNCTION_PARAM_GENERATOR_MACRO,_,BOOST_PP_IF(BOOST_VMD_IS_EMPTY(BOOST_PP_CAT(elem,_ARGS)),,BOOST_PP_TUPLE_TO_SEQ((BOOST_PP_CAT(elem,_ARGS))))) \
);

// Now actually export all functions
#define X(arg) (arg)
BOOST_PP_SEQ_FOR_EACH(RP_FUNCTION_GENERATOR_MACRO, _, LIST_OF_REFPROP_FUNCTION_NAMES)
#undef X

#endif