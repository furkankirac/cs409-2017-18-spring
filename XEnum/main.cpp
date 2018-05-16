#include <array>
#include <iostream>
#include <string>
#include <tuple>

namespace compile_time
{
    // compile-time integral values
    template<auto u>
    using cint = typename std::integral_constant<decltype(u), u>;

    template<auto u>
    constexpr cint<u> cintvar{}; // cintvar is a templatized variable.

    // compile-time strings
    template<char ...s>
    constexpr const char string_storage[sizeof...(s) + 1] = {s..., '\0'};

    template<char ...s>
    struct cstring { static constexpr const char* c_str() { return &string_storage<s...>[0]; } };

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
} // namespace compile_time

using namespace compile_time;

template<typename ENUMSTRUCT, typename ...Ts>
struct EnumType : public ENUMSTRUCT
{
    using ENUMTYPE = typename ENUMSTRUCT::Type;
    using TUPLE = std::tuple<Ts...>;

    ENUMTYPE value{ENUMTYPE::DEFAULT};

    constexpr EnumType(const ENUMTYPE value = ENUMTYPE::DEFAULT) : value(value) { }
    constexpr EnumType(ENUMSTRUCT, const Ts...) { }

    template<ENUMTYPE ENUMVAL, size_t i = 0>
    static constexpr size_t indexOf()
    {
        const auto sz = std::tuple_size_v<TUPLE>;
        static_assert(i < sz, "indexOf cannot find what you are looking for!");

        if constexpr(std::is_same_v<cint<ENUMVAL>, std::tuple_element_t<i, TUPLE>>)
            return i;
        else
            return indexOf<ENUMVAL, i+1>();
    }

    template<ENUMTYPE ENUMVAL>
    static constexpr auto fullNameOf() { return std::tuple_element_t<indexOf<ENUMVAL>()+1, TUPLE>::c_str(); }

    template<ENUMTYPE ENUMVAL>
    static constexpr auto shortNameOf() { return std::tuple_element_t<indexOf<ENUMVAL>()+2, TUPLE>::c_str(); }
};

#define fullNameOf(type, val)   type::fullNameOf<type::val>()
#define shortNameOf(type, val)  type::shortNameOf<type::val>()

// ENUMTYPE definitions

// ---[ ColorType
namespace impl
{
    struct ColorType { enum Type { Red, Green, Blue, Orange, DEFAULT = Blue }; };
} // namespace impl

#define V(x) cintvar<T::x>

#define T impl::ColorType
constexpr EnumType color_type{
    T{},
    V(Red), "Red"_s, "R"_s,
    V(Green), "Green"_s, "G"_s,
    V(Blue), "Blue"_s, "B"_s
};
#undef T
using ColorType = decltype(color_type);

// ---[ Transformation
namespace impl
{
    struct TransformationType { enum Type { None, Rotate_90, Rotate_180, Rotate_270, Flip_Horizontal, Flip_Vertical, DEFAULT = None }; };
} // namespace impl

#define T impl::TransformationType
constexpr EnumType transformation_type{
    T{},
    V(None), "None"_s, "None"_s,
    V(Rotate_90), "Rotate 90 Degrees"_s, "Rot90"_s,
    V(Rotate_180), "Rotate 180 Degrees"_s, "Rot180"_s,
    V(Rotate_270), "Rotate 270 Degrees"_s, "Rot270"_s,
    V(Flip_Horizontal), "Flip Horizontal"_s, "H.Flip"_s,
    V(Flip_Vertical), "Flip Vertical"_s, "V.Flip"_s
};
#undef T
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

    cout << fullNameOf(ColorType, Green);
    cout << shortNameOf(ColorType, Blue);

    return (int)string(TransformationType::fullNameOf<TransformationType::Rotate_180>()).size();
}
