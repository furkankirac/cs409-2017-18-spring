#include <memory>
#include <iostream>
#include <vector>

// std::sort example

// placement new and calling destructor directly
// std::unique_ptr, std::shared_ptr

// returning {}
// why & is not needed for taking address of functions but required for taking address of member functions
// std::function and member function pointer storage
// compiler explorer: -O3

struct Dummy
{
    int value{42};
    std::string s;

    Dummy(int value, const std::string& s) : value(value), s(std::move(s)) { }

};

std::unique_ptr<Dummy> func(std::unique_ptr<Dummy> d)
{
    d->value = 100;
    return std::move(d);
}

std::shared_ptr<Dummy> func(std::shared_ptr<Dummy> d)
{
    return d;
}


int main()
{
//    std::unique_ptr<Dummy> d(new Dummy);
//    std::unique_ptr<Dummy> d = std::make_unique<Dummy>();
    auto d = std::make_unique<Dummy>(100, "deneme");
    d = func(std::move(d));

    auto s = std::make_shared<Dummy>(200, "shared");
    s = func(s);



    const auto& internal_object = *d;
    std::cout << internal_object.value << std::endl;
    std::cout << (*d).value << std::endl;
    std::cout << d->value << std::endl;

    return 0;
}
