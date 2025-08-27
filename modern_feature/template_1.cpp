#include <iostream>
#include <cmath>
#include <type_traits>

using namespace std;


// Template: Allowing to write generalized to code that does not depend on specific data types.
// Reference document -> https://en.cppreference.com/w/cpp/language/templates.html

// Function Template
template <typename T>
T add (T a, T b) {
    return a + b;
}

template <typename T> // Declaring a class template with a type parameter T for instantiation like Vector2D<int> or Vector2D<double>
class Vector2D {
public: // Accessible to members, constructor and methods

    T x, y; // if T is a fundamental type like int or double, the values are not defined until setting them in person

    Vector2D(T x, T y): x(x), y(y) {} // Member(Constructor param)

    T lengthWithTemplateReturnType() {
        return sqrt(x * x + y * y);
    }

    // Use hypot for better numerical behavior and return a floating result.
    auto lengthWithAutoReturnType() const noexcept {
        using R = std::common_type<T, double>;
        return hypot(static_cast<R>(x), static_cast<R>(y));
    }
};

int main() {
    cout << "Function template" << endl;
    cout << add<int>(1, 5) << endl;
    cout << add<double>(1.0, 2.0) << endl;
    cout << add<float>(1.0, 2.0) << endl;

    cout << "--------------------------" << endl;

    cout << "Class template" << endl;
    Vector2D<int> vi = {1, 2};
    Vector2D<double> vd = Vector2D<double>(1.0, 3.0);

    cout << vi.length() << endl;
    cout << vd.length() << endl;




    return 0;
}