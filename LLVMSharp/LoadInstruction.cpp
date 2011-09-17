
#include "LoadInstruction.h"
#include "Value.h"
#include "BasicBlock.h"

LLVM::LoadInstruction::LoadInstruction(LLVM::Value^ value, String^ name, LLVM::BasicBlock^ parent)
{
	this->instruction = new llvm::LoadInst(
		value->GetNativeValue(),
		ToUnmanagedString(name),
		parent->GetNativeBlock());
}

LLVM::LoadInstruction::operator LLVM::LoadInstruction^(LLVM::Value^ value)
{
	return gcnew LLVM::LoadInstruction(llvm::cast<llvm::LoadInst>(value->GetNativeValue()));
}

LLVM::LoadInstruction::operator LLVM::Value^(LLVM::LoadInstruction^ instruction)
{
	return gcnew LLVM::Value(instruction->GetNativeInstruction());
}

llvm::LoadInst* LLVM::LoadInstruction::GetNativeInstruction()
{
	return this->instruction;
}