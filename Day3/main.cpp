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
    Animal::Type    m_type = Type::Dog;
    std::string     m_name = "";
    short           m_age = 0;
    Gender          m_gender = Gender::Female;

public:
    Animal() = default;

    Animal(Animal::Type type, const std::string& name = "") :
        m_type(type),
        m_name(std::move(name))
    {
    }

    Animal(const Animal& other)
    {
        *this = other;
    }

    Animal(Animal&& other)
    {
        m_type = other.m_type;

        m_name = std::move(other.m_name);
//        m_name = (std::string&&)other.m_name;

        m_age = other.m_age;
        m_gender = other.m_gender;
    }


    Animal& operator =(const Animal& other) = default;

    Animal& operator =(Animal&& other) = default;

    virtual ~Animal()
    {
    }

    Animal& operator <<(const std::string& name)
    {
        m_name = name;
        return *this;
    }

    const std::string& name() const
    {
        return m_name;
    }

    operator std::string()
    {
        return m_name;
    }

    int dummy() const
    {
        return 42;
    }

    virtual void printType()
    {
        std::cout << "Animal" << std::endl;
    }

};

class XAnimal : public Animal
{
public:
    XAnimal() : Animal() { }
    XAnimal(Animal::Type type, const std::string& name = "") :
        Animal(type, name)
    {
    }

    int dummy() const = delete;

    virtual void printType() override
    {
        std::cout << "XAnimal" << std::endl;
    }
};


int main()
{
    using namespace std;

    Animal puppy(Animal::Type::Dog, "puppy");
    Animal sparky((Animal&&)puppy);

    XAnimal xpuppy;
//    xpuppy.dummy();

    puppy.printType();
    xpuppy.printType();

    Animal* pAnimal;

    pAnimal = &puppy;
    pAnimal->printType();
//    pAnimal[0].printType();
//    (*pAnimal).printType();

    pAnimal = &xpuppy;
    pAnimal->printType();

    puppy << "furkan";
    std::string animalName = puppy.name();
    std::cout << animalName << std::endl;

    std::string animalName2 = puppy;
    std::cout << animalName2 << std::endl;

    std::cout << (std::string)puppy;

    cout << "Hello World!" << endl;
    return 0;
}
