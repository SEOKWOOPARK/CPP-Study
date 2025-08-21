#include <iostream>
#include <algorithm>

using namespace std;

// Polymorphism - Compile(Overloading), Runtime(Overriding)

struct Printer {
    void print(int x, int y) {
        cout << "Int is " << x << endl;
        cout << "Int is " << y << endl;
        cout << "Sum is " << x + y << endl;
    }

    void print(double d) {
        cout << "Float is "<< d << endl;
    }

    void print(const string& s) {
        cout << "String is "<< s << endl;
    }
};

struct Animal {
    virtual void speak() {
        cout << "Animal's sound" << endl;
    }
};

struct Dog: Animal {
    void speak() override {
        cout << "Dog's sound" << endl;
    }
};

struct Cat: Animal {
    void speak() override {
        cout << "Cat's sound" << endl;
    }
};

int main() {
    // Compile(Overloading)
    Printer p1;
    p1.print(100, 20);
    p1.print(20.5);
    p1.print("C++");

    cout << "------------------------" << endl;

    // Runtime(Overriding)
    Animal* d = new Dog();
    Animal* c = new Cat();

    d -> speak();
    c -> speak();

    delete d;
    delete c;

    return 0;
}