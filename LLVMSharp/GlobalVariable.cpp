
#include "GlobalVariable.h"
#include "Module.h"
#include "Type.h"
#include "Constant.h"

LLVM::GlobalVariable::GlobalVariable(
	LLVM::Module^ module, LLVM::Type^ type, bool constant, LLVM::LinkageType linkage, LLVM::Constant^ value, String^ name)
{
	this->global = new llvm::GlobalVariable(
        *(module->Native),
		type->GetNativeType(),
		constant,
		(llvm::GlobalValue::LinkageTypes)linkage,
		value->GetNativeConstant(),
		ToUnmanagedString(name));
}