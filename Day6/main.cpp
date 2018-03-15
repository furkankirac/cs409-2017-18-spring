#include <iostream>
#include <vector>

// location of const
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

int main(int argc, char* argv[])
{    
    using namespace std;

    int a = 5;
    int b = 6;

    const int* p = &a;
    int const * p2 = &a;
//    p2[0] = 10; // cannot do this
    p2 = &b; // can do

    int* const p3 = &a;
    *p3 = 10; // this works
    p3 = &b; // this doesn't work


}
