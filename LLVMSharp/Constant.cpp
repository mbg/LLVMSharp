
#include "Constant.h"
#include "LLVMContext.h"
#include "Type.h"
#include "Value.h"

LLVM::Constant::Constant(LLVM::LLVMContext^ context, UInt32 bits, UInt64 value)
    : Value(llvm::ConstantInt::get(context, llvm::APInt(bits, value)))
{
}

LLVM::Constant::Constant(LLVM::LLVMContext^ context, String^ value)
    : Value(llvm::ConstantDataArray::getString(context,
		ToUnmanagedString(value),
		true))
{
}

LLVM::Constant::Constant(LLVM::LLVMContext^ context, String^ value, bool isNullTerminated)
    : Value(llvm::ConstantDataArray::getString(
		context,
		ToUnmanagedString(value),
		isNullTerminated))
{
}

LLVM::Constant::Constant(LLVM::Type^ type)
    : Value(llvm::ConstantExpr::getSizeOf(type))
{
}

LLVM::Type^ LLVM::Constant::GetType()
{
	return gcnew LLVM::Type(this->Native->getType());
}

LLVM::Constant^ LLVM::Constant::TruncOrBitCast(LLVM::Type^ type)
{
    return gcnew LLVM::Constant(llvm::ConstantExpr::getTruncOrBitCast((llvm::Constant*)this->Native, type));
}

LLVM::Constant::operator LLVM::Constant^(LLVM::Value^ value)
{
	return gcnew LLVM::Constant(llvm::cast<llvm::Constant>(value->Native));
}

LLVM::Constant::operator LLVM::Value^(LLVM::Constant^ constant)
{
	return gcnew LLVM::Value(constant);
}

LLVM::Constant::Constant(llvm::Constant* constant)
    : Value(constant)
{
}