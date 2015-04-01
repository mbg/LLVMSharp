#pragma once

#include "LLVM.h"
#include "Type.h"

namespace LLVM
{
    public ref class ArrayType : Type 
    {
    internal:
        ArrayType(llvm::ArrayType* type) : Type(type) {};
    public:
        ArrayType(Type^ elementType, uint64_t numElements);

        property uint64_t ElementCount
        {
            uint64_t get();
        };
    };
}