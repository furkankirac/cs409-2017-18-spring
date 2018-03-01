#include <iostream>

// ADL: Argument-dependent lookup
namespace X
{
    template <typename T>
    struct Number
    {
        T m_value;
    };

    template <typename T>
    auto add(const T& a, const T& b)
    {
        if constexpr(std::is_class<T>::value)
            return a.m_value + b.m_value;
        else
            return a + b;
    }

    auto subtract(int a, int b) -> int
    {
        return a - b;
    }

}


template <typename T>
float doIt(int a, int b, const T& func)
{
    return func(a, b);
}


int main()
{
//    int a = 5;
//    int a(5);
//    int a{5};
//    auto a = int{5};

//    typedef X::Number<float> FloatNumber;
    using FloatNumber = X::Number<float>;

    {
//        auto summation = X::add(5, 6);
        auto summation = add(FloatNumber{5.2}, FloatNumber{6.3});
        std::cout << summation << std::endl;
    }

    {
        int a=5;
        int b=6;

        auto f = [=]() mutable {
            ++a;
            ++b;
            return a*b;
        };
        auto summation = f();
        std::cout << summation << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;

        summation = f();
        std::cout << summation << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
    }

    return 0;
}
