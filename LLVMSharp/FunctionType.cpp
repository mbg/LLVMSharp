
#include "FunctionType.h"
#include "Type.h"
#include <vector>

using namespace LLVM;

static std::vector<llvm::Type*> toVector(array<LLVM::Type^>^ input)
{
    std::vector<llvm::Type*> result;

	for(int i = 0; i < input->Length; i++)
	{
		result.push_back(input[i]->Native);
    }

    return result;
}

FunctionType::FunctionType(LLVM::Type^ returnType)
    : Type(llvm::FunctionType::get(returnType, false))
{
}

FunctionType::FunctionType(LLVM::Type^ returnType, ...array<LLVM::Type^>^ argumentTypes)
    : Type(llvm::FunctionType::get(returnType, toVector(argumentTypes), false))
{
}