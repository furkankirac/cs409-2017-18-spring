#include "Fraction.h"

int main()
{
    Fraction F1("ali", 1, 2);
    Fraction F2("veli", 2, 3);
    Fraction F3(F2);

    F1.print();
    F2.print();
    F3.print();

//    F1.operator =(F2);
//    F1 = F2;


    Fraction F_added = F1.add(F2);
    F_added.print();

    return 0;
}
