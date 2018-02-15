#include <string>

class Fraction
{
    std::string m_name;
    int m_top;
    int m_bottom;

public:
    Fraction(int top=0, int bottom=1) : m_top(top), m_bottom(bottom)
    {
    }

    Fraction(std::string name, int top=0, int bottom=1) :
        Fraction(top, bottom)
    {
        m_name = name;
    }

    ~Fraction()
    {
    }
};

int main()
{
    {
    Fraction* F = new Fraction;
    delete F;
    }

    {
    Fraction F2;
    }

    Fraction* F3;

    return 0;
}
