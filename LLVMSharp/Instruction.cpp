
#include "Instruction.h"
#include "Value.h"

LLVM::Instruction::operator LLVM::Instruction^(LLVM::Value^ value)
{
	return gcnew LLVM::Instruction(llvm::cast<llvm::Instruction>(value->Native));
}

LLVM::Instruction::operator LLVM::Value^(LLVM::Instruction^ instruction)
{
	return gcnew LLVM::Value(instruction);
}
