#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Dynamic binding -> Smart Pointer refers to the applicable(almost children) class
class Animal {
public:
    // Even though a destructor is defined by the 'virtual' keyword, it needs brackets {}
    // virtual ~Animal() = default; -> possible(Compiler will execute the destructor automatically)
    // virtual ~Animal() = 0; -> possible(Forcing the children class)
    virtual ~Animal() { // Run by the parents in-person
        cout << "The animal is removed" << endl;
    }

    // Pure virtual function: Forcing children to override(define) this function in-person.
    virtual void speak() = 0;

    // Normal virtual function: overriding is an option depending on children
    virtual void listen() {
        cout << "The animal is listening to something" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "The dog is speaking something" << endl;
    }

    ~Dog() {
        cout << "The dog is removed" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "The cat is speaking something" << endl;
    }

    ~Cat() {
        cout << "The cat is removed" << endl;
    }
};

// ------------------------------------------------------------
// Static binding -> Smart Pointer refers to the parents class

class Country {
public:
    void speak() {
        cout << "The country is speaking something" << endl;
    }
    ~Country() {
        cout << "The country is removed" << endl;
    }
};

class USA : public Country{
public:
    void speak() {
        cout << "The USA is speaking something" << endl;
    }
    ~USA() {
        cout << "The USA is removed" << endl;
    }
};

class Japan : public Country{
public:
    void speak() {
        cout << "The Japan is speaking something" << endl;
    }
    ~Japan() {
        cout << "The Japan is removed" << endl;
    }
};

int main() {
    vector<unique_ptr<Animal>> zoo;
    zoo.push_back(make_unique<Cat>());
    zoo.push_back(make_unique<Dog>());

    for (const auto& animal : zoo) {
        animal -> speak();
    }

    cout << "------------------------------------------" << endl;

    vector<unique_ptr<Country>> countries;
    countries.push_back(make_unique<USA>());
    countries.push_back(make_unique<Japan>());

    for (const auto& country : countries) {
        country -> speak();
    }

    return 0;
}