#include <iostream>
#include <cstdarg>

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

auto func()
{

}

int main()
{
    std::array<int, 2> a2;
    std::array<float, 3> a3;

    a2 = func(); // func is gonna deduce the return type's 2 and do plan A
    a3 = func(); // func is gonna deduce the return type's 3 and do plan B

    return 0;
}
