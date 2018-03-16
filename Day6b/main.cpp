#include <memory>
#include <iostream>
#include <vector>

struct Dummy
{
    int value{42};
    std::string s;

    Dummy(int value, const std::string& s) : value(value), s(std::move(s)) { }
};

// this function takes the ownership of a Dummy instance from outside world
std::unique_ptr<Dummy> func(std::unique_ptr<Dummy> d)
{
    d->value = 100; // -> is required to dereference unique_ptr and get access to the underlying instance

    // return the ownership to the outside world
    // std::move is required because returning a copy is not allowed by design of unique_ptr
    // unique_ptr does not implement a copy constructor by design
    // we need to address the move constructor of unique_ptr
    return std::move(d);
}

// take the ability to access the Dummy instance contained
std::shared_ptr<Dummy> func(std::shared_ptr<Dummy> d)
{
    return d; // do nothing and return the shared_ptr to the caller
}


int main()
{
//    std::unique_ptr<Dummy> d(new Dummy); // C++11 style, new is used
//    std::unique_ptr<Dummy> d = std::make_unique<Dummy>(); // variadic templates allow creation of make_unique that doesn't cause to write new
    auto d = std::make_unique<Dummy>(100, "deneme"); // use auto at left hand since type is already defined at the right hand side
    d = func(std::move(d)); // move the ownership of unique_ptr to func, it returns the ownership back, we store the object in d again

    auto s = std::make_shared<Dummy>(200, "shared");
    s = func(s);

    const auto& internal_object = *d; // access the encapsulated object of unique_ptr
    std::cout << internal_object.value << std::endl;
    std::cout << (*d).value << std::endl; // short notation
    std::cout << d->value << std::endl; // shorter notation

    return 0;
}
