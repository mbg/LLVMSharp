
#include "LoadInstruction.h"
#include "Value.h"

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