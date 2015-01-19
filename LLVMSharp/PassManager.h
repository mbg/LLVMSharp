#pragma once

#include "LLVM.h"
#include "llvm/PassManager.h"

#include "Pass.h"
#include "Module.h"
#include "Function.h"
#include "Wrapper.h"

namespace LLVM
{
    public ref class PassManagerBase : Wrapper<llvm::PassManagerBase*>
    {
    public:
        PassManagerBase(llvm::PassManagerBase* base) : Wrapper(base) {};
        void Add(Pass^ pass);
    };

    public ref class PassManager : PassManagerBase
    {
    public:
        PassManager() : PassManagerBase(new llvm::PassManager()) {};

        bool Run(Module^ module);
    };

    public ref class FunctionPassManager : PassManagerBase
    {
    public: 
        FunctionPassManager(Module^ module) : PassManagerBase(new llvm::FunctionPassManager(module)) {};

        bool Run(Function^ function);
        bool DoInitialization();
        bool DoFinalization();
    };
}
