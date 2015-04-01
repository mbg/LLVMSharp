#include "ConstantExpr.h"
#include "Value.h"
#include "Constant.h"

using namespace LLVM;

template <class T, class S>
static std::vector<S>* toVector(array<T>^ input)
{
    std::vector<S>* result = new std::vector<S>();

	for(int i = 0; i < input->Length; i++)
	{
		result->push_back(input[i]->Native);
    }

    return result;
}

static std::vector<llvm::Constant*>* toConstantVector(array<Constant^>^ input)
{
    std::vector<llvm::Constant*>* result = new std::vector<llvm::Constant*>();

	for(int i = 0; i < input->Length; i++)
	{
        result->push_back((llvm::Constant*)input[i]->Native);
    }

    return result;
}

Constant^ ConstantExpr::GEP(Constant^ c, ...array<Value^>^ indices)
{
    std::vector<llvm::Value*>* vec = toVector<Value^, llvm::Value*>(indices);
    llvm::ArrayRef<llvm::Value*> arr = makeArrayRef(*vec);

    return gcnew Constant(
        llvm::ConstantExpr::getGetElementPtr((llvm::Constant*)c->Native, arr));
}

Constant^ ConstantExpr::GEP(Constant^ c, ...array<Constant^>^ indices)
{
    std::vector<llvm::Constant*>* vec = toConstantVector(indices);
    llvm::ArrayRef<llvm::Constant*> arr = makeArrayRef(*vec);

    //delete vec;

    return gcnew Constant(
        llvm::ConstantExpr::getGetElementPtr((llvm::Constant*)c->Native, arr));
}