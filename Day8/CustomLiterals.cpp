#include <iostream>
#include "CustomLiterals.h"


namespace Day8
{
    namespace CustomLiterals
    {
        void run()
        {
            using namespace std;

            auto a = 5.0f;
            auto s = "deneme"s;
            auto r1 = 3.2_rad;
            auto r2 = 3_rad;
            auto d1 = 30_deg;
            auto d2 = 60_deg;

            r2 = d2; // assignment
            d1 = r1;

            cout << r1.value << " radians" << '\n';
            cout << r2.value << " radians" << '\n';

            cout << d1.value << " degrees" << '\n';
            cout << d2.value << " degrees" << '\n';

        }

        Radian& Radian::operator =(const Degree other)
        {
            value = other.value / 180.0f * 3.14f;
            return *this;
        }

        Degree& Degree::operator =(const Radian other)
        {
            value = other.value * 180.0f / 3.14f;
            return *this;
        }

    }
}
