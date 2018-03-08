#include <iostream>

namespace X
{
    struct FriendExample
    {
        friend std::string foo(const FriendExample& fe);
    };

    std::string foo(const FriendExample& fe)
    {
        return "foo X";
    }

}

namespace Y
{
    struct FriendExample
    {
        friend std::string foo(const FriendExample& fe)
        {
            return "foo Y";
        }
    };
}

int main()
{
    {
        X::FriendExample fe;
        std::cout << X::foo(fe) << std::endl; // X::foo function is explicitly defined, hence, accessible
    }

    {
        Y::FriendExample fe;
//        std::cout << Y::foo(fe) << std::endl; // Y::foo function is not accessible. There is no Y::foo.
        std::cout << foo(fe) << std::endl; // Y::foo function is accessible through ADL
    }
    return 0;
}
