#include <iostream>
#include <optional>
#include <variant>

#include "VariantVisitor.h"
#include "CustomLiterals.h"

// named aggregate initialization
struct Foo
{
    int integer = 0;
    float realnumber = 1.0f;
    std::string hello;
};

void func()
{
    Foo foo{.realnumber=2.0f, .integer=5};
}




// custom literals

// std::variant and std::visit example

// std::optional
// inline namespaces
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


int main()
{
    using namespace Day8;

    {
        using namespace VariantVisitor;
        exec();
    }

    {
        using namespace CustomLiterals;
        exec();
    }

    return 0;
}
