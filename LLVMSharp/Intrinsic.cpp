
#include "Intrinsic.h"
#include "Module.h"
#include "Type.h"
#include "Function.h"

LLVM::Function^ LLVM::Intrinsic::GetDecleration(
	LLVM::Module^ module, LLVM::IntrinsicType id, ...array<LLVM::Type^>^ types)
{
	llvm::Type** argtypes = new llvm::Type*[types->Length];

	for(int i = 0; i < types.Length; i++)
	{
		argtypes[i] = types[i];
	}

	llvm::Function* function = llvm::Intrinsic::getDeclaration(
		module,
		(llvm::Intrinsic::ID)id,
        makeArrayRef(
		    argtypes,
		    types->Length));

	return gcnew LLVM::Function(function);
}