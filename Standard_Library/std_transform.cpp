#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    vector<int> destination;

    destination.resize(v.size() + 2, -5);
    std::transform(v.begin(), v.end(), destination.begin(), [](int x) { return x * x; });

    for (int num: destination) {
        cout << num << endl;
    }

    cout << endl;

    // Applying 'transform' to 'itself'
    // 'destination' should be bigger than 'v'
    std::transform(destination.begin(), destination.end(), destination.begin(), [](int x) {return x * x;});

    for (int num: destination) {
        cout << num << endl;
    }


    cout << "----------------------------" << endl;




    return 0;
}