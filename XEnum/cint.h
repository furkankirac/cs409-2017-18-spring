#ifndef CINT_H
#define CINT_H

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
    operator T() { return static_cast<T>(value); }
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

#endif // CINT_H
