#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// std::partial_sort: sorting only the subrange [first, mid)
// The remaining [mid, last) elements are left in unspecificed order
// Internally uses a heap-based algorithm
// n = total size, k = mid - first -> O(n log k)
// Reference(https://en.cppreference.com/w/cpp/algorithm/partial_sort.html?utm_source=chatgpt.com)

int main() {
    vector<int> v1 = {9, 1, 5, 3, 7, 2, 6, 8, 4};

    cout << "Before partial sort " << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << ' ';
    }

    cout << endl;

    partial_sort(v1.begin(), v1.begin() + 7, v1.end());

    cout << "After partial sort " << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << ' ';
    }

}