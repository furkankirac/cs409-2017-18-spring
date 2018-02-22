#include <iostream>

#include <string>

enum class Gender
{
    Female,
    Male
};

class Animal
{
public:
    enum class Type
    {
        Dog,
        Cat,
        Rabbit,
        Crow
    };

private:
    Animal::Type    m_type;
    std::string     m_name;
    short           m_age = 0;
    Gender          m_gender = Gender::Female;

public:
    Animal()
    {
    }

    Animal(Animal::Type type,
           const std::string& name = "") :
        m_type(type),
        m_name(name)
    {
    }

    Animal(const Animal& other)
    {
        *this = other;
    }

    Animal& operator =(const Animal& other)
    {
        m_type = other.m_type;
        m_name = other.m_name;
        m_age = other.m_age;
        m_gender = other.m_gender;

        return *this;
    }


    ~Animal()
    {
    }


};

int main()
{
    using namespace std;

    Animal puppy(Animal::Type::Dog);
    Animal sparky;

    sparky = puppy;

    cout << "Hello World!" << endl;
    return 0;
}
