#include <iostream>
//#include <variant>
//#include <vector>
//#include <numeric>
//#include <algorithm>

using namespace std;

// variable templates
template<class T>
constexpr T pi = T(3.1415926535897932385L);  // variable template

template<class T>
T circular_area(T r) // function template
{
    return pi<T> * r * r; // pi<T> is a variable template instantiation
}


//template<typename T, typename = enable_if_enum_or_integral<T>>
//inline bool instanceOf(const T type) const { return codecId() == (LCT)type; }

// cint --> std::integral_constant
// class template parameter deduction
// deduction guides
// overloaded lambdas

// std::accumulate
// std::remove, std::remove_if

// std::common_type_t
// std::gcd, lcm
// std::stoi, stol, stof
// std::add_cv, std::add_const, std::add_volatile
// std::clamp

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

int main()
{
    return 0;
}
