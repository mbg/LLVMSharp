
#include "LLVMContext.h"

using namespace LLVM;

LLVMContext::~LLVMContext()
{
	//llvm::llvm_shutdown();
}

void LLVMContext::RegisterPass(Pass^ pass, String^ name, String^ arg)
{
    throw gcnew NotImplementedException("Not yet implemented...");
}