
#include "FunctionType.h"
#include "Type.h"
#include <vector>

LLVM::FunctionType::FunctionType(LLVM::Type^ returnType)
{
	std::vector<const llvm::Type*> types;
	this->type = llvm::FunctionType::get(returnType->GetNativeType(), types, false);
}

LLVM::FunctionType::FunctionType(LLVM::Type^ returnType, ...array<LLVM::Type^>^ argumentTypes)
{
	std::vector<const llvm::Type*> types;

	for(int i = 0; i < argumentTypes->Length; i++)
	{
		types.push_back(argumentTypes[i]->GetNativeType());
	}

	this->type = llvm::FunctionType::get(returnType->GetNativeType(), types, false);
}

llvm::FunctionType* LLVM::FunctionType::GetNativeType()
{
	return this->type;
}