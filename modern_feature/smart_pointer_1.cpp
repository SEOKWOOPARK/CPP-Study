#include <iostream>
#include <memory>

using namespace std;

// Reference document1: https://en.cppreference.com/w/cpp/memory/unique_ptr.html
// Reference document2: https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared

class Dog {
public:
    // Constructor
    // Once a class is created, this would be called
    Dog() {
        cout << "A dog is created" << endl;
    }

    // Destructor
    // Once a class is destroyed, this would be called
    ~Dog() {
        cout << "The dog is removed" << endl;
    }

    void running() {
        cout << "The dog is running.." << endl;
    }
    void stop() {
        cout << "The dog is stopping now.." << endl;
    }
};

class Cat {
public:
    Cat() {
        cout << "The cat is created" << endl;
    }
    ~Cat() {
        cout << "The cat is removed" << endl;
    }

    void running() {
        cout << "The cat is running.." << endl;
    }
};

int main() {
    // Class with a smart pointer: Preventing memory leaks

    // Only one unique_ptr can manage a given object at a time
    // When the unique_ptr goes out of scope, it automatically deletes the object.
    // And, Destructor is called -> helping prevent memory leaks

    // At this point,only d1 owns Dog class object
    // 'make_unique' creates an object on the 'heap' and wraps the object inside a _unique_ptr
    // Smart Pointer would be stored in 'stack'
    unique_ptr<Dog> d1 = make_unique<Dog>();
    d1 -> running();

    // This object can only be shared by one owner. Copying it is not allowed -> 'move' to transfer ownership
    // When using a smart pointer, methods can be called by '->'
    unique_ptr<Dog> d2 = std::move(d1);
    d2 -> running();

    cout << "----------------------" << endl;

    // Class without a smart pointer -> a general class(instance) is stored in 'stack'
    // Methods of a general class can be called by '.'
    Cat c;
    c.running();


    // In the end of the scope, destructor is called.
    return 0;
}