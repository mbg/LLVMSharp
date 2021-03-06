
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class IntegerType
	{
	private:
		llvm::IntegerType* type;
	public:
		IntegerType(LLVMContext^ context, unsigned bits);

		property unsigned BitWidth
		{
			unsigned get();
		}

		property bool PowerOfTwoByteWidth
		{
			bool get();
		}

		static explicit operator IntegerType^ (Type^ type);
		static operator Type^ (IntegerType^ type);
	internal:
		IntegerType(llvm::IntegerType* type) : type(type) {};
		const llvm::IntegerType* GetNativeType();
	};
}