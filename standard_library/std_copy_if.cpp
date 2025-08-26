#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    vector<int> v = {1,2,3,4,5};
    vector<int> destination;
    destination.reserve(v.size());
    copy_if(v.begin(), v.end(), back_inserter(destination), [](int x) {return x % 2 == 0;});

    for (auto i: destination) {
        cout << i << " ";
    }

    cout << endl;
    cout << "-----------------------------" << endl;

    vector<int> nums = {1,2,3,4,5};
    set<float> floats = {1.5, 3.2};

    copy_if(nums.begin(), nums.end(), inserter(floats, floats.begin()), [](int x) {return x % 2 == 0;});

    for (auto i: floats) {
        cout << i << " ";
    }

    // std::find, cbegin(), cend()



    return 0;
}