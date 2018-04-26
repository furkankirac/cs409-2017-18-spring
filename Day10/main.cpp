#include <iostream>

// SFINAE, enable_if

// template auto parameters

// array types with constant size
// compile time integral numbers

// std::map, std::any
// static_cast, dynamic_cast, reinterpret_cast, const_cast
// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

//template<bool B, typename T = void>
//struct enable_if { };

//template<class T>
//struct enable_if<true, T>
//{
//    using type = T;
//};

template<typename T>
typename enable_if<!is_same_v<T, string>>::type func(T value)
{
    cout << value << endl;
}


int main()
{
    func(5);
    func("furkan"s);
    return 0;
}
