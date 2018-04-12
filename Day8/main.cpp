#include <iostream>
#include <optional>
#include <variant>

#include "VariantVisitor.h"
#include "CustomLiterals.h"

// std::optional
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

std::optional<int> func(int i)
{
    if(i > 0)
        return i+1;

    return {};
}


int main()
{
    using namespace Day8;

    // std::optional
    auto retval = func(0);
    std::cout << retval.value_or(-1) << std::endl;


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
