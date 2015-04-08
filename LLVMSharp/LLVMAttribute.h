#pragma once

#include "LLVM.h"
#include "llvm/Attributes.h"

#include "Wrapper.h"

namespace LLVM
{
    public ref class Attributes : Wrapper<llvm::Attributes*>
    {
    internal:
        Attributes(llvm::Attributes* attr) : Wrapper(attr) {};
    };
}
