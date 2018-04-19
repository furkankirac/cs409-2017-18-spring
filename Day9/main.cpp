#include <iostream>
#include <cstdarg>

// variadic parameters
// variadic templates: printAll: old style recursion, if constexpr version
// pack expansion, initializer_lists
// template type deduction displayer trick

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

void printAll(int count, ...)
{
    va_list args;
    va_start(args, count);
    while(true)
    {
        auto value = va_arg(args, int);
        if(value == -1)
            break;
        cout << value << endl;
    }
    cout << endl;
    va_end(args);
}


int main()
{
    printAll(0, 1, 2, 3, 4, 5, -1);
    printAll(0, 10, 20, 30, -1);
    return 0;
}
