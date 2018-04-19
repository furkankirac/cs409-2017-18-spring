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

void printAll()
{
}

template<typename HEAD, typename... TAIL>
void printAll(HEAD head, TAIL... tail)
{
    cout << head << endl;
    printAll(tail...);
}

int main()
{
    printAll(1, 2, 30.0, "deneme", 5);

    cout << endl;

    printAll(10, 20, 30);
    return 0;
}
