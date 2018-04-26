#include <stdlib.h>
#include <cmath>

#define ADD_UNARY_OPERATOR(op) \
    template<auto v> \
    bool operator op(cint<v>) { return u op v; }

#define ADD_BINARY_OPERATOR(op) \
    template<auto v> \
    auto operator op(cint<v>) { return cint<u op v>{}; }

template<auto u>
struct cint
{
    using U = decltype(u);
    using value_type = U;
    static constexpr value_type value = u;

    ADD_BINARY_OPERATOR(+)
    ADD_BINARY_OPERATOR(-)
    ADD_BINARY_OPERATOR(*)

    ADD_UNARY_OPERATOR(==)
    ADD_UNARY_OPERATOR(!=)

    // below is the casting operator defined for all possible types.
    // this allows to assign a cint<...> to an "int", "long" kind of standard variable easily (without writing .value at the end)
    template<typename T>
    operator T() { return (T)value; }

    // below sqrt function does nothing right now
    // you could implement a compile time function that can take square-roots
    // remember that std::sqrt is not compile-time compatible, it's only for run-time
    // this function gets called when sqrt is used with cint type through ADL (arg. dep. lookup)
    friend constexpr auto sqrt(cint<u> /*param_name_not_required*/)
    {
        return cint<u>{};
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

template <char... chars>
auto operator "" _c()
{
    return cint<
            parse<sizeof...(chars)>({ chars... })
            >{};
}

// below distance function works both in run-time and compile-time now!
// we used a good trick for the sqrt function below to make it work both for compile-time and run-time.
template<typename P1, typename P2>
constexpr auto distance(P1 p1, P2 p2)
{
    auto xs = p1.x - p2.x;
    auto ys = p1.y - p2.y;

    using namespace std; // std namespace is imported and we have runtime compatible std::sqrt implementations there
    // we don't directly write std::sqrt (qualified function call) below to allow ADL (argument dependent lookup)
    // if the argument of sqrt below is cint type, ADL will look for sqrt in cint
    // otherwise it will use std::sqrt since it is imported
    return sqrt(xs*xs + ys*ys); // sqrt needs to be used in an unqualified fashion for ADL to work
}

// a generic point implementation that can work both with standard run-tiem types and compile-time types
template<typename T1, typename T2>
struct Point { T1 x; T2 y; };

// a function that creates a Point struct.
// we use a function because function template parameters can be auto deduced, which is easier to use.
template<typename T1, typename T2>
auto point(T1 x, T2 y) { return Point<T1, T2>{x, y}; }

int main()
{
#if 1 // change this to 0 for run-time version
    auto p1 = point(3_c, 5_c); // call point function, which auto-deduces the types
    auto p2 = point(7_c, 2_c); // here we deduce cint<7> and cint<2>
    auto d = distance(p1, p2);
    return d; // here d is cint<...> and return type of main function is int. (int) cast is automatically called.
#else
    auto p1 = point(3, 5); // call point function, which auto-deduces the types
    auto p2 = point(7, 2); // here we deduce int and int
    auto d = distance(p1, p2); // here d is already int, no casting to return type is required
    return d;
#endif
}
