#include <iostream>
#include <vector>

// reference vs pointer safety

// write template class storing T as value_type
// std::vector<T> container usage
// for(auto...)
// capturing return variable's type, and assigning to a different container with different T
// std::sort example

// placement new and calling destructor directly
// std::unique_ptr, std::shared_ptr

// returning {}
// why & is not needed for taking address of functions but required for taking address of member functions
// std::function and member function pointer storage
// compiler explorer: -O3

namespace X
{
    template<typename T>
    struct vec : public std::vector<T>
    {
        using value_type = T;

        using base = std::vector<T>;
        using base::base;
        using base::operator =;
    };

} // end of X


template<typename T>
void printVector(const std::vector<T>& vec)
{
    for(auto value : vec)
    {
        if constexpr(std::is_same<T, std::string>::value)
            std::cout << "'" << value << "'" << std::endl;
        else
            std::cout << value << std::endl;
    }
}

template<typename TYPE_TO, typename TYPE_FROM>
void convert(TYPE_TO& to, const TYPE_FROM& from)
{
    using underlying_type_to = typename TYPE_TO::value_type;
//    using underlying_type_from = typename TYPE_FROM::value_type;

    to.clear();
    for(const auto a : from)
    {
        if constexpr(std::is_same<underlying_type_to, std::string>::value)
            to.push_back(std::to_string(a));
        else
            to.push_back(a);
    }
}


int main(int argc, char* argv[])
{    
    using namespace std;

    std::vector<int> A{1, 2, 3, 4};
    std::vector<std::string> B;
    std::vector<float> C{1.1f, 2.2f, 3.3f, 4.4f};
    std::vector<std::string> D;

    convert(B, A);
    convert(D, C);
//    convert(B, std::vector<int>{1, 2, 3, 4}); // rvalue, this works because of const usage in convert
    printVector(A);
    printVector(B);
    printVector(C);
    printVector(D);

//    B = A;

//    X::vec<int> v{10, 20};
//    printVector(v);

}
