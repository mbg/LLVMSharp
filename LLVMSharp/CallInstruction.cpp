
#include "CallInstruction.h"
#include "Instruction.h"
#include "BasicBlock.h"
#include "Type.h"
#include "Value.h"
#include "Function.h"

LLVM::Instruction^ LLVM::CallInstruction::CreateMalloc(BasicBlock^ block, Type^ t0, Type^ t1, Value^ allocSize, Value^ arraySize, String^ name)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(
		block,
		t0->GetNativeType(),
		t1->GetNativeType(),
		allocSize,
		arraySize,
        0,
		ToUnmanagedString(name)));
}

LLVM::Instruction^ LLVM::CallInstruction::CreateMalloc(BasicBlock^ block, Type^ t0, Type^ t1, Value^ allocSize, Value^ arraySize, Function^ mallocFunction, String^ name)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(
		block,
		t0->GetNativeType(),
		t1->GetNativeType(),
		allocSize,
		arraySize,
        mallocFunction,
		ToUnmanagedString(name)));
}

LLVM::Instruction^ LLVM::CallInstruction::CreateFree(LLVM::Value^ pointer, LLVM::BasicBlock^ block)
{
	return gcnew LLVM::Instruction(llvm::CallInst::CreateFree(
		pointer,
		block));
}

LLVM::CallInstruction^ LLVM::CallInstruction::Create(LLVM::Value^ target, String^ name, LLVM::BasicBlock^ parent)
{
	return gcnew LLVM::CallInstruction(llvm::CallInst::Create(
		target,
		ToUnmanagedString(name),
		parent));
}

bool LLVM::CallInstruction::TailCall::get()
{
    llvm::CallInst* inst = (llvm::CallInst*)this->Native;
	return inst->isTailCall();
}

void LLVM::CallInstruction::TailCall::set(bool value)
{
    llvm::CallInst* inst = (llvm::CallInst*)this->Native;
	inst->setTailCall(value);
}

LLVM::CallInstruction::operator LLVM::CallInstruction^(LLVM::Value^ value)
{
    return gcnew LLVM::CallInstruction(llvm::cast<llvm::CallInst>(value->Native));
}

LLVM::CallInstruction::operator LLVM::Value^(LLVM::CallInstruction^ instruction)
{
	return gcnew LLVM::Value(instruction);
}