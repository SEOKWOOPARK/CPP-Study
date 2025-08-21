#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v1 = {1,2,3,4,5,6};

    auto new_end = remove_if(v1.begin(), v1.end(), [](int x) { return x % 2 == 0; });
    // v = {1, 3, 5, 4, 5, 6}
    // Valid up to tie first 5
    // new_end: the index of 4
    // 4, 5, 6 -> Garbage section which doesn't match the lambda function

    // Removing invalid ones == Reducing the vector size
    v1.erase(new_end, v1.end());

    for (int v: v1) {
        cout << v << endl;
    }

    return 0;
}