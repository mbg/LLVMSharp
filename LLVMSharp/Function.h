
#pragma once

#include "llvm/Support/IRBuilder.h"
#include "LinkageType.h"
#include "FunctionType.h"
#include "Module.h"

using namespace System;

namespace LLVM
{
	public ref class Function
	{
	private:
		llvm::Function* function;
		void Initialise(Module^ module, String^ name, FunctionType^ type, LinkageType linkage);
	public:
		Function(Module^ module, String^ name, FunctionType^ type);
		Function(Module^ module, String^ name, FunctionType^ type, LinkageType linkage);

		property bool Empty
		{
			bool get();
		}

		void SetArgumentName(unsigned index, String^ name);

		static explicit operator Function^ (Constant^ constant);
		static operator Constant^ (Function^ function);

		static operator Value^ (Function^ function);
	internal:
		Function(llvm::Function* function);

		llvm::Function* GetNativeFunction();
	};
}