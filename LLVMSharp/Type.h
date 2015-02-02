
#pragma once

#include "LLVM.h"
#include "Wrapper.h"

namespace LLVM
{
    public ref class Type : Wrapper<llvm::Type*>
	{
	internal:
        Type(llvm::Type* type) : Wrapper(type) {};
	public:
		// implementation specific types
		static Type^ GetVoidType(LLVM::LLVMContext^ context);
		static Type^ GetLabelType(LLVM::LLVMContext^ context);
		static Type^ GetFloatType(LLVM::LLVMContext^ context);
		static Type^ GetDoubleType(LLVM::LLVMContext^ context);
		static Type^ GetMetadataType(LLVM::LLVMContext^ context);

		// x86 types
		static Type^ GetX86FP80Type(LLVM::LLVMContext^ context);
		static Type^ GetX86MMXType(LLVM::LLVMContext^ context);

		// power pc types
		static Type^ GetPPCFP128Type(LLVM::LLVMContext^ context);

		// other implementation specific types
		static Type^ GetFP128Type(LLVM::LLVMContext^ context);

		// general types
		static IntegerType^ GetIntegerType(LLVM::LLVMContext^ context, unsigned bits);
		static IntegerType^ GetInteger1Type(LLVM::LLVMContext^ context);
		static IntegerType^ GetInteger8Type(LLVM::LLVMContext^ context);
		static IntegerType^ GetInteger16Type(LLVM::LLVMContext^ context);
		static IntegerType^ GetInteger32Type(LLVM::LLVMContext^ context);
		static IntegerType^ GetInteger64Type(LLVM::LLVMContext^ context);

		// pointer types
		static PointerType^ GetFloatPointerType(LLVM::LLVMContext^ context);
		static PointerType^ GetFloatPointerType(LLVM::LLVMContext^ context, unsigned address);
		static PointerType^ GetDoublePointerType(LLVM::LLVMContext^ context);
		static PointerType^ GetDoublePointerType(LLVM::LLVMContext^ context, unsigned address);
		static PointerType^ GetInteger8PointerType(LLVM::LLVMContext^ context);
		static PointerType^ GetInteger8PointerType(LLVM::LLVMContext^ context, unsigned address);

		bool CanLosslesslyBitCastTo(Type^ type);
	};
}