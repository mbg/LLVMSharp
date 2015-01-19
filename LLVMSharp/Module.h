#pragma once

#include "LLVM.h"

#include "Wrapper.h"

using namespace System;

namespace LLVM
{
    public ref class Module : Wrapper<llvm::Module*>
	{
	private:
	public:
		Module(LLVMContext^ context, String^ name);

		Constant^ GetOrInsertFunction(String^ name, FunctionType^ signature);

		void WriteToFile(String^ filename);
		void Dump();
	};
}