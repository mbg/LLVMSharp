
#include "PointerType.h"
#include "Type.h"

LLVM::PointerType::operator LLVM::PointerType^(LLVM::Type^ type)
{
	return gcnew LLVM::PointerType(llvm::cast<llvm::PointerType>(type->GetNativeType()));
}

LLVM::PointerType::operator LLVM::Type^(LLVM::PointerType^ type)
{
	return gcnew LLVM::Type(type->type);
}

const llvm::PointerType* LLVM::PointerType::GetNativeType()
{
	return this->type;
}