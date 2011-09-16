#pragma once

#include "LLVM.h"

using namespace System;

namespace LLVM
{
	public ref class Module 
	{
	private:
		llvm::Module* module;
	public:
		Module(LLVMContext^ context, String^ name);

		Constant^ GetOrInsertFunction(String^ name, FunctionType^ signature);

		void Dump();
	internal:
		llvm::Module* GetNativeModule();
	};
}