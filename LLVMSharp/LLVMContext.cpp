
#include "LLVMContext.h"

LLVM::LLVMContext::~LLVMContext()
{
	//llvm::llvm_shutdown();
}

llvm::LLVMContext& LLVM::LLVMContext::GetNativeContext()
{
	return this->context;
}