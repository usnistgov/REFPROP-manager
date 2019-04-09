project(REFPROPManager)
cmake_minimum_required(VERSION 3.1)

# We heavily use C++11, C++11 support is required
set (CMAKE_CXX_STANDARD 11)

add_subdirectory("${CMAKE_SOURCE_DIR}/externals/boost-cmake")

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

set(NAMEstatic "${NAME}static")
set(NAMEexample "${NAME}example")

set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/manager.cpp")
if (WIN32)
  list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/externals/manyso/externals/MemoryModule/MemoryModule.c")
endif()

# THE EXAMPLE
# -----------
add_executable(${NAMEexample} ${SOURCES} "${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp")
target_compile_definitions(${NAMEexample} PRIVATE -DNOT_DLL)
target_link_libraries(${NAMEexample} PRIVATE Boost::filesystem)

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