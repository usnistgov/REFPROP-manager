project(REFPROPManager)
cmake_minimum_required(VERSION 3.1)

# We heavily use modern C++, C++17 support is required
set (CMAKE_CXX_STANDARD 17)

# If a specific downloaded version of boost can be found in the externals folder, use it, otherwise 
# allow boost-cmake to pull in boost sources
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/externals/boost_1_71_0.tar.bz2")
    message(STATUS "Using local copy of boost")
    set(BOOST_URL "${CMAKE_CURRENT_SOURCE_DIR}/externals/boost_1_71_0.tar.bz2" CACHE STRING  "Boost zip file path")
    set(BOOST_URL_SHA256 "d73a8da01e8bf8c7eda40b4c84915071a8c8a0df4a6734537ddde4a8580524ee" CACHE STRING  "Boost zip file SHA256 checksum")
endif()

add_subdirectory("${CMAKE_SOURCE_DIR}/externals/boost-cmake")

macro(add_nix_libraries target)
    # See https://stackoverflow.com/a/29871891
    # Add DL and pthreads
    FIND_PACKAGE ( Threads REQUIRED )
    find_package(Threads REQUIRED)
    if(THREADS_HAVE_PTHREAD_ARG)
      target_compile_options(${target} PRIVATE "-pthread")
    endif()
    if(CMAKE_THREAD_LIBS_INIT)
      target_link_libraries(${target} PRIVATE "${CMAKE_THREAD_LIBS_INIT}")
    endif()
    target_link_libraries(${target} PRIVATE ${CMAKE_DL_LIBS})
endmacro()

# Determine the name of the library to be built
if (UNIX)
  set(NAME "refpropmanager")
else ()
  if (CMAKE_SIZEOF_VOID_P MATCHES "8")
    SET(NAME "REFMAN64")
  else()
    SET(NAME "REFMAN32")
  endif()
endif()

if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Do some global includes
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/REFPROP-headers")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/manyso/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/manyso/externals/MemoryModule")
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/manager.cpp")
if (WIN32)
  list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/externals/manyso/externals/MemoryModule/MemoryModule.c")
endif()

# THE EXAMPLES
# ------------

file(GLOB_RECURSE TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/test/test*.cpp")
foreach (testfile ${TEST_SOURCES})

  get_filename_component(snippet_name ${testfile} NAME)
  get_filename_component(snippet_exe ${testfile} NAME_WE)

  set(NAMEexample "${snippet_exe}")
  add_executable(${NAMEexample} ${SOURCES} "${testfile}")
  target_compile_definitions(${NAMEexample} PRIVATE -DNOT_DLL)
  target_link_libraries(${NAMEexample} PRIVATE Boost::filesystem)
  target_include_directories(${NAMEexample} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/externals/ThreadPool2")
  set_property(TARGET Boost_filesystem PROPERTY POSITION_INDEPENDENT_CODE ON)
  set_property(TARGET Boost_system PROPERTY POSITION_INDEPENDENT_CODE ON)
  if (NOT MSVC)
      add_nix_libraries(${NAMEexample})
  endif()
endforeach()

# THE SHARED LIBRARY
# ------------------

set(EXPORT_CODE "#define EXPORT_CODE extern \"C\"")
if (WIN32)
    set(EXPORT_CODE "#define EXPORT_CODE extern \"C\" __declspec(dllexport)")
endif()
set(CONVENTION "#define CONVENTION")
if (WIN32)
    set(CONVENTION "#define CONVENTION __stdcall")
endif()
message(STATUS "EXPORT_CODE: ${EXPORT_CODE}") 
message(STATUS "CONVENTION: ${CONVENTION}")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/EXPORTS.h.in" "${CMAKE_CURRENT_BINARY_DIR}/EXPORTS.h")

add_library(${NAME} SHARED ${SOURCES})
target_link_libraries(${NAME} PRIVATE Boost::filesystem)
if (UNIX)
  target_link_libraries(${NAME} PRIVATE ${CMAKE_DL_LIBS})
endif()