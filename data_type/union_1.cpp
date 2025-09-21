#include <iostream>

using namespace std;

union Data {
    int i;
    float f;
    char c;
};

int main() {
    Data d;

    d.i = 42;
    cout << "d.i = " << d.i << endl;
    cout << "d.f = " << d.f << endl;

    d.f = 3.14f;
    cout << "d.f = " << d.f << endl;
    cout << "d.i = " << d.i << endl;

    d.c = 'A';
    cout << "d.c = " << d.c << endl;
    cout << "d.i = " << d.c << endl;

    return 0;
}