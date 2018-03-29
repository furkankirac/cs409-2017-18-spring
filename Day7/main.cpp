#include <iostream>
#include <vector>
#include <array>
#include <variant>

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
    std::string s = "furkan";
    int k = -2;
    float f = 3.14f;

    Dummy() : k(5) { }
};

int main()
{
    using namespace std;

//    Dummy d;
//    auto [s, k, f] = d;
//    cout << s << endl;
//    cout << k << endl;
//    cout << f << endl;

    vector<pair<int, double>> v{ {5, 10.01}, {-2, 3.14} };

    for(auto [a, b] : v)
        cout << a << ", " << b << endl;



    return 0;
}
