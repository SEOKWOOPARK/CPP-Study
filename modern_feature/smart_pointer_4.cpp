#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Reference 1: https://en.cppreference.com/w/cpp/memory/unique_ptr/get
// Reference 2: https://en.cppreference.com/w/cpp/memory/unique_ptr/release
using namespace std;

class Animal {
public:
    virtual ~Animal() {
        cout << "Destructor: Animal part is removed from memory" << endl;
    }

    // Pure Virtual Function: Forces children classes to implement speak()
    virtual void speak() = 0;
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog is speaking" << endl;
    }

    ~Dog() {
        cout << "Dog is removed first" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat is speaking" << endl;
    }
    ~Cat() {
        cout << "Cat is removed first" << endl;
    }
};

int main() {
    unique_ptr<Animal> dog = std::make_unique<Dog>();

    // 'get' : Getting the raw address without taking ownership
    Animal* animal_dog = dog.get();
    cout << animal_dog << endl;
    animal_dog->speak();

    vector<unique_ptr<Animal>> zoo;

    // Transferring ownership from myDog to the zoo vector
    // After this, dog becomes a 'null' pointer
    zoo.push_back(std::move(dog));
    zoo.push_back(make_unique<Cat>());

    if (dog == nullptr) {
        cout << "dog is now empty. Ownership moved to the zoo" << endl;
    }

    cout << "-----------------------------------------" << endl;

    for (const auto& animal : zoo) {
        animal->speak();
    }

    cout << "-----------------------------------------" << endl;

    // animal_dog is still alive since the address of Dog is not changed after transferring the ownership
    animal_dog->speak();

    cout << "-----------------------------------------" << endl;

    // As 'zoo' goes out of scope, it triggers the deletion of all contained objects.
    // Thanks to 'virtual' destructor, children and parents are deleted together!
    cout << "Scope is over" << endl;

    return 0;
}