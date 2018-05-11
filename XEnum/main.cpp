#include <iostream>
#include <tuple>

#include "Enum.h"

template<auto u>
using cint = typename std::integral_constant<decltype(u), u>;

enum class ColorTypeDef { Red, Green, Blue, Orange };

template<typename TUPLE>
struct ColorType
{
    const TUPLE info;

    ColorTypeDef value;

    ColorType(const TUPLE info) : info(info) { }

    template<typename ENUMTYPE, size_t i = 0>
    constexpr inline EnumInfo infoOf(TUPLE t)
    {
        const auto sz = std::tuple_size_v<TUPLE>;
        if constexpr(std::is_same_v<ENUMTYPE, std::tuple_element_t<i, TUPLE>>)
            return { std::get<i+1>(t), std::get<i+2>(t) };
        else if constexpr(i < sz-1)
            return infoOf<ENUMTYPE, i+1>(t);
        else
            return {"", ""};
    }

    template<typename ENUMTYPE>
    constexpr inline auto infoOf() { return infoOf<ENUMTYPE>(info); }
};

int main()
{
    using namespace std;

    ColorType ct{make_tuple(
                    cint<ColorTypeDef::Red>{}, "Red", "R",
                    cint<ColorTypeDef::Green>{}, "Green", "G",
                    cint<ColorTypeDef::Blue>{}, "Blue", "B"
                    )};
    cout << ct.infoOf<cint<ColorTypeDef::Green>>().fullname << endl;
//    cout << ct.infoBlock<cint<ColorTypeDef::Green>>().shortname << endl;
    return string(ct.infoOf<cint<ColorTypeDef::Green>>().shortname).size();
//    return 0;
}
