#ifndef CUSTOMLITERALS_H
#define CUSTOMLITERALS_H

namespace Day8
{
    namespace CustomLiterals
    {
        struct Degree;

        struct Radian
        {
            float value;

            Radian& operator =(const Degree other);
        };

        struct Degree
        {
            float value;

            Degree& operator =(const Radian other);
        };

        inline Degree operator"" _deg(long double value)
        {
            return Degree{(float)value};
        }

        inline Degree operator"" _deg(unsigned long long int value)
        {
            return Degree{(float)value};
        }

        inline Radian operator"" _rad(long double value)
        {
            return Radian{(float)value};
        }

        inline Radian operator"" _rad(unsigned long long int value)
        {
            return Radian{(float)value};
        }


        void run();
    }
}

#endif // CUSTOMLITERALS_H
