
#include "Value.h"

using namespace LLVM;

String^ Value::Name::get()
{
    return ToManagedString(this->Native->getName().data());
}

void Value::Name::set(String^ name)
{
    this->Native->setName(ToUnmanagedString(name));
}

void Value::Dump()
{
    this->Native->dump();
}