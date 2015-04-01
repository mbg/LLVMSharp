#pragma once

#include "LLVM.h"

namespace LLVM
{
    public ref class ConstantExpr abstract sealed
    {
    public:
        static Constant^ GEP(Constant^ c, ...array<Value^>^ indices);
        static Constant^ GEP(Constant^ c, ...array<Constant^>^ indices);
    };
}
