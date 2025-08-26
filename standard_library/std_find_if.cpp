#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    // find_if: finding the first corresponding element in a container
    // This doesn't require '=' in lambda necessarily
    vector<int> v = {1,2,3,4,5,7,10};
    auto target = find_if(v.begin(), v.end(), [](int i){return i > 6;});

    if (target != v.end()) {
        cout << "First element greater than 6: " << *target << endl;
    }

    cout << endl;

    cout << "--------------------------------" << endl;

    // find -> Comparing the 'value' directly and finding the first one with the value
    // end() -> Function to indicate the next one of the last element
    vector<int> test1 = {1, 3, 5, 7};
    auto it1 = find(test1.begin(), test1.end(), 5);

    if (it1 != test1.end()) {
        cout << "Found: " << *it1 << endl;
    }

    cout << "--------------------------------" << endl;

    // find_if -> Returning the first element corresponding to a condition
    vector<int> test2 = {20, 30, 40, 41, 55};

    auto it2 = find_if(test2.begin(), test2.end(), [](int x) { return x > 29; });

    if (it2 != test2.end()) {
        cout << "Found: " << *it2 << endl;
    }

    cout << "--------------------------------" << endl;

    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charse", 35}
    };

    int target_age = 25;

    auto it3 = find_if(people.begin(), people.end(), [target_age](const Person& p) {
        return p.age == target_age;
    });

    if (it3 != people.end()) {
        cout << "Found" << it3 -> name<< " is " << it3 -> age << " years old." << endl;
    } else {
        cout << "Not found with age " << target_age << endl;
    }


    return 0;
}