#include <iostream>
#include <vector>
#include <array>
#include <variant>
#include <type_traits>

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
    const int a;
    const float& f;

    Dummy(const int a, const float& f) : a(a), f(f) { }

    template<typename T, typename U>
    auto operator() (const T& s, U u) {
        using K = typename std::decay_t<T>;
        if constexpr(std::is_same_v<K, int>)
        {
            return 2*s;
        } else
        {
            return s + std::to_string(a) + std::to_string(f);
        }
    }
};

int main()
{
    using namespace std;

    int a = 123;
    float f = 5.55f;

    auto lambda = [a, &f](const auto& s, auto v) {
        using T = typename std::decay_t<decltype(s)>;
        if constexpr(std::is_same_v<T, int>)
        {
            return 2*s;
        } else
        {
            return s + std::to_string(a) + std::to_string(f);
        }
    };

    cout << lambda("furkan", 10) << endl;
    cout << lambda(5, "deneme"s) << endl;

    return 0;
}
