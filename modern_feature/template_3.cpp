#include <iostream>

using namespace std;

// Variadic template: To take any number of argument

template <typename... Args>
void printAll(Args... args) {
    (cout << ... << args) << endl;
}

// Template Aliases: Providing shortcuts for long template names
template <typename T>
using vec_size_3 = array<T, 3>;

// using Mat 3d

int main() {
    printAll("Hello World! ", 3, " ", true, " ", 3.5);

    vec_size_3<float> point = {1.1, 2.2, 3.3};
    cout << point[0] << " " << point[1] << " " << point[2] << endl;
}

