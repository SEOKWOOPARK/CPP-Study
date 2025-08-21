#include <iostream>

int main() {

    int a = 3;
    int b = 5;
    int temp = a;

    a = b;
    b = temp;

    temp = 10;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << temp << std::endl;

    return 0;

}