#include <iostream>
#include <vector>

namespace X
{
    // inheriting from std::vector<T> does not inherit constructors, assignment operator overloads
    template<typename T>
    struct vec : public std::vector<T>
    {
        using value_type = T;

        using base = std::vector<T>; // give an alias to base class so that refering to constructor is easy
        using base::base; // use contructors of base class (import them)
        using base::operator =; // use assignemt operators of base class (import them)
    };

} // end of X


// a function that prints std::vector of any type
// but it does follow a special quoted style for vector<std::string> containers
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

#define CONVERT_VERSION 2 // make this either 1 or 2 for selecting different versions of the same function
#if CONVERT_VERSION == 1

// 1st implementation of convert where underlying type of std::vector is auto-deduced
template<typename UNDERLYING_TYPE_TO, typename UNDERLYING_TYPE_FROM>
void convert(std::vector<UNDERLYING_TYPE_TO>& to, const std::vector<UNDERLYING_TYPE_FROM>& from)
{
    to.clear();
    for(const auto a : from)
    {
        if constexpr(std::is_same<UNDERLYING_TYPE_TO, std::string>::value)
            to.push_back(std::to_string(a));
        else
            to.push_back(a);
    }
}
#else
// 2nd implementation of convert where the whole type (i.e. std::vector<float>) is auto deduced
// in this version we need to detect underlying type (i.e. float) from the deduced type
template<typename TYPE_TO, typename TYPE_FROM>
void convert(TYPE_TO& to, const TYPE_FROM& from)
{
    // std::vector has an alias "value_type" which defines the type it uses

    // when you refer to a type "typename" is put in front
    // a not so important detail for now
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
#endif


int main(int argc, char* argv[])
{    
    using namespace std;

    std::vector<std::string> v_str;

    {
        std::vector<int> v_int{1, 2, 3, 4};
        convert(v_str, v_int);
        printVector(v_int);
        printVector(v_str);
    }

    {
        convert(v_str, std::vector<int>{1, 2, 3, 4}); // rvalue, this works because of const usage in convert
        printVector(std::vector<int>{1, 2, 3, 4});
        printVector(v_str);
    }

    {
        std::vector<float> v_float{1.1f, 2.2f, 3.3f, 4.4f};
        convert(v_str, v_float);
        printVector(v_float);
        printVector(v_str);
    }
}
