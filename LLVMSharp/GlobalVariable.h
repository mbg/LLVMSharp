
#pragma once

#include "LLVM.h"

namespace LLVM
{
	/// <summary>
	/// Represents a global variable.
	/// </summary>
	public ref class GlobalVariable
	{
	private:
		llvm::GlobalVariable* global;
	public:
		GlobalVariable(Module^ module, Type^ type, bool constant, LinkageType linkage, Constant^ value, String^ name);
	};
}