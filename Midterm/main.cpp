#include <iostream>

namespace Q1
{
    template<typename T>
    struct Pair
    {
        T first, second;

        friend void print(const Pair<T>& pair)
        { std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl; }

        // Q1a
        Pair(const T& first, const T& second) :
            first(std::move(first)), second(std::move(second)) { }

        // Q1b
        template<typename T2>
        Pair(const T2& other)
        {
            if constexpr(std::is_same<T, std::string>::value)
            {
                first = "'" + std::to_string(other.first) + "'";
                second = "'" + std::to_string(other.second) + "'";
            }
            else
            {
                first = other.first;
                second = other.second;
            }
        }
    }; // end of Pair struct

} // end of Q1 namespace

namespace Q2
{
    class Functor
    {
        const int& u;
        const double n;

    public:
        Functor(const int&u, const double n) : u(u), n(n) { }

        auto operator() (const float f) { return f*u*n; }
    };
} // end of Q2

namespace Q7_UG
{
    struct Foo
    {
        int n;
        std::string s;
        float f;
    };

    template<int N>
    auto& get(Foo& f)
    {
        if constexpr(N == 0)
            return f.n;
        else if constexpr(N == 1)
            return f.s;
        else if constexpr(N == 2)
            return f.f;
    }
} // end of Q7_UG

namespace Q7_GRAD
{
    template<typename T>
    auto FUNC(const T& lambda)
    {
        return [&](int a) {
            auto s = "[" + std::to_string(lambda(a)) + "]";
            return std::move(std::make_unique<std::string>(s));
        };
    }
} // end of Q7_GRAD


int main()
{
    // comment out if(false) lines for enabling blocks below

    if(false)
    {
        using namespace Q1;

        auto pair_int = Pair<int>(4, 5);
        print(pair_int);

        auto pair_float = Pair<float>(1.1f, 2.2f);
        print(pair_float);

        Pair<std::string> pair_str_1 = pair_int;
        print(pair_str_1);

        Pair<std::string> pair_str_2 = pair_float;
        print(pair_str_2);
    }

    if(false)
    {
        using namespace Q2;
        int u{5};
        double n{0.1};
        Functor func(u, n);
        std::cout << func(10) << std::endl;
    }

    if(false)
    {
        using namespace Q7_UG;
        auto foo = Foo{10, "hello", 3.14};
        int& n = get<0>(foo);
        std::string& s = get<1>(foo);
        float& f = get<2>(foo);
    }

    if(false)
    {
        auto new_functor = Q7_GRAD::FUNC([](int a) { return a+1; }); // define a functor instance (which takes an int) and pass it to FUNC as parameter
        auto u_ptr = new_functor(5);
        std::cout << *u_ptr << std::endl; // prints [6] to the console
    }

    return 0;
}
