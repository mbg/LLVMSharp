#pragma once

namespace LLVM
{
    template <typename T>
    public ref class Wrapper
    {
    private:
        T native;
    public:
        Wrapper(T n) : native(n) {};
    internal:
        property T Native {
            T get() { return this->native; };
        };

        operator T() { return this->native; }
    };
}
