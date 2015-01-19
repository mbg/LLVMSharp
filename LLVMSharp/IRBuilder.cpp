
#include "IRBuilder.h"
#include "BasicBlock.h"
#include "Value.h"
#include "Type.h"
#include "LoadInstruction.h"
#include "CallInstruction.h"
#include "PHINode.h"

LLVM::IRBuilder::IRBuilder(LLVM::BasicBlock^ block)
{
	this->builder = new llvm::IRBuilder<>(block);
}

LLVM::BasicBlock^ LLVM::IRBuilder::GetInsertBlock()
{
	return gcnew LLVM::BasicBlock(this->builder->GetInsertBlock());
}

void LLVM::IRBuilder::SetInsertPoint(LLVM::BasicBlock^ block)
{
	this->builder->SetInsertPoint(block);
}

LLVM::LoadInstruction^ LLVM::IRBuilder::CreateLoad(LLVM::Value^ pointer, String^ name)
{
	return gcnew LLVM::LoadInstruction(this->builder->CreateLoad(
		pointer,
		ToUnmanagedString(name)));
}

void LLVM::IRBuilder::CreateStore(LLVM::Value^ value, LLVM::Value^ pointer)
{
	this->builder->CreateStore(
		value,
		pointer);
}

LLVM::Value^ LLVM::IRBuilder::CreateAdd(LLVM::Value^ leftValue, LLVM::Value^ rightValue, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateAdd(
		leftValue,
		rightValue,
		ToUnmanagedString(name)));
}

LLVM::Value^ LLVM::IRBuilder::CreateGEP(LLVM::Value^ pointer, LLVM::Value^ index, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateGEP(
		pointer,
		index,
		ToUnmanagedString(name)));
}

LLVM::Value^ LLVM::IRBuilder::CreateTrunc(LLVM::Value^ value, LLVM::Type^ type, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateTrunc(
		value,
		type->GetNativeType(),
		ToUnmanagedString(name)));
}

LLVM::Value^ LLVM::IRBuilder::CreateSignExtend(LLVM::Value^ value, LLVM::Type^ type, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateSExt(
		value,
		type->GetNativeType(),
		ToUnmanagedString(name)));
}

void LLVM::IRBuilder::CreateBranch(LLVM::BasicBlock^ target)
{
	this->builder->CreateBr(target);
}

void LLVM::IRBuilder::CreateCall(LLVM::Value^ target)
{
	this->builder->CreateCall(
		target,
		"");
}

LLVM::CallInstruction^ LLVM::IRBuilder::CreateCall(LLVM::Value^ target, String^ name)
{
	return gcnew LLVM::CallInstruction(this->builder->CreateCall(
		target,
		ToUnmanagedString(name)));
}

LLVM::CallInstruction^ LLVM::IRBuilder::CreateCall(LLVM::Value^ target, ...array<LLVM::Value^>^ arguments)
{
	llvm::Value** args = new llvm::Value*[arguments->Length];

	for(int i=0; i < arguments->Length; i++)
	{
		args[i] = arguments[i];
	}

	return gcnew LLVM::CallInstruction(this->builder->CreateCall(
		target,
        makeArrayRef(
		args,
		args + arguments->Length)));
}

LLVM::PHINode^ LLVM::IRBuilder::CreatePHI(LLVM::Type^ type, unsigned int numReserved, String^ name)
{
	return gcnew LLVM::PHINode(this->builder->CreatePHI(
		type->GetNativeType(), numReserved,
		ToUnmanagedString(name)));
}