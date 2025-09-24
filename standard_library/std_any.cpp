#include <any>
#include <iostream>
#include <string>

using namespace std;

// 'any' since C++17: Useful when the type is not known at compile time
// Throws std::bad_any_cast when it's a wrong type

int main() {

    any a = 42; // A type-safe box that can hold one value of any copy-constructible type(a new object by copying an existing one)
    cout << any_cast<int>(a) << endl; // Extracting the value as as int. If the held type is not int(meaning current type), it throws bad_any_cast

    a = string("Hello World!");
    cout << any_cast<string>(a) << endl;

    if (a.type() == typeid(string)) {
        cout << "string type" << endl;
    }

    return 0;
}