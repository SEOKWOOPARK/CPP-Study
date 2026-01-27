#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Animal {
public:
    virtual ~Animal() {
        cout << "Destructor: Animal part is removed from memory" << endl;
    }

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

    Animal* animal_dog = dog.get();
    cout << animal_dog << endl;
    animal_dog->speak();

    vector<unique_ptr<Animal>> zoo;

    zoo.push_back(std::move(dog));
    zoo.push_back(make_unique<Cat>());

    if (dog == nullptr) {
        cout << "dog is now empty. Ownership moved to the zoo" << endl;
    }

    for (const auto& animal : zoo) {
        animal->speak();
    }

    cout << "Scope is over" << endl;

    return 0;
}