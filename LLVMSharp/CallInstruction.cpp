
#include "CallInstruction.h"
#include "Instruction.h"
#include "BasicBlock.h"
#include "Type.h"
#include "Value.h"
#include "Function.h"

LLVM::Instruction^ LLVM::CallInstruction::CreateMalloc(BasicBlock^ block, Type^ t0, Type^ t1, Value^ allocSize, Value^ arraySize, Function^ mallocFunction, String^ name)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(
		block->GetNativeBlock(),
		t0->GetNativeType(),
		t1->GetNativeType(),
		allocSize->GetNativeValue(),
		arraySize->GetNativeValue(),
		mallocFunction == nullptr ? NULL : mallocFunction->GetNativeFunction(),
		ToUnmanagedString(name)));
}

LLVM::Instruction^ LLVM::CallInstruction::CreateFree(LLVM::Value^ pointer, LLVM::BasicBlock^ block)
{
	return gcnew LLVM::Instruction(llvm::CallInst::CreateFree(
		pointer->GetNativeValue(),
		block->GetNativeBlock()));
}

bool LLVM::CallInstruction::TailCall::get()
{
	return this->instruction->isTailCall();
}

void LLVM::CallInstruction::TailCall::set(bool value)
{
	this->instruction->setTailCall(value);
}

LLVM::CallInstruction::operator LLVM::CallInstruction^(LLVM::Value^ value)
{
	return gcnew LLVM::CallInstruction(llvm::cast<llvm::CallInst>(value->GetNativeValue()));
}

LLVM::CallInstruction::operator LLVM::Value^(LLVM::CallInstruction^ instruction)
{
	return gcnew LLVM::Value(instruction->GetNativeInstruction());
}

llvm::CallInst* LLVM::CallInstruction::GetNativeInstruction()
{
	return this->instruction;
}