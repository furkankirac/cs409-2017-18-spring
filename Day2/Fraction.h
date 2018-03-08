#ifndef FRACTION_H
#define FRACTION_H

#include "stdio.h"
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

    Fraction(const std::string& name, int top=0, int bottom=1) :
        Fraction(top, bottom)
    {
        m_name = name;
    }

    Fraction(const Fraction& other) :
        Fraction(other.m_name, other.m_top, other.m_bottom)
    {
    }

    ///// non-default destructor
    ~Fraction() = default;

    Fraction& operator =(const Fraction& other)
    {
        set(other.top(), other.bottom());
        return *this;
    }

//    Fraction& operator =(int k)
//    {
//        set(k, 1);
//        return *this;
//    }

    int top() const
    { return m_top; }

    int bottom() const
    { return m_bottom; }

    void set(int top, int bottom)
    {
        m_top = top;
        m_bottom = bottom;
    }

    Fraction add(const Fraction& other) const
    {
        return Fraction(
                    top()*other.bottom()+other.top()*bottom(),
                    bottom()*other.bottom()
                    );
    }

    void print()
    {
        if(m_name.empty())
            printf("%d/%d\n", top(), bottom());
        else
            printf("%s: %d/%d\n", m_name.c_str(), top(), bottom());
    }

};


#endif // FRACTION_H
