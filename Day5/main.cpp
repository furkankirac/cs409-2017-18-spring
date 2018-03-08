#include <iostream>

using namespace std;

class Dummy;

class Furkan // FriendlyToDummies
{
    friend class Dummy; // Dummy class can access even private fields of Furkan

private:
    int money; // Dummy can access this

public:
    Furkan(int money) : money(money) { }

    friend void stealFromFurkan(Dummy& d, Furkan& f); // stealFromFurkan function can access private fields

    int getMoney() const
    {
        return money;
    }

};

struct Dummy
{
    static int count; // count belongs to Dummy class, not to its instances.

    int value;
    static int dummy(const Dummy& d)
    {
        return d.value;
    }
};

int Dummy::count = 0;

void stealFromFurkan(Dummy& d, Furkan& f)
{
    d.value = f.money;
    f.money = 0;
}



int counter()
{
    static int count = 0; // initialized at first call, freed when program ends
    return ++count;
}

int main(int argc, char* argv[])
{
    Furkan f(1000000000);
    Dummy d{0};

    std::cout << "Furkan's Money = " << f.getMoney() << std::endl;
    std::cout << "Dummy's Money = " << d.value << std::endl;
    stealFromFurkan(d, f);
    std::cout << "Furkan's Money = " << f.getMoney() << std::endl;
    std::cout << "Dummy's Money = " << d.value << std::endl;

    {
        Dummy d{42};
        // dummy function is static. It doesn't require an instance.
        // it is as if a global function locked into Dummy struct
        std::cout << Dummy::dummy(d) << std::endl;

        // static int count is initialized in first call to counter() and
        // then it retains its value as if it is a global variable
        std::cout << counter() << std::endl; // prints 1
        std::cout << counter() << std::endl; // prints 2
        std::cout << counter() << std::endl; // prints 3
    }

    return 0;
}
