#include "Fraction.h"

Fraction add(const Fraction& F1, const Fraction& F2)
{
    Fraction Fnew;
    int top = F1.top()*F2.bottom()+F2.top()*F1.bottom();
    int bottom = F1.bottom()*F2.bottom();
    Fnew.set(top, bottom);
    return Fnew;
}


int main()
{
    Fraction F1("ali", 1, 2);
    Fraction F2("veli", 2, 3);

    F1.print();
    F2.print();

    Fraction F_added = add(F1, F2);
    F_added.print();

    return 0;
}
