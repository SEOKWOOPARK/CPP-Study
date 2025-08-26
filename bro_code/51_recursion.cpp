#include <iostream>

using namespace std;

// Stack overflow in Wikipedia.
// In software, a stack overflow occurs if the call stack pointer exceeds the stack bound.

int factorial(int num) {
    if (num > 1) {
        return num * factorial(num - 1);
    }

    return 1;
}

int main() {
    cout << factorial(14) << endl;
    return 0;
}