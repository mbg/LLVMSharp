
#pragma once

#include "LLVM.h"
#include "Instruction.h"

namespace LLVM
{
	public ref class CallInstruction : Instruction
	{
	public:
		static Instruction^ CreateMalloc(BasicBlock^ block, Type^ t0, Type^ t1, Value^ allocSize, Value^ arraySize, Function^ mallocFunction, String^ name);
		static Instruction^ CreateFree(Value^ pointer, BasicBlock^ block);

		static CallInstruction^ Create(Value^ target, String^ name, BasicBlock^ parent);

		property bool TailCall
		{
			bool get();
			void set(bool value);
		}

		static explicit operator CallInstruction^ (Value^ constant);
		static operator Value^ (CallInstruction^ function);
	internal:
		CallInstruction(llvm::CallInst* instruction) : Instruction(instruction) { };
	};
}