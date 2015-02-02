
#include "Constant.h"
#include "LLVMContext.h"
#include "Type.h"
#include "Value.h"

LLVM::Constant::Constant(LLVM::LLVMContext^ context, UInt32 bits, UInt64 value)
{
	this->constant = llvm::ConstantInt::get(
		context,
		llvm::APInt(bits, value));
}

LLVM::Constant::Constant(LLVM::LLVMContext^ context, String^ value)
{
	this->constant = llvm::ConstantDataArray::getString(
		context,
		ToUnmanagedString(value),
		true);
}

LLVM::Constant::Constant(LLVM::LLVMContext^ context, String^ value, bool isNullTerminated)
{
	this->constant = llvm::ConstantDataArray::getString(
		context,
		ToUnmanagedString(value),
		isNullTerminated);
}

LLVM::Constant::Constant(LLVM::Type^ type)
{
	this->constant = llvm::ConstantExpr::getSizeOf(type);
}

LLVM::Type^ LLVM::Constant::GetType()
{
	return gcnew LLVM::Type(this->constant->getType());
}

void LLVM::Constant::TruncOrBitCast(LLVM::Type^ type)
{
	this->constant = llvm::ConstantExpr::getTruncOrBitCast(this->constant, type);
}

LLVM::Constant::operator LLVM::Constant^(LLVM::Value^ value)
{
	return gcnew LLVM::Constant(llvm::cast<llvm::Constant>(value->Native));
}

LLVM::Constant::operator LLVM::Value^(LLVM::Constant^ constant)
{
	return gcnew LLVM::Value(constant->GetNativeConstant());
}

LLVM::Constant::Constant(llvm::Constant* constant)
{
	this->constant = constant;
}

llvm::Constant* LLVM::Constant::GetNativeConstant()
{
	return this->constant;
}