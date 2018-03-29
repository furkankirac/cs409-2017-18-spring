#include <iostream>
#include <vector>
#include <array>
#include <variant>

// std::array, std::pair, std::tuple
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


int main()
{
    using namespace std;

    std::variant<int, float, long double, std::string> dummy;
    dummy = 5;
    dummy = 5.3f;
    dummy = 10.0l;
    dummy = "furkan";

    try
    {
        auto value = std::get<int>(dummy);
    }
    catch(const std::bad_variant_access& e)
    {
        cout << "Error" << endl;
    }

    return 0;
}
