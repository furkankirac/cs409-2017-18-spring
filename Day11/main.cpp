#include <iostream>
#include <variant>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// std::common_type_t
// std::gcd, lcm
// std::stoi, stol, stof
// std::add_cv, std::add_const, std::add_volatile
// std::clamp

// std::map
// std::any

// static_cast, dynamic_cast, reinterpret_cast, const_cast

// inline variables
// [[fallthrough]], [[maybe_unused]], [[nodiscard]]

int main()
{
    using namespace std;

    vector<float> V{1.1, 2.2, 3.3, 4.9};

    auto sum = accumulate(next(V.begin()), V.end(), to_string(V[0]),
            [](const string& s, float value) {
                return s + ", " + to_string(value);
                }
    );
    cout << sum << endl;

    sum.erase(remove(sum.begin(), sum.end(), ','), sum.end());
    cout << sum << endl;


    // std::remove, std::remove_if


    return 0;
}





