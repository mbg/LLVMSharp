
#include "PointerType.h"
#include "Type.h"

LLVM::PointerType^ LLVM::PointerType::Get(LLVM::Type^ type, unsigned addressSpace)
{
	return gcnew LLVM::PointerType(llvm::PointerType::get(
		type->GetNativeType(), addressSpace));
}

LLVM::PointerType^ LLVM::PointerType::GetUnqualified(LLVM::Type^ type)
{
	return LLVM::PointerType::Get(type, 0);
}

LLVM::PointerType::operator LLVM::PointerType^(LLVM::Type^ type)
{
	return gcnew LLVM::PointerType(llvm::cast<llvm::PointerType>(type->GetNativeType()));
}

LLVM::PointerType::operator LLVM::Type^(LLVM::PointerType^ type)
{
	return gcnew LLVM::Type(type->type);
}

llvm::PointerType* LLVM::PointerType::GetNativeType()
{
	return this->type;
}