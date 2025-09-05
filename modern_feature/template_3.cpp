#include <iostream>
#include <Eigen/Dense>
#include <map>
using namespace Eigen;
using namespace std;

// Variadic template: To take any number of argument
// Reference document -> https://en.cppreference.com/w/cpp/language/parameter_pack.html
template <typename... Args>
void printAll(Args... args) {
    (cout << ... << args) << endl;
}

// Template Alias1: Providing shortcuts for long template names
// Reference document -> https://en.cppreference.com/w/cpp/language/type_alias.html
template <typename T>
using vec_size_3 = array<T, 3>;

// Template Alias2: Using Mat 3d
using Mat3d = Eigen::Matrix<double, 3, 3>;
using Vec3d = Eigen::Matrix<double, 3, 1>;

// Template Alias3: Default template args
template <typename T>
using StringMap = map<string, T>;

int main() {
    printAll("Hello World! ", 3, " ", true, " ", 3.5);

    vec_size_3<float> point = {1.1, 2.2, 3.3};
    cout << point[0] << " " << point[1] << " " << point[2] << endl;
    cout << "---------------------" << endl;

    Vec3d v(1, 2, 3);
    Mat3d I = Mat3d::Identity();
    cout << "I equals to \n" << I << endl;
    cout << "v equals to \n" << v << endl;

    cout << "---------------------" << endl;
    StringMap<int> ages;
    ages["John"] = 50;
    ages["Ali"] = 30;
    ages["Chris"] = 400;

    for (auto& [key, value]: ages) {
        cout << key << ": " << value << endl;
    }

}

