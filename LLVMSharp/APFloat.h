#pragma once

#include "LLVM.h"
#include "Wrapper.h"

namespace LLVM
{
    public ref class APFloat : Wrapper<llvm::APFloat*>
    {
    public:
        APFloat(double d) : Wrapper(new llvm::APFloat(d)) {};
        APFloat(float f) : Wrapper(new llvm::APFloat(f)) {};
    };
}
