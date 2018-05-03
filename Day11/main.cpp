#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    using namespace std;

    vector<float> V{1.1, 2.2, 3.3, 4.9};

    // start from the string version of the first float and concatenate a comma followed by each float in the array by converting it to string
    auto sum = accumulate(next(V.begin()), V.end(), to_string(V[0]), [](const string& s, float value) { return s + ", " + to_string(value); });
    cout << sum << endl;

    sum.erase(remove(sum.begin(), sum.end(), ','), sum.end());
    cout << sum << endl;

    return 0;
}
