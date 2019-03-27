# Motivation

NIST REFPROP is a FORTRAN-based computational library for carrying out thermophysical property calculations.  It is non-trivial to carry out parallel evaluations with REFPROP, where you would like to like to have more encapsulation of the REFPROP library, or multiple copies of REFPROP running in parallel.

Enter ``REFPROP-manager``.

``REFPROP-manager`` is, as the name suggests, a manager DLL that allows you to hold multiple copies of the REFPROP DLL in memory.  Common previous workarounds to this problem involved multiple physical copies of the REFPROP dll.  This manager wraps up all the memory management into a package that looks and feels pretty much like the REFPROP dll with only a few small differences.

# Credits/License

The code that forms the base of the ``REFPROP-manager`` was written by Ian Bell, NIST, with significant contributions from Tobias Loew.  The code of ``REFPROP-manager`` is in the public domain.  Please see the licenses for the dependent libraries.

* MemoryModule, part of ``manyso``, is licensed with MPL v2.0.  The code of MemoryModule is linked through the ``manyso`` library.
* The headers for REFPROP come from the [REFPROP-headers](https://github.com/CoolProp/REFPROP-headers) repo (MIT license).

## In Python
As motivation, here is a small example in Python of calling the manager class, with a lot of the details hidden away.  What you need to know is that the interface looks, to the user, EXACTLY like the "normal" Python wrapper.

In Python:
``` python
# Get this Python module from https://github.com/usnistgov/REFPROP-wrappers/wrappers/python
import ctREFPROP.ctREFPROP as ct

# Absolute path to the folder that has a copy of REFPROP compiled 
# with dynamic linkage of the runtimes
path = r"D:\Code\REFPROP-cmake\build\10dyn\Release" 
# A "conventional" copy of the REFPROP dll
RP1 = ct.REFPROPFunctionLibrary(path, "dll")

# Now the magic starts... This is a Python wrapper of the manager shared library
manager = ct.REFPROPLibraryManager(r'D:\Code\REFPROP-manager\msvc\Release\REFMAN64.dll')
# Here is a copy of REFPROP that is loaded into the manager.  Internally, the handle
# is cached for subsequent calls into the DLL
RP2 = manager.get_instance(path,"REFPRP64.dll")

for RP in RP1,RP2:
    baseSI = RP.GETENUMdll(0, "MOLAR BASE SI  ").iEnum
    iMass = 0; iFlag = 0
    r = RP.REFPROPdll(r"AMMONIA.FLD", "TD","ETA",baseSI,iMass,iFlag,398.788,7044.7,[1.0]+[0.0]*19)
    print(r)
```

## In C++11

See the example in the folder ``test/test.cpp``.  You MUST use CMake to build to ensure that all dependencies are properly included.  A sample command line to generate the project and run the example would be:

```
git clone --recursive https://github.com/usnistgov/REFPROP-manager
cd REFPROP-manager
mkdir build && cd build
cmake .. -G "Visual Studio 14 2015 Win64"
cmake --build . --config Release --target REFMAN64example
```

You may need to change the path to the REFPROP folder in the CPP code, and you may also need to change the generator if you use a different version of Visual Studio (on windows), or use another operating system, in which case the generator is not needed at all.  Please check out the CMake documentation.

# Caveats:

* If you use a REFPROP DLL with the runtimes statically linked, you will be limited to creating approximately 120 copies of REFPROP; with the runtimes dynamically linked the number of instances of REFPROP is only limited by the available RAM of your computer.
* REFPROP reads from file(s) during calls to ``SETUPdll`` or ``REFPROPdll``.  Therefore, instantiation of each of the instances should be done as a *serial* operation.  Afterwards, the flash calculations can be done in parallel.
* As usual, the bitness of all the DLL must match - the manager, REFPROP, and the calling program must all be 64-bit or 32-bit, no mixing and matching.
* The manager expects that the ``FLUIDS`` and ``MIXTURES`` directories will be found in the same directory as the directory that the REFPROP DLL is in.

Each loaded instance of a DLL may require system-, process-, or thread-global resources. For instance on Windows DLLs linked against the static-runtime of Intel-Fortran require a fiber-local-storage-slot per loaded instance. Since the number of fiber-local-storage-slots seems to be limited to 128 per thread (the exact limit is not documented on MSDN; 128 tested for Windows 2016 Server) this puts a strict upper bound to the number of DLLs loaded simultaneously. Linking against the dynamic-runtime of Intel-Fortran does not impose this restrictions. Furthermore, linking against dynamic-runtime versions of Fortran, C and C++ has the benefit of reducing the overall size of used process-memory (another limiting global resource, especially in 32-bit processes).

# Build

## Prerequisites

You will need, at the minimum, to build the manager:

* cmake
* a C++11 compatible compiler (on windows: MSVC 2015+; on linux: g++ or clang)
* [implicit] boost is also a dependency, but it is automatically downloaded and linked into the build

In order to *use* the manager, it is necessary to obtain either:

1. a statically-linked runtime linked copy of the REFPROP DLL such as is available with the conventional REFPROP installation 
2. [better] a built-it-yourself copy of the REFPROP DLL (from [REFPROP-cmake](https://github.com/usnistgov/REFPROP-cmake)) with the runtimes dynamically linked (pass the flag ``-DREFPROP_DYNAMIC_RUNTIME=ON`` to the cmake build command for the intel compiler)

**Warning:**  

## CMake build

The build of the manager is carried out with cmake.  The conventional out-of-source build paradigm for cmake is followed:

```
git clone --recursive https://github.com/usnistgov/REFPROP-manager
cd REFPROP-manager
mkdir build
cd build
cmake .. -G "Visual Studio 14 2015 Win64"
cmake --build . --config Release
```

When building with visual studio, the output DLL will be in the ``Release`` folder.  For more information on cmake options, please read the cmake documentation.