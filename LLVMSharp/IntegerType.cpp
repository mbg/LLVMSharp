
#include "IntegerType.h"
#include "LLVMContext.h"
#include "Type.h"

LLVM::IntegerType::IntegerType(LLVM::LLVMContext^ context, unsigned bits)
{
	this->type = llvm::IntegerType::get(
		context,
		bits);
}

unsigned LLVM::IntegerType::BitWidth::get()
{
	return this->type->getBitWidth();
}

bool LLVM::IntegerType::PowerOfTwoByteWidth::get()
{
	return this->type->isPowerOf2ByteWidth();
}

LLVM::IntegerType::operator LLVM::IntegerType^(LLVM::Type^ type)
{
	return gcnew LLVM::IntegerType(llvm::cast<llvm::IntegerType>(type->GetNativeType()));
}

LLVM::IntegerType::operator LLVM::Type^(LLVM::IntegerType^ type)
{
	return gcnew LLVM::Type(type->type);
}

const llvm::IntegerType* LLVM::IntegerType::GetNativeType()
{
	return this->type;
}