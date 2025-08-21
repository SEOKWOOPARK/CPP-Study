#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int age;
};

int main() {

    // replacing elements with new_value
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    replace_if(v1.begin(), v1.end(), [](int x) { return x % 2 == 0;}, -100);

    for (int v: v1) {
        cout << v << " ";
    }
    cout << endl;

    cout << "--------------------------------" << endl;

    vector<Person> people = {
        {"Alice", 20},
        {"Bob", 30},
        {"Charlie", 40},
        {"David", 25}
    };

    replace_if(people.begin(), people.end(), [](const Person& p) { return p.age >= 30;},
        Person{"Old person", 0});

    for (auto& p: people) {
        cout << p.name << " " << p.age << endl;
    }

    return 0;
}