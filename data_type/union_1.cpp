#include <iostream>

using namespace std;

// Union: user-defined type where all members share the same memory location
// Only one member is valid and active at any given time.
// Alignment by the strictest alignment requirement among its member
// Memory efficiency: only one member’s storage is needed.
// Type reinterpretation: unions are sometimes used to look at the same bytes as different types

// Reference:

union Data {
    int i; // Alignment 4
    float f; // Alignment 4
    char c; // Alignment 1
};

int main() {

    // The size of a union equals to the size of its largest member
    Data d;

    d.i = 42; // Alignment 4(Byte) & Type representation: int

    cout << "d.i = " << d.i << endl; // Valid member
    cout << "d.f = " << d.f << endl; // Not valid member with a garbage value (Undefined behavior)

    d.f = 3.14f; // Alignment 4(Byte) & Type representation: int
    cout << "d.f = " << d.f << endl;
    cout << "d.i = " << d.i << endl;

    d.c = 'A';
    cout << "d.c = " << d.c << endl;
    cout << "d.i = " << d.i << endl;

    return 0;
}