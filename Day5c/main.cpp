#include <iostream>

using namespace std;

// global functions, member functions, static functions, friend functions, inline functions
// global variables, static variables
// function pointers, member function pointers, std::function
// functors, function pointers and lambdas as arguments
// capturing return variable's type

inline int max(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    int a = 3;
    int b = 5;
    cout << max(a, b) << endl;
    cout << (a > b ? a : b) << endl;

    return 0;
}
