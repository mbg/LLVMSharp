#include "ConstantFP.h"
#include "LLVMContext.h"

using namespace LLVM;

ConstantFP^ ConstantFP::Get(LLVMContext^ context, APFloat^ f)
{
    const llvm::APFloat& V = *(f->Native);

    return gcnew ConstantFP(
        llvm::ConstantFP::get(context->Native, V));
}

bool ConstantFP::IsNaN::get() 
{
    llvm::ConstantFP* fp = (llvm::ConstantFP*)this->Native;
    return fp->isNaN();
}

bool ConstantFP::IsNegative::get() 
{
    llvm::ConstantFP* fp = (llvm::ConstantFP*)this->Native;
    return fp->isNegative();
}

bool ConstantFP::IsZero::get() 
{
    llvm::ConstantFP* fp = (llvm::ConstantFP*)this->Native;
    return fp->isZero();
}

bool ConstantFP::IsExactlyValue(double value)
{
    llvm::ConstantFP* fp = (llvm::ConstantFP*)this->Native;
    return fp->isExactlyValue(value);
}