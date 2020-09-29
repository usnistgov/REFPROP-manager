#include <string>
#include <map>
#include <memory>

#include "REFPROP-manager/REFPROP-manager.hpp"

static std::string REFPROP_PATH = "";

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


// generates for each REFPROP-function something like
// extern "C" __declspec(dllexport) void __stdcall ABFL1dll(int handle, int *errcode, double &  arg_0, ... , std::size_t  arg_13) 
// { 
// 	try{ get_instance(handle).ABFL1dll(arg_0, ..., arg_13); } catch(...) { HandleExceptionNoMsg(errcode); }
// };
// ...

#define RP_FUNCTION_GENERATOR_MACRO_CPP(r, data, elem)          \
	EXPORT_CODE void CONVENTION elem\
( int handle, int *errcode \
BOOST_PP_SEQ_FOR_EACH_I(RP_FUNCTION_PARAM_GENERATOR_MACRO,_,BOOST_PP_IF(BOOST_VMD_IS_EMPTY(BOOST_PP_CAT(elem,_ARGS)),,BOOST_PP_TUPLE_TO_SEQ((BOOST_PP_CAT(elem,_ARGS))))) \
)\
{ try{ get_instance(handle).elem( \
BOOST_PP_SEQ_FOR_EACH_I(RP_FUNCTION_ARG_GENERATOR_MACRO,_,BOOST_PP_IF(BOOST_VMD_IS_EMPTY(BOOST_PP_CAT(elem,_ARGS)),,BOOST_PP_TUPLE_TO_SEQ((BOOST_PP_CAT(elem,_ARGS))))) \
); } catch(...) { HandleExceptionNoMsg(errcode);} };

// export all functions
#define X(arg) (arg)
BOOST_PP_SEQ_FOR_EACH(RP_FUNCTION_GENERATOR_MACRO_CPP, _, LIST_OF_REFPROP_FUNCTION_NAMES)
#undef X