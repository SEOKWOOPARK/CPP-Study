#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

// std::nth_element: rearranging elements a range [begin, end)
// nth_element(begin, nth, end)
// All elements before nth are less than or equal to *nth
// All elements after nth are greater than or equal to *nth
// Neither side is sorted. Only the partition guarantee holds


int main() {
    vector<int> v1 = {9, 1, 5, 3, 7, 2, 6, 60, 8, 77, 4};

    auto mid = v1.begin() + v1.size() / 2;

    nth_element(v1.begin(), mid, v1.end());

    cout << "median value: " << *mid << endl;

    cout << "----------------------" << endl;

    // Searching for top-k largest
    vector<int> v2 = {12, 5, 8, 20, 15, 7, 2, 30, 25};
    int k = 3;

    nth_element(v2.begin(), v2.begin() + k, v2.end(), greater<>{});

    cout << "Top 3 unsorted largest: ";
    for (int i = 0; i < k; i++) {
        cout << v2[i] << ' ';
    }
}