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

struct Dummy
{
    union
    {
        int a;
        float f;
        long double d;
    };

    enum Type { Int, Float, LongDouble };
    Type type;
};

int main()
{
    using namespace std;

    Dummy dummy;
    dummy.a = 5;
    dummy.type = Dummy::Type::Int;

    dummy.f = 3.2f;

    cout << dummy.a << endl;

    return 0;
}
