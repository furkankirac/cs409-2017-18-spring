#include <iostream>

// ADL: Argument-dependent lookup
namespace X
{
    template <typename T>
    struct Number
    {
        T m_value;
    };

    int add(const Number<int>& a, const Number<int>& b)
    {
        return a.m_value + b.m_value;
    }

    int add(int a, int b)
    {
        return a+b;
    }

}


int main()
{
//    int summation = X::add(5, 6);
    int summation = add(X::Number<int>{5}, X::Number<int>{6});
    std::cout << summation << std::endl;
    return 0;
}
