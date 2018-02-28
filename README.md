
# Motivation

NIST REFPROP is a FORTRAN-based computational library for carrying out thermophysical property calculations.  It is non-trivial to carry out parallel evaluations with REFPROP, where you would like to like to have more encapsulation of the REFPROP library, or multiple copies of REFPROP running in parallel.

Enter ``REFPROP-manager``.

``REFPROP-manager`` is, as the name suggests, a manager DLL that allows you to hold multiple copies of the REFPROP DLL in memory.  Common previous workarounds to this problem involved multiple physical copies of the REFPROP dll.  This manager wraps up all the memory management into a package that looks and feels pretty much like the REFPROP dll with only a few small differences.

As motivation, here is a small example in Python of calling the manager class, with a lot of the details hidden away.  What you need to know is that the interface looks, to the user, EXACTLY like the "normal" python wrapper.  Additional examples in C++11 are shown below.

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

Caveats:

* REFPROP reads from file(s) during calls to ``SETUPdll`` or ``REFPROPdll``.  Therefore, instantiation of each of the instances should be done as a *serial* operation.  Afterwards, the flash calculations can be done in parallel.
* As usual, the bitness of all the DLL must match - the manager, REFPROP, and the calling program must all be 64-bit or 32-bit, no mixing and matching.
* The manager expects that the ``fluids`` and ``mixtures`` directories will be found in the same directory as the directory that the REFPROP DLL is in.

# Credits/License

The code that forms the base of the ``REFPROP-manager`` was written by Ian Bell, NIST, with significant contributions from Tobias Loew.  The code of ``REFPROP-manager`` is in the public domain.  Please see the licenses for the dependent libraries.

* MemoryModule, part of ``manyso``, is licensed with MPL v2.0.  The code of MemoryModule is linked through the ``manyso`` library.
* The headers for REFPROP come from the [REFPROP-headers](https://github.com/CoolProp/REFPROP-headers) repo (MIT license).

# Prerequisites

You will need, at the minimum, to build the manager:

* cmake
* a C++11 compatible compiler (on windows: MSVC 2015+; on linux: g++ or clang)
* [implicit] boost is also a dependency, but it is automatically downloaded and linked into the build

In order to *use* the manager, it is necessary to obtain either:

1. a statically-linked runtime linked copy of the REFPROP DLL such as is available with the conventional REFPROP installation 
2. [better] a built-it-yourself copy of the REFPROP DLL (from [REFPROP-cmake](https://github.com/usnistgov/REFPROP-cmake)) with the runtimes dynamically linked (pass the flag ``-DREFPROP_DYNAMIC_RUNTIME=ON`` to the cmake build command for the intel compiler)

**Warning:**  If you use a REFPROP DLL with the runtimes statically linked, you will be limited to creating approximately 120 copies of REFPROP; with the runtimes dynamically linked the number of instances of REFPROP is only limited by the available RAM of your computer.

# Build

The build of the manager is carried out with cmake.  The conventional out-of-source build paradigm for cmake is followed:

```
git clone --recursive https://github.com/usnistgov/REFPROP-manager
cd REFPROP-manager
cmake .. -G "Visual Studio 14 2015 Win64"
cmake --build . --config Release
```

When building with visual studio, the output DLL will be in the ``Release`` folder.  For more information on cmake options, please read the cmake documentation.