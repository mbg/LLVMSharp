#pragma once

#include "LLVM.h"
#include "Constant.h"
#include "APFloat.h"

namespace LLVM
{
    public ref class ConstantFP : Constant
    {
    public:
        static ConstantFP^ Get(LLVMContext^ context, APFloat^ f);

        property bool IsZero
        {
            bool get();
        };

        property bool IsNegative
        {
            bool get();
        };

        property bool IsNaN
        {
            bool get();
        };

        bool IsExactlyValue(double value);
    internal:
        ConstantFP(llvm::ConstantFP* base) : Constant(base) {};
    };
}