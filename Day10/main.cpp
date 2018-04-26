#include <iostream>

// SFINAE, enable_if

// template auto parameters

// array types with constant size

// compile time integral numbers

// std::map, std::any
// static_cast, dynamic_cast, reinterpret_cast, const_cast
// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

template<typename U, U u>
struct cint
{
    using value_type = U;
    static constexpr value_type value = u;

    template<typename V, V v>
    auto operator +(cint<V, v>)
    {
        return cint<decltype(u+v), u+v>{};
    }

    template<typename V, V v>
    bool operator ==(cint<V, v>)
    {
        return u == v;
    }

};


template<int N>
constexpr int parse(const char (&array)[N])
{
    int multiplier = 1;
    int value = 0;
    for(auto i = N-1; i>=0; --i)
    {
        value += multiplier * (array[i] - '0');
        multiplier *= 10;
    }

    return value;
}


template <char... CHARS>
auto operator "" _c()
{
    return cint<
            int,
            parse<sizeof...(CHARS)>({ CHARS... })
            >{}
            ;
}

int main()
{
    return (123_c + 1110_c).value;
}
