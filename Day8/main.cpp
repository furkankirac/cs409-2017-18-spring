#include <iostream>
#include <optional>
#include <variant>

#include "VariantVisitor.h"
#include "CustomLiterals.h"

// RVO
// noexcept operator and specifier

// std::map
// std::any

// partial template specialization for classes
// template specialization for function templates

// static_cast, dynamic_cast, reinterpret_cast, const_cast
// CRTP

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

struct Huge
{
    int array[10000];
    double dbl[20000];
    // ...

    Huge() { cout << "constructor " << this << endl; }
    ~Huge() { cout << "destructor " << this << endl; }
    Huge(const Huge&)  { cout << "copy constructor " << this << endl; }
};

Huge func(int i)
{
    Huge huge1, huge2;
    if(i > 0)
        return huge1;
    return huge2;
}

int main()
{
    using namespace Day8;

    Huge huge = func(1);
    std::cout << "bla bla" << endl;

//    auto retval = func(0);
//    std::cout << retval.value_or(-1) << std::endl;

//    {
//        using namespace VariantVisitor;
//        run();
//    }

//    {
//        using namespace CustomLiterals;
//        run();
//    }
    return 0;
}
