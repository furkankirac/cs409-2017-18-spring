#include <variant>
#include <string>
#include <iostream>

#include "VariantVisitor.h"

namespace Day8
{
    namespace VariantVisitor
    {
        struct Foo { };

        using myvariant = std::variant<int, double, std::string, Foo>;

        void printVariant(const myvariant& var)
        {
            std::visit([](auto&& value) {
                using T = typename std::decay_t<decltype(value)>;
                if constexpr(std::is_same_v<T, Foo>)
                {
                    return;
                }
                else
                {
                    if constexpr(std::is_same_v<T, std::string>)
                        std::cout << "This is a string: ";
                    std::cout << value << std::endl;
                }

            }, var);

        }

        void run()
        {
            using namespace std::literals;
            myvariant value = 5.2; //"furkan"s;

            printVariant(value);

        }
    }
}
