#include <iostream>
#include <cstdarg>

// variadic templates: printAll: old style recursion, if constexpr version
// pack expansion, initializer_lists
// template type deduction displayer trick

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

template<typename... Ts>
void printAll(const Ts&... args)
{
    (std::cout << ... << args);
}

int main()
{
    printAll(1, 2, 30.0, std::string("deneme"), 5);

    cout << endl;

    printAll(10, 20, 30);
    return 0;
}
