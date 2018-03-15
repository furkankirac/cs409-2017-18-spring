#ifndef VECTORUTILITIES_H
#define VECTORUTILITIES_H

#include <vector>

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

#endif // VECTORUTILITIES_H
