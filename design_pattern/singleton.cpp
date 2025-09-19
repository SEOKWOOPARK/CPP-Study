#include <iostream>
#include <mutex>

using namespace std;

// Reference for Singleton 1: https://en.wikipedia.org/wiki/Singleton_pattern
// Reference for Singleton 2: https://refactoring.guru/design-patterns/singleton/cpp/example
// Reference for Constructor 1: https://learn.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=msvc-170
// Reference for Constructor 2: https://en.cppreference.com/w/cpp/language/copy_constructor.html

class Singleton {
private:
    Singleton() {
        cout << "Singleton constructor" << endl;
    }

    // default: Compiler generates the default implementation of a constructor, destructor, or operator instead of writing it manually
    // When constructor is not declared by a developer, it is assigned in public
    ~Singleton() = default;

    // This line disables the copy constructor.
    // The compiler will reject any attempt to cpy the object
    // delete: prevents the functino from being called
    // const Singleton&: meaning copy constructor. Keeping the original object while generating a new object
    Singleton(const Singleton&) = delete;

    // This line disables the copy assignment operator.
    // **copy assignment operator** -> A special operator function called when an already existing object is assigned the value of another object
    // T& operator=(const T& other): Basic form
    Singleton& operator=(const Singleton&) = delete;

    // 'move constructor' is being explicitly disabled
    // **move constructor** -> allows one object to steal the resources of another temporary object (an rvalue), instead of copying
    // T(T&& other): Basic form
    // other → the actual source object you’re “moving from”
    // Without 'other' parameter, it means that 'this function exists but can never be used'
    Singleton(Singleton&&) = delete;

    // 'move assignment operator' is being explicitly disabled
    // **move assignment operator** -> assign (overwrite) an existing object with the resources of another object
    // T& operator=(T&& other): Basic form
    // other → the actual source object you’re “moving from”
    Singleton& operator=(Singleton&&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void doSomething() {
        cout << "Singleton is working" << endl;
    }
};

int main() {
    auto& s1 = Singleton::getInstance();
    auto& s2 = Singleton::getInstance();

    s1.doSomething();

    string a = "Hello";
    string b = move(a); // b takes ownership of the memory for a
    cout << a << endl;
    cout << b << endl;

    cout << "Are they same? " << boolalpha << (&s1 == &s2) << endl;
}