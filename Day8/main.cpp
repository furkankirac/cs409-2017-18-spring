#include <iostream>
#include <string>

using namespace std;

// Curiously recurring template pattern

template<typename DERIVED>
struct Base
{
    std::string text;
    int times;

    void print()
    {
//        DERIVED::PRINT();
        ((DERIVED*)this)->PRINT();
    }
};

struct Derived : public Base<Derived>
{
    void PRINT()
    {
//        cout << "deneme" << endl;
        for(int i=0; i<times; ++i)
            cout << text;
    }
};




int main()
{
    Derived D;
    D.print();

    return 0;
}
