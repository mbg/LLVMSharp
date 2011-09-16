#pragma once

#include "llvm/LLVMContext.h"

namespace LLVM 
{
	public ref class LLVMContext 
	{
	private:
		llvm::LLVMContext &context;
	public:
		LLVMContext() : context(llvm::getGlobalContext()) { };
		~LLVMContext();
	internal:
		llvm::LLVMContext& GetNativeContext();
	};
}