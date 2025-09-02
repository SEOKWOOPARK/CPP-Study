#include <iostream>

using namespace std;

// Reference document1 -> https://en.cppreference.com/w/cpp/language/template_specialization.html
// Reference document2 -> https://en.cppreference.com/w/cpp/language/partial_specialization.html

// Template specialization
// Printer class with a template for general purpose
template <typename T>
class Printer {
public:
    void print(T v) {
        cout << v << endl;
    }
};

// Printer class with a template for general purpose
// <>: Delivering to compiler that it's not a new generic template and just a specialization of an existing one.

template <>
class Printer<bool> {
public:
    void print(bool v) {
        cout << (v ? "true" : "false") << endl;
    }
};

template <>
class Printer<double> {
public:
    void print(double v) {
        cout << "You entered: " << v << endl;
    }
};


int main() {

    Printer<int> printer_int;
    printer_int.print(7);

    Printer<float> printer_float;
    printer_float.print(7.5);

    Printer<string> printer_string;
    printer_string.print("hello");

    // Special case parameter 'bool'
    Printer<bool> printer_bool;
    printer_bool.print(true);

    // Special case parameter 'double'
    Printer<double> printer_double;
    printer_double.print(7.5);

    return 0;
}
