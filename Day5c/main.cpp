#include <iostream>
#include <functional>

int mymin(int a, int b)
{
    return a < b ? a : b;
}

int mymax(int a, int b)
{
    return a > b ? a : b;
}

struct Dummy
{
    int value;

    void foo()
    {
        std::cout << "foo = " << value << std::endl;
    }
};

struct Functor
{
    inline int operator()(int a, int b) const
    {
        return a > b ? a : b;
    }
};

template <typename FUNC>
int doIt_fast(int a, int b, const FUNC& func)
{
    return func(a, b);
}


int doIt_slow(int a, int b, std::function<int(int, int)> func)
{
    return func(a, b);
}


int main()
{
    // function pointer definitions
    {
//        int(*func)(int, int) = mymax; // direct style variable declaration
//        typedef int(*func_ptr)(int, int); // old style type definition
        using func_ptr = int(*)(int, int); // new style type definition
        func_ptr func = mymax;
        std::cout << func(3, 5) << std::endl;
    }

    std::cout << doIt_slow(3, 5, [](int a, int b) { return a > b ? a : b; }) << std::endl;

    // assigning a functor to std::function and runtime calling of the lambda by a function call
    {
        Functor functor;
        std::function<int(int, int)> func = functor;
        std::cout << doIt_slow(3, 5, func) << std::endl;
    }

    // assigning a lambda to std::function and runtime calling of the lambda by a function call
    {
        std::function<int(int, int)> func = [](int a, int b) { return a > b ? a : b; };
        std::cout << doIt_slow(3, 5, func) << std::endl;
    }

    // compile time binding of lambda -> more optimization, no function call for evaluating max
    std::cout << doIt_fast(3, 5, [](int a, int b) { return a > b ? a : b; }) << std::endl;

    // functor is already instantiated, there is a function belonging to it,
    // no way of optimization even if we call fast version
    // fast version acts as if it is a slow version. It will call the function in functor.
    {
        Functor functor;
        std::cout << doIt_fast(3, 5, functor) << std::endl;
    }

    // member function pointer usage
    {
        using memfunc_ptr = void(Dummy::*)();

        Dummy d{8};
        d.foo();

        memfunc_ptr mfunc = &Dummy::foo;
        (d.*mfunc)();
    }

    return 0;
}
