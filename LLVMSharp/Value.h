
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class Value
	{
	private:
		llvm::Value* value;
	internal:
		Value(llvm::Value* value) : value(value) { };
		llvm::Value* GetNativeValue();
	};
}