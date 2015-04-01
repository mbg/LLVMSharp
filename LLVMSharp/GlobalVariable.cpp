
#include "GlobalVariable.h"
#include "Module.h"
#include "Type.h"
#include "Constant.h"

LLVM::GlobalVariable::GlobalVariable(
	LLVM::Module^ module, LLVM::Type^ type, bool constant, LLVM::LinkageType linkage, LLVM::Constant^ value, String^ name)
    : LLVM::Constant(new llvm::GlobalVariable(
        *(module->Native),
		type,
		constant,
		(llvm::GlobalValue::LinkageTypes)linkage,
        (llvm::Constant*)value->Native,
		ToUnmanagedString(name)))
{
}