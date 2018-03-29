#include <iostream>
#include <vector>
#include <array>
#include <variant>

// clang code-model

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

struct Vec
{
    std::vector<int> v;

    Vec(int value) : v{value} { }
    Vec(std::initializer_list<int> l) : v{l} { }
};

int main()
{
    using namespace std;

    Vec a{3, 4, 5, 6};

    for(auto& value : a.v)
        cout << value << endl;

    return 0;
}
