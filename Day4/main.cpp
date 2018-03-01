#include <iostream>

// ADL: Argument-dependent lookup
namespace X
{
    struct Integer
    {
        int m_value;
    };

    int add(const Integer& a, const Integer& b)
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
    int summation = add(X::Integer{5}, X::Integer{6});
    return 0;
}
