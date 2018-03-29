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

    pair<int, float> p{3, 3.14f};
    cout << "First=" << p.first << ", Second=" << p.second << endl;

    tuple<double, std::string, float> t{1.2, "furkan"s, 10.0f};
    auto value = std::get<0>(t);
    auto value2 = std::get<1>(t);
    auto other = std::get<double>(t);

    cout << value << endl;
    cout << value2 << endl;

    return 0;
}
