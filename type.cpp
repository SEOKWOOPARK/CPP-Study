#include <iostream>

using namespace std;

int type_calculation() {
    // double pi = 3.141592653589793;
    // pi = 9.9;
    // std::cout << pi << std::endl;

    int x = 10;
    int y = ++x;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    int m = 100;
    int n = m++;

    std::cout << m << std::endl;
    std::cout << n << std::endl;

    int f = 1 + 2 * 3;
    std::cout << f << std::endl;
    return 0;
}

int main() {
    type_calculation();
    return 0;
}
