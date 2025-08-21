#include <iostream>
#include <string>

using namespace std;

// Structure: user's data type including multiple different data type
// Structure's basic access: public <--> Class basic access: private
struct Person {
    // member variable
    string name;
    int age;

    // member function
    void introduce() {
        cout << "My name is " << name << endl;
        cout << "My age is " << age << endl;
    }
};

struct Parents {
    string mother = "Kathy";
    string father = "John";
    int zip_code = 1555;

    void get_family_information() {
        cout << "Mother's name is " << mother << endl;
        cout << "Father's name is " << father << endl;
        cout << "Zip code is mother" << zip_code << endl;
    }
};

struct Children: Parents {
    void get_family_information() {
        cout << "This is the polymorphism member function" << endl;
    }
}; // In terms of children, Parent's properties are public to access

class Animal {
    string name;
    int age;
};

int main() {
    Person p1;
    p1.name = "Alice";
    p1.age = 20;

    cout<< p1.name << endl;
    cout << p1.age << endl;
    p1.introduce();

    cout << "--------------------------" << endl;

    // Inheritance
    Parents parent;
    cout << parent.mother << endl;
    cout << parent.father << endl;
    cout << parent.zip_code << endl;
    parent.get_family_information();

    Children c2;
    c2.mother = "Matthew";
    c2.zip_code = 1666;

    cout << c2.mother << endl;
    cout << c2.father << endl;
    cout << c2.zip_code << endl;
    c2.get_family_information();

    cout << "--------------------------" << endl;

    Animal animal;



    return 0;
}