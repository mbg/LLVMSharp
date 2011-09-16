
#include "Instruction.h"
#include "Value.h"

LLVM::Instruction::operator LLVM::Instruction^(LLVM::Value^ value)
{
	return gcnew LLVM::Instruction(llvm::cast<llvm::Instruction>(value->GetNativeValue()));
}

LLVM::Instruction::operator LLVM::Value^(LLVM::Instruction^ instruction)
{
	return gcnew LLVM::Value(instruction->GetNativeInstruction());
}

llvm::Instruction* LLVM::Instruction::GetNativeInstruction()
{
	return this->instruction;
}