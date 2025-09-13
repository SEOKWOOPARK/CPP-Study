#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

int main() {
    double x = -3.8;
    double y = 12.5;
    double angle = numbers::pi / 4;
    cout << angle << endl;

    cout << "Absolute value of x is " << abs(x) << endl;
    cout << "Absolute value of y is " << abs(y) << endl;

    cout << "Square root of x is " << sqrt(x) << endl;
    cout << "Square root of y is " << sqrt(y) << endl;

    cout << "pow(x, 3) = " << pow(x, 3) << endl;
    cout << "pow(y, 3) = " << pow(y, 3) << endl;

    cout << "Exponent of x is " << exp(x) << endl;
    cout << "Exponent of y is " << exp(y) << endl;

    cout << "Sin(45 deg) = " << sin(angle) << endl;
    cout << "Cos(45 deg) = " << cos(angle) << endl;
    cout << "Tan(45 deg) = " << tan(angle) << endl;
    cout << "Tanh(45 deg) = " << tanh(angle) << endl;

    cout << "Ceil(x) = " << ceil(x) << endl;
    cout << "Ceil(y) = " << ceil(y) << endl;

    cout << "Floor(x) = " << floor(x) << endl;
    cout << "Floor(y) = " << floor(y) << endl;

    cout << "Trunc(x) = " << trunc(x) << endl;
    cout << "Trunc(y) = " << trunc(y) << endl;

    return 0;

}