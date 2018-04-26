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

#define CINT(type, value) cint<type, value>{}

int main()
{
    auto S = "furkan"s;

//    A::value ---> 5;
//    A::value_type ---> int

    auto A = CINT(int, 10);
    auto B = cint<long int, 10>{};
    auto C = A + B;
    bool x = A == B;
//    cout << (x ? "true" : "false") << endl;

//    decltype(C) --> cint<long int, 15>

    return C.value;
}
