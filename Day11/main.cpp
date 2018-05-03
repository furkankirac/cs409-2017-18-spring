#include <iostream>
#include <variant>
#include <vector>
//#include <numeric>
//#include <algorithm>

using namespace std;

// std::accumulate
// std::remove, std::remove_if

// std::common_type_t
// std::gcd, lcm
// std::stoi, stol, stof
// std::add_cv, std::add_const, std::add_volatile
// std::clamp

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

namespace std
{
    inline namespace __1
    {
        template<typename T>
        pair(T, const char*) -> pair<T, string>;
    }
}

template<typename ...Ts> struct Lambdas : public Ts... { using Ts::operator()...; };
template<class... Ts> Lambdas(Ts...) -> Lambdas<Ts...>;

int main()
{
    using namespace std;

    auto p = pair(10.0, "furkan");
//    TD<decltype(p)> inst;

    variant<int, float, string> key;
    key = 5.0f;

    visit([](auto&& v) {
        using T = decay_t<decltype(v)>;
        if constexpr(is_same_v<T, int>)
            cout << "integer" << endl;
        else if constexpr(is_same_v<T, float>)
            cout << "float" << endl;
        else if constexpr(is_same_v<T, string>)
            cout << "string" << endl;
    }, key);

    visit(Lambdas{
              [](int v) { cout << "integer" << endl; },
              [](float v) { cout << "float" << endl; },
              [](string v) { cout << "string" << endl; }
          }, key);


    return 0;
}





