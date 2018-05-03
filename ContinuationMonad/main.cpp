#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

enum class DebugMode { On, Off };

static constexpr auto default_debug_mode = DebugMode::On; // make this Off for turning extra type debug info in output

// this is a generalized to_string function that also works on const char* and char types
auto make_string = [](auto&& x, DebugMode mode = default_debug_mode) {
    using T = decay_t<decltype(x)>;
    auto debug = mode == DebugMode::On;
    if constexpr(is_same_v<T, string>)
        return x + (debug ? "(string)" : "");
    else if constexpr(is_same_v<T, const char*>)
        return string(x) + (debug ? "(const char*)" : "");
    else if constexpr(is_same_v<T, char>)
        return string(1, x) + (debug ? "(char)" : ""); // create a length 1 string from char
    else if constexpr(is_integral_v<T>)
        return std::to_string(x) + (debug ? "(integral)" : "");
};

// returns a new lambda that captures variadic number of arguments and
// this lambda when given a callable (called access), passes the parameter pack into it and returns whatever that callable returns.
// that way it provides "access" to the captured parameter pack.
auto list = [](auto ...x) {
    return [=](auto access) { return access(x...); };
};

// head, tail, length, print are examples of operations that you may perform on a list.

// head returns the first element of the list.
auto head = [](auto x) {
    auto access = [](auto first, auto ...rest) { return list(first); };
    return x(access); // stored parameter pack of the list will be applied to access functor
};

// tail returns the list excluding the first element.
auto tail = [](auto x) {
    auto access = [](auto first, auto ...rest) { return list(rest...); };
    return x(access); // stored parameter pack of the list will be applied to access functor
};

// length returns the size of the parameter pack stored.
auto length = [](auto x) /* -> size_t */ {
    auto access = [](auto ...z) { return sizeof...(z); };
    return x(access); // stored parameter pack of the list will be applied to access functor
};

// println prints each element of the parameter pack in a new line
auto println = [](auto x) /* -> void */ {
    // nice trick below to put an "endl" after each element
    auto access = [](auto ...z) { (void)initializer_list<int>{ ((cout << make_string(z) << endl), 0)... }; };
    return x(access); // stored parameter pack of the list will be applied to access functor
};

// join creates a string by joining the stringified elements of the parameter pack by inserting a joiner in between
auto join = [](auto x, const string& joiner = "; ") /* -> string */ {
    auto access = [joiner](auto ...z) {
        vector<string> v = {make_string(z)...};
        return accumulate(next(v.begin()), v.end(), v[0], [joiner](const string& accum, const string& s) { return accum + joiner + s; });
    };
    return x(access); // stored parameter pack of the list will be applied to access functor
};


int main()
{
    auto L = list(1, '2', "3", "4"s);

    cout << "Length of list is " << length(L) << endl << endl;

    cout << "List contents are below:" << endl;
    println(L);
    cout << endl;

    cout << "List contents joined by comma is" << endl << join(L, ", ") << endl << endl;

    cout << "Head element of the list is" << endl << join(head(L)) << endl << endl;

    cout << "Tail elemenets of the list is " << join(tail(L)) << endl;

    return 0;
}
