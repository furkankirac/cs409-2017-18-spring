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

void printVector(const std::vector<int>& vec)
{
    for(auto value : vec)
        std::cout << value << std::endl;
}

int main(int argc, char* argv[])
{    
    using namespace std;

    int array[10];

    vector<int> v{10, 20};
    printVector(v);

}
