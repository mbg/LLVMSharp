
#pragma once

#include "LLVM.h"

using namespace System;

namespace LLVM
{
	public ref class FunctionType
	{
	private:
		llvm::FunctionType* type;
	public:
		FunctionType(Type^ returnType);
		FunctionType(Type^ returnType, ...array<Type^>^ argumentTypes);
	internal:
		llvm::FunctionType* GetNativeType();
	};
}