
#include "GlobalValue.h"

LLVM::GlobalValue::GlobalValue(llvm::GlobalValue* globalValue)
{
	this->globalValue = globalValue;
}