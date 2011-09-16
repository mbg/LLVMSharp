
#pragma once

#include "llvm/GlobalValue.h"

namespace LLVM
{
	public ref class GlobalValue
	{
	private:
		llvm::GlobalValue* globalValue;
	internal:
		GlobalValue(llvm::GlobalValue* globalValue);
	};
}