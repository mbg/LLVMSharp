
#include "BranchInstruction.h"
#include "BasicBlock.h"
#include "Value.h"

LLVM::BranchInstruction^ LLVM::BranchInstruction::Create(
	LLVM::BasicBlock^ ifTrue, LLVM::BasicBlock^ ifFalse, LLVM::Value^ value, LLVM::BasicBlock^ parent)
{
	return gcnew LLVM::BranchInstruction(llvm::BranchInst::Create(
		ifTrue->GetNativeBlock(),
		ifFalse->GetNativeBlock(),
		value->GetNativeValue(),
		parent->GetNativeBlock()));
}