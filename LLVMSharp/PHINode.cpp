
#include "PHINode.h"
#include "Type.h"
#include "Value.h"
#include "BasicBlock.h"

LLVM::PHINode::PHINode(LLVM::Type^ type, unsigned int numReserved, String^ name, LLVM::BasicBlock^ block)
{
	this->node = llvm::PHINode::Create(
		type->GetNativeType(), numReserved,
		ToUnmanagedString(name),
		block);
}

void LLVM::PHINode::AddIncomding(LLVM::Value^ value, LLVM::BasicBlock^ block)
{
	this->node->addIncoming(
		value,
		block);
}

LLVM::PHINode::operator LLVM::PHINode^(LLVM::Value^ value)
{
    return gcnew LLVM::PHINode(llvm::cast<llvm::PHINode>(value->Native));
}

LLVM::PHINode::operator LLVM::Value^(LLVM::PHINode^ node)
{
	return gcnew LLVM::Value(node->GetNativeNode());
}

llvm::PHINode* LLVM::PHINode::GetNativeNode()
{
	return this->node;
}