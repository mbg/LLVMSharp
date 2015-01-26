#pragma once

#include "llvm/LLVMContext.h"

#include "Pass.h"
#include "Wrapper.h"

namespace LLVM 
{
    public ref class LLVMContext : Wrapper<llvm::LLVMContext&>
	{
	public:
        LLVMContext() : Wrapper(llvm::getGlobalContext()) {};
		~LLVMContext();

        void RegisterPass(Pass^ pass, String^ name, String^ arg);
	};
}