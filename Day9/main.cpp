#include <iostream>
#include <cstdarg>

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

template<typename T>
struct TypeDisplayer;

void print_(const int& value)
{
    cout << "lvalue:" << value << endl;
}

void print_(int&& value)
{
    cout << "rvalue:" << value << endl;
}

template<typename T>
void print(T&& value)
{
//    TypeDisplayer<T> x;
//    TypeDisplayer<decltype(value)> y;

    print_(std::forward<T>(value));
}

int main()
{
    int i = 5;
    const int ci = 10;

//    print(5); // T = int, value = int
//    print(5.0); // T = double, value = double
//    print(i); // T = int, value = int
    print(ci);
    print(5);
//    print(ci); // T = int, value = int

    return 0;
}
