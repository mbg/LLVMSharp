
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class PointerType
	{
	private:
		const llvm::PointerType* type;
	public:
		static explicit operator PointerType^ (Type^ type);
		static operator Type^ (PointerType^ type);
	internal:
		PointerType(const llvm::PointerType* type) : type(type) { };
		const llvm::PointerType* GetNativeType();
	};
}