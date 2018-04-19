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

template <typename T>
void print(const T& value)
{
    cout << value << endl;
}

template<typename... Ts>
void runOnAll(const Ts&... args)
{
    //print(1), print(2), print(30.0), print(5)
    // (void, 0), (void, 0), (void, 0), (void, 0)
    auto x = {(print(args),0)...};
    (void)std::initializer_list<int>{(print(args),0)...};
}


int main()
{
    runOnAll(1, 2, 30.0, 5);

    return 0;
}
