#include <iostream>

using namespace std;

int main() {

    int *x_pointer = nullptr;
    int *y_pointer = nullptr;
    int x = 1;

    x_pointer = &x;

    if (x_pointer == nullptr) {
        cout << "x_pointer is null" << endl;
    } else {
        cout << "x_pointer is assigned" << endl;
    }


    if (y_pointer == nullptr) {
        cout << "y_pointer is null" << endl;
    } else {
        cout << "y_pointer is assigned" << endl;
    }





    return 0;
}