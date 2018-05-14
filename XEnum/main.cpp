#include <iostream>
#include <tuple>

namespace compile_time
{
    // compile-time integral values
    template<auto u>
    using cint = typename std::integral_constant<decltype(u), u>;

    #define CINT(x) cint<x>{}

    // compile-time strings
    template<char ...s>
    constexpr char const string_storage[sizeof...(s) + 1] = {s..., '\0'};

    template<char ...s>
    struct cstring { static constexpr const char* c_str() { return &string_storage<s...>[0]; } };

    template <typename S, std::size_t ...N>
    constexpr cstring<S::get()[N]...> prepare_impl(S, std::index_sequence<N...>) { return {}; }

    template <typename S>
    constexpr decltype(auto) prepare(S s) { return prepare_impl(s, std::make_index_sequence<sizeof(S::get()) - 1>{}); }

    #define CSTR(s) \
        compile_time::prepare([]{ \
            struct tmp { static constexpr decltype(auto) get() { return s; } }; \
            return tmp{}; \
            }() )

} // end of compile-time namespace

using namespace compile_time;

struct EnumInfo
{
    const char* fullname{};
    const char* shortname{};
};

template<typename ENUMSTRUCT, typename... Ts>
struct EnumType : public ENUMSTRUCT
{
    using ENUMTYPE = typename ENUMSTRUCT::Type;
    using TUPLE = std::tuple<Ts...>;

    ENUMTYPE value{ENUMTYPE::DEFAULT};

    constexpr EnumType(const ENUMTYPE value = ENUMTYPE::DEFAULT) : value(value) { }

    constexpr EnumType(ENUMSTRUCT, const Ts...)
    {
    }

    template<ENUMTYPE ENUMVAL, size_t i = 0>
    static constexpr auto infoOf() -> EnumInfo
    {
        const auto sz = std::tuple_size_v<TUPLE>;
        if constexpr(std::is_same_v<cint<ENUMVAL>, std::tuple_element_t<i, TUPLE>>)
            return { std::tuple_element_t<i+1, TUPLE>::c_str(), std::tuple_element_t<i+2, TUPLE>::c_str() };
        else if constexpr(i < sz-1)
            return infoOf<ENUMVAL, i+1>();
        else
            return {"", ""};
    }
};

//template<typename FIRST, typename ...REST>
//EnumType(FIRST, const REST...) -> EnumType<typename FIRST::value_type, FIRST, REST...>;

// ENUMTYPE definitions
#define ENUMINFO(x, y, z) CINT(impl::x), CSTR(y), CSTR(z)

// ---[ ColorType
namespace impl
{
    struct ColorType { enum Type { Red, Green, Blue, Orange, DEFAULT = Blue }; };
}

constexpr EnumType color_type{
    impl::ColorType{},
    ENUMINFO(ColorType::Red, "Red", "R"),
    ENUMINFO(ColorType::Green, "Green", "G"),
    ENUMINFO(ColorType::Blue, "Blue", "B")
};
using ColorType = decltype(color_type);

// ---[ Transformation
namespace impl
{
    struct TransformationType { enum Type { None, Rotate_90, Rotate_180, Rotate_270, Flip_Horizontal, Flip_Vertical, DEFAULT = None }; };
}

constexpr EnumType transformation_type{
    impl::TransformationType{},
    ENUMINFO(TransformationType::None, "None", "None"),
    ENUMINFO(TransformationType::Rotate_90, "Rotate 90 Degrees", "Rot90"),
    ENUMINFO(TransformationType::Rotate_180, "Rotate 180 Degrees", "Rot180"),
    ENUMINFO(TransformationType::Rotate_270, "Rotate 270 Degrees", "Rot270"),
    ENUMINFO(TransformationType::Flip_Horizontal, "Flip Horizontal", "H.Flip"),
    ENUMINFO(TransformationType::Flip_Vertical, "Flip Vertical", "V.Flip")
};
//using TransformationType = decltype(transformation_type);
struct TransformationType : public decltype(transformation_type)
{
    void clear() { value = TransformationType::DEFAULT; }
};

int main()
{
    using namespace std;

    ColorType ct = ColorType::Green;
    TransformationType tt{TransformationType::Rotate_270};
    tt.clear();

    cout << ct.infoOf<ColorType::Green>().fullname << endl;
    cout << ct.infoOf<ColorType::Green>().shortname << endl;
    return string(ct.infoOf<ColorType::Green>().fullname).size();
//    return 0;
}
