
#pragma once

#include "LLVM.h"
#include "Type.h"

using namespace System;

namespace LLVM
{
    public ref class FunctionType : Type
	{
	public:
		FunctionType(Type^ returnType);
		FunctionType(Type^ returnType, ...array<Type^>^ argumentTypes);
	};
}