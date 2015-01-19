
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class PHINode
	{
	private:
		llvm::PHINode* node;
	public:
		PHINode(Type^ type, unsigned int, String^ name, BasicBlock^ block);

		void AddIncomding(Value^ value, BasicBlock^ block);

		static explicit operator PHINode^ (Value^ value);
		static operator Value^ (PHINode^ node);
	internal:
		PHINode(llvm::PHINode* node) : node(node) { };
		llvm::PHINode* GetNativeNode();
	};
}