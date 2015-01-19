
#pragma once

#include "LLVM.h"

#include "Wrapper.h"

namespace LLVM
{
    public ref class Value : Wrapper<llvm::Value*>
	{
	private:
	internal:
		Value(llvm::Value* value) : Wrapper(value) { };
	};
}