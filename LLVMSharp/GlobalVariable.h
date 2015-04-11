
#pragma once

#include "LLVM.h"
#include "Constant.h"

namespace LLVM
{
	/// <summary>
	/// Represents a global variable.
	/// </summary>
    public ref class GlobalVariable : Constant
	{
	public:
		GlobalVariable(Module^ module, LLVM::Type^ type, bool constant, LinkageType linkage, Constant^ value, String^ name);
	};
}