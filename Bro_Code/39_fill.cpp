// 39. Fill function

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int SIZE = 10;
    string foods[SIZE];

    fill_n(foods, SIZE / 2, "Korean BBQ");
    fill_n(foods + (SIZE / 2), SIZE / 2, "Korean Sushi");


    for (string food : foods) {
        cout << food << endl;
    }

    cout << sizeof(foods) / sizeof(foods[0]) << endl;


    return 0;
}