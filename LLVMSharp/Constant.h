
#pragma once

#include "LLVM.h"

using namespace System;

namespace LLVM
{
	public ref class Constant
	{
	private:
		llvm::Constant* constant;
	public:
		Constant(LLVMContext^ context, UInt32 bits, UInt64 value);
		Constant(LLVMContext^ context, String^ value);
		Constant(LLVMContext^ context, String^ value, bool isNullTerminated);
		Constant(Type^ type);

		Type^ GetType();

		void TruncOrBitCast(Type^ type);

		static explicit operator Constant^ (Value^ constant);
		static operator Value^ (Constant^ function);
	internal:
		Constant(llvm::Constant* constant);

		llvm::Constant* GetNativeConstant();
	};
}