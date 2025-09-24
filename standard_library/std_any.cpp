#include <any>
#include <iostream>
#include <string>

using namespace std;

int main() {

    any a = 42;
    cout << any_cast<int>(a) << endl;

    a = string("Hello World!");
    cout << any_cast<string>(a) << endl;

    if (a.type() == typeid(int)) {
        cout << "string type" << endl;
    }

    return 0;
}