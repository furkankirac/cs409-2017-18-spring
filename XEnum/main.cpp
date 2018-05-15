#include <iostream>
#include <tuple>

#define STRINGS_WITH_UDL // enable experimental user defined literals which is not part of the standard but Clang and GCC supports it

namespace compile_time
{
    // compile-time integral values
    template<auto u>
    using cint = typename std::integral_constant<decltype(u), u>;

    template<auto u>
    constexpr cint<u> cintvar{}; // cintvar is a templatized variable.

    // compile-time strings
    template<char ...s>
    constexpr char const string_storage[sizeof...(s) + 1] = {s..., '\0'};

    template<char ...s>
    struct cstring { static constexpr const char* c_str() { return &string_storage<s...>[0]; } };

#ifdef STRINGS_WITH_UDL
    template <char ...s>
    constexpr cstring<s...> cstring_var{}; // variable template (templatized variable)

    inline namespace literals
    {
        // this is experimental usage not in the standard yet. because string literals cannot be templatized as we wish yet
        // but fortunately both GCC and Clang supports it
        template <typename CHARTYPE, CHARTYPE ...s>
        constexpr auto operator"" _s()
        {
            static_assert(std::is_same<CHARTYPE, char>::value, "we support only char for character types.");
            return cstring_var<s...>;
        }
    } // namespace literals
#else
    template <typename S, std::size_t ...N>
    constexpr cstring<S::get()[N]...> prepare_impl(S, std::index_sequence<N...>) { return {}; }

    template <typename S>
    constexpr decltype(auto) prepare(S s) { return prepare_impl(s, std::make_index_sequence<sizeof(S::get()) - 1>{}); }

#define CSTR(s) \
    compile_time::prepare([]{ \
        struct tmp { static constexpr decltype(auto) get() { return s; } }; \
        return tmp{}; \
        }() )
#endif
} // namespace compile_time

using namespace compile_time;

struct EnumInfo
{
    const char* fullname{};
    const char* shortname{};
};

template<typename ENUMSTRUCT, typename ...Ts>
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

// ENUMTYPE definitions

// ---[ ColorType
namespace impl
{
    struct ColorType { enum Type { Red, Green, Blue, Orange, DEFAULT = Blue }; };
} // namespace impl

constexpr EnumType color_type{
    impl::ColorType{},
    cintvar<impl::ColorType::Red>, "Red"_s, "R"_s,
    cintvar<impl::ColorType::Green>, "Green"_s, "G"_s,
    cintvar<impl::ColorType::Blue>, "Blue"_s, "B"_s
};
using ColorType = decltype(color_type);

// ---[ Transformation
namespace impl
{
    struct TransformationType { enum Type { None, Rotate_90, Rotate_180, Rotate_270, Flip_Horizontal, Flip_Vertical, DEFAULT = None }; };
} // namespace impl

constexpr EnumType transformation_type{
    impl::TransformationType{},
    cintvar<impl::TransformationType::None>, "None"_s, "None"_s,
    cintvar<impl::TransformationType::Rotate_90>, "Rotate 90 Degrees"_s, "Rot90"_s,
    cintvar<impl::TransformationType::Rotate_180>, "Rotate 180 Degrees"_s, "Rot180"_s,
    cintvar<impl::TransformationType::Rotate_270>, "Rotate 270 Degrees"_s, "Rot270"_s,
    cintvar<impl::TransformationType::Flip_Horizontal>, "Flip Horizontal"_s, "H.Flip"_s,
    cintvar<impl::TransformationType::Flip_Vertical>, "Flip Vertical"_s, "V.Flip"_s
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
