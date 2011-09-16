
#include "Type.h"
#include "LLVMContext.h"
#include "IntegerType.h"
#include "PointerType.h"

LLVM::Type::Type(const llvm::Type* type)
{
	this->type = type;
}

const llvm::Type* LLVM::Type::GetNativeType()
{
	return this->type;
}

LLVM::Type^ LLVM::Type::GetVoidType(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getVoidTy(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetLabelType(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getLabelTy(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetFloatType(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getFloatTy(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetDoubleType(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getDoubleTy(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetMetadataType(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getMetadataTy(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetX86FP80Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getX86_FP80Ty(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetX86MMXType(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getX86_MMXTy(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetPPCFP128Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getPPC_FP128Ty(context->GetNativeContext()));
}

LLVM::Type^ LLVM::Type::GetFP128Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::Type(llvm::Type::getFP128Ty(context->GetNativeContext()));
}

LLVM::IntegerType^ LLVM::Type::GetIntegerType(LLVM::LLVMContext^ context, unsigned bits)
{
	return gcnew LLVM::IntegerType(llvm::Type::getIntNTy(context->GetNativeContext(), bits));
}

LLVM::IntegerType^ LLVM::Type::GetInteger1Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::IntegerType(llvm::Type::getInt1Ty(context->GetNativeContext()));
}

LLVM::IntegerType^ LLVM::Type::GetInteger8Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::IntegerType(llvm::Type::getInt8Ty(context->GetNativeContext()));
}

LLVM::IntegerType^ LLVM::Type::GetInteger16Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::IntegerType(llvm::Type::getInt16Ty(context->GetNativeContext()));
}

LLVM::IntegerType^ LLVM::Type::GetInteger32Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::IntegerType(llvm::Type::getInt32Ty(context->GetNativeContext()));
}

LLVM::IntegerType^ LLVM::Type::GetInteger64Type(LLVM::LLVMContext^ context)
{
	return gcnew LLVM::IntegerType(llvm::Type::getInt64Ty(context->GetNativeContext()));
}

LLVM::PointerType^ LLVM::Type::GetFloatPointerType(LLVM::LLVMContext^ context)
{
	return LLVM::Type::GetFloatPointerType(context, 0);
}

LLVM::PointerType^ LLVM::Type::GetFloatPointerType(LLVM::LLVMContext^ context, unsigned address)
{
	return gcnew LLVM::PointerType(llvm::Type::getFloatPtrTy(context->GetNativeContext(), address));
}

LLVM::PointerType^ LLVM::Type::GetDoublePointerType(LLVM::LLVMContext^ context)
{
	return LLVM::Type::GetDoublePointerType(context, 0);
}

LLVM::PointerType^ LLVM::Type::GetDoublePointerType(LLVM::LLVMContext^ context, unsigned address)
{
	return gcnew LLVM::PointerType(llvm::Type::getDoublePtrTy(context->GetNativeContext(), address));
}

LLVM::PointerType^ LLVM::Type::GetInteger8PointerType(LLVM::LLVMContext^ context)
{
	return LLVM::Type::GetInteger8PointerType(context, 0);
}

LLVM::PointerType^ LLVM::Type::GetInteger8PointerType(LLVM::LLVMContext^ context, unsigned address)
{
	return gcnew LLVM::PointerType(llvm::Type::getInt8PtrTy(context->GetNativeContext(), address));
}

bool LLVM::Type::CanLosslesslyBitCastTo(LLVM::Type^ type)
{
	return this->type->canLosslesslyBitCastTo(type->GetNativeType());
}