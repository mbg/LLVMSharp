
#include "PHINode.h"
#include "Type.h"
#include "Value.h"
#include "BasicBlock.h"

LLVM::PHINode::PHINode(LLVM::Type^ type, String^ name, LLVM::BasicBlock^ block)
{
	this->node = llvm::PHINode::Create(
		type->GetNativeType(),
		ToUnmanagedString(name),
		block->GetNativeBlock());
}

void LLVM::PHINode::ReserveOperandSpace(unsigned int values)
{
	this->node->reserveOperandSpace(values);
}

void LLVM::PHINode::AddIncomding(LLVM::Value^ value, LLVM::BasicBlock^ block)
{
	this->node->addIncoming(
		value->GetNativeValue(),
		block->GetNativeBlock());
}

LLVM::PHINode::operator LLVM::PHINode^(LLVM::Value^ value)
{
	return gcnew LLVM::PHINode(llvm::cast<llvm::PHINode>(value->GetNativeValue()));
}

LLVM::PHINode::operator LLVM::Value^(LLVM::PHINode^ node)
{
	return gcnew LLVM::Value(node->GetNativeNode());
}

llvm::PHINode* LLVM::PHINode::GetNativeNode()
{
	return this->node;
}