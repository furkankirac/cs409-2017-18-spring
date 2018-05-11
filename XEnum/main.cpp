#include <iostream>
#include <string>
#include <numeric>
#include <vector>

#include "Enum.h"
#include "Monad.h"
#include "cint.h"

enum class ColorTypeDef { Red, Green, Blue };

template<typename INFOFUNC>
struct ColorType
{
    const INFOFUNC info;

    ColorTypeDef value;

    ColorType(INFOFUNC info) : info(info) { }

    template<typename ENUMTYPE, typename ENUMINFOLIST>
    constexpr inline EnumInfo infoOf(ENUMINFOLIST L)
    {
        if(length(L) == 0)
            return {};
        if constexpr(!std::is_same_v<ENUMTYPE, decltype(head_element(L))>)
            return infoOf<ENUMTYPE>(tail(L));
        else
            return { head_element(tail(L)), head_element(tail(tail(L))) };
    }

    template<typename ENUMTYPE>
    constexpr inline auto infoOf() { return infoOf<ENUMTYPE>(info); }
};

int main()
{
    using namespace std;

    ColorType ct{list(
                    cint<ColorTypeDef::Red>{}, "Red", "R",
                    cint<ColorTypeDef::Green>{}, "Green", "G",
                    cint<ColorTypeDef::Blue>{}, "Blue", "B"
                    )};
    cout << ct.infoOf<cint<ColorTypeDef::Green>>().fullname << endl;
//    cout << ct.infoBlock<cint<ColorTypeDef::Green>>().shortname << endl;
    return string(ct.infoOf<cint<ColorTypeDef::Green>>().shortname).size();
}
