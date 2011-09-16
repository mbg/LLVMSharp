
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class Intrinsic
	{
	public:
		static Function^ GetDecleration(Module^ module, IntrinsicType id, ...array<Type^>^ types);
	};
}