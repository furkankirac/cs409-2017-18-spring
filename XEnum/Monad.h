#ifndef MONAD_H
#define MONAD_H

#include <iostream>
#include <vector>

inline namespace Monad
{
    // returns a new lambda that captures variadic number of arguments and
    // this lambda when given a callable (called access), passes the parameter pack into it and returns whatever that callable returns.
    // that way it provides "access" to the captured parameter pack.
    constexpr auto list = [](auto ...x) {
        return [=](auto access) { return access(x...); };
    };

    // head, tail, length, println, join are examples of operations that you may perform on a list.

    // head returns the first element of the list as a new list.
    constexpr auto head = [](auto x) {
        constexpr auto access = [](auto first, auto ...rest) { return list(first); };
        return x(access); // stored parameter pack of the list will be applied to access functor
    };

    // head returns the first element of the list as a new list.
    constexpr auto head_element = [](auto x) {
        constexpr auto access = [](auto first, auto ...rest) { return first; };
        return x(access); // stored parameter pack of the list will be applied to access functor
    };

    // tail returns a new list excluding the first element.
    constexpr auto tail = [](auto x) {
        constexpr auto access = [](auto first, auto ...rest) { return list(rest...); };
        return x(access); // stored parameter pack of the list will be applied to access functor
    };

    // length returns the size of the parameter pack stored which is equal to the number of elements of the list.
    constexpr auto length = [](auto x) /* -> size_t */ {
        constexpr auto access = [](auto ...z) { return sizeof...(z); };
        return x(access); // stored parameter pack of the list will be applied to access functor
    };

    // println prints each element of the parameter pack in a new line
    constexpr auto println = [](auto x) /* -> void */ {
        // nice trick below to put an "endl" after each element
        constexpr auto access = [](auto ...z) { (void)std::initializer_list<int>{ ((std::cout << make_string(z) << std::endl), 0)... }; };
        return x(access); // stored parameter pack of the list will be applied to access functor
    };

    // join creates a string by joining the stringified elements of the parameter pack by inserting a joiner in-between
    constexpr auto join = [](auto x, const std::string& joiner = "; ") /* -> string */ {
        auto access = [joiner](auto ...z) {
            // vector and accumulate support only run-time works. therefore this lambda doesn't work in compile-time jobs
            std::vector<std::string> v = {make_string(z)...};
            return accumulate(next(v.begin()), v.end(), v[0], [joiner](const std::string& accum, const std::string& s) { return accum + joiner + s; });
        };
        return x(access); // stored parameter pack of the list will be applied to access functor
    };

    //constexpr auto call_init = [](auto x) {
    //    constexpr auto access = [](auto ...vars) { return init(vars...); };
    //    return x(access);
    //};
}

#endif // MONAD_H
