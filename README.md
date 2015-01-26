LLVMSharp - .NET bindings for LLVM
===================

This library is a .NET wrapper for [LLVM](http://llvm.org/) 3.2 written in C++/CLI. The bindings are written by hand and

## Building LLVM for LLVMSharp

To begin, we will need to download the appropriate [LLVM sources](http://llvm.org/releases/download.html#3.2) and unpack them somewhere (we will refer to that location as `LLVM_SRC`).

Once we have a copy of the LLVM sources, they need to be configured using CMake. We set both, the "Where is the source code" and the "Where to build the binaries" directories to `LLVM_SRC` and click "Configure". We choose a recent version of Visual Studio (tested with `Visual Studio 11`) when prompted.

After a short while, we are presented with a list of build settings. The defaults will work fine. We click "Configure" once more, then click "Generate" afterwards.

Finally, we open `LLVM.sln` in `LLVM_SRC` and set the build configuration to `Release`, then build `ALL_BUILD`.

## Building LLVMSharp

Once we have built LLVM from its sources, we can build LLVMSharp. To do this, we simply need to make sure that Visual Studio can find the LLVM headers and libraries which we do by right-clicking on the project node `LLVMSharp` in the solution explorer, followed by `Properties` in the context menu. 

In the property pages, we navigate to `Configuration Properties` / `VC++ Directories`. We add `LLVM_SRC\include` to `Include Directories` and `LLVM_SRC\lib\Release` to `Library Directories`. The project should now compile.