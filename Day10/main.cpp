#include <iostream>

// template auto parameters

// array types with constant size

// compile time integral numbers

// std::map, std::any
// static_cast, dynamic_cast, reinterpret_cast, const_cast
// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

template<auto u>
struct cint
{
    using U = decltype(u);
    using value_type = U;
    static constexpr value_type value = u;

    template<auto v>
    auto operator +(cint<v>)
    {
        return cint<u+v>{};
    }

    template<auto v>
    bool operator ==(cint<v>)
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
            parse<sizeof...(CHARS)>({ CHARS... })
            >{}
            ;
}

int main()
{
    auto A = cint<10>{};
    return (123_c + 1110_c).value;
}
