
#pragma once

#include "LLVM.h"

using namespace System;

namespace LLVM
{
	public ref class IRBuilder
	{
	private:
		llvm::IRBuilder<>* builder;
	public:
		IRBuilder(BasicBlock^ block);

		BasicBlock^ GetInsertBlock();
		void SetInsertPoint(BasicBlock^ block);

		LoadInstruction^ CreateLoad(Value^ pointer, String^ name);
		void CreateStore(Value^ value, Value^ pointer);
		Value^ CreateAdd(Value^ leftValue, Value^ rightValue, String^ name);
		Value^ CreateGEP(Value^ pointer, Value^ index, String^ name);
		Value^ CreateTrunc(Value^ value, Type^ type, String^ name);
		Value^ CreateSignExtend(Value^ value, Type^ type, String^ name);
		void CreateBranch(BasicBlock^ target);
		void CreateCall(Value^ target);
		CallInstruction^ CreateCall(Value^ target, String^ name);
		CallInstruction^ CreateCall(Value^ target, ...array<Value^>^ arguments);
		PHINode^ CreatePHI(Type^ type, unsigned int, String^ name);
	};
}