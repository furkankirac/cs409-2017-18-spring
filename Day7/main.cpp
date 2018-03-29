#include <iostream>
#include <vector>
#include <array>
#include <variant>

// returning by copy list initialization
// structured bindings
// generic lambdas
// std::any
// std::optional
// static_cast, dynamic_cast, reinterpret_cast, const_cast

// template specialization
// inline variables
// returning {}
// std::any
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

struct Dummy
{
    std::string s;
    int k;
};

Dummy func()
{
    return {"furkan", 5};
}


int main()
{
    using namespace std;


    return 0;
}
