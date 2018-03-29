#include <iostream>
#include <vector>
#include <array>
#include <variant>

// clang code-model

// init-statement for if/switch

// initializer lists
// std::array, std::pair, std::tuple
// returning by copy list initialization
// structured bindings
// generic lambdas
// union, std::variant
// std::any
// std::optional
// static_cast, dynamic_cast, reinterpret_cast, const_cast

// template specialization
// inline variables
// returning {}
// std::any
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

int main()
{
    using namespace std;

    auto longJob = [] {
        // ... execute some long jobs
        return 15;
    };

    if(auto value = longJob(); value > 10)
    {
        // do some other things
        float k = value * 10;
        // do other things with k
    }

    return 0;
}
