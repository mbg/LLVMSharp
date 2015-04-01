#include "ArrayType.h"

using namespace LLVM;

ArrayType::ArrayType(Type^ elementType, uint64_t numElements)
    : Type(llvm::ArrayType::get(elementType, numElements))
{
}

uint64_t ArrayType::ElementCount::get()
{
    llvm::ArrayType* type = (llvm::ArrayType*)this->Native;
    return type->getNumElements();
}