#include <iostream>
#include <string>

// partial template specialization for classes
// template specialization for function templates

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast
// CRTP

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

using namespace std;

template<typename T, int K>
struct Array
{
    T values[K];
};

template<int K>
struct Array<double, K>
{
    double doubles[K];
    std::string text;
};

template<>
struct Array<float, 1>
{
    float V;
};

template<typename T, int K = 1>
inline void println(T value)
{
    cout << value;
    for(int i=0; i<K; ++i)
        cout << endl;
}


int main()
{
    Array<int, 10> A;
    A.values[0] = 10;

    Array<double, 20> D;
    D.doubles[2] = 2.3;
    D.text = "hurray";

    Array<float, 1> F;
    F.V = 3.2f;

    println(F.V);
    println<std::string, 3>(D.text);

    return 0;
}
