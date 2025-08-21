#include <iostream>
using namespace std;

int main() {

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto &i: v1) {
        i *= 2;
    }

    for (int num: v1) {
        cout << num << " ";
    }

    cout << endl;
    for_each(v2.begin(), v2.end(), [](int &x){ x *= 5; });

    for (int num: v2) {
        cout << num << " ";
    }



    return 0;
}