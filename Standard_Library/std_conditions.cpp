#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v1 = {2, 4, 6, 8, 10, 12, -2};

    bool all_even = all_of(v1.begin(), v1.end(), [](int x) {return x % 2 == 0;});
    bool any_multiple_of_three = any_of(v1.begin(), v1.end(), [](int x) {return x % 3 == 0;});
    bool non_negative = none_of(v1.begin(), v1.end(), [](int x) {return x < 0;});

    cout << "All elements are even: " << (all_even ? "True" : "False") << endl;
    cout << "There is a multiple of three: " << (any_multiple_of_three ? "True" : "False") << endl;
    cout << "No elements are negative: " << (non_negative ? "True" : "False") << endl;

    
    return 0;
}