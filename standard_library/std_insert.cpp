#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {

    vector<int> vec = {1, 2, 4, 5};

    vec.insert(vec.begin() + 2, 300);
    vec.insert(vec.end(), 100);

    for (int v: vec) {
        cout << v << " ";
    }

    cout << endl;
    cout << "------------------------------------------" << endl;

    // Concatenating multiple vectors
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4, 5, 6};
    vector<int> vec3 = {7, 8, 9};
    vector<int> vec4 = {10, 11, 12};

    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    vec1.insert(vec1.end(), vec3.begin(), vec3.end());

    cout << "vec1 + vec2 + vec3" << endl;

    for (int v: vec1) {
        cout << v << " ";
    }

    cout << endl;
    vec1.insert(vec1.end(), make_move_iterator(vec4.begin()), make_move_iterator(vec4.end()));

    for (int v: vec1) {
        cout << v << " ";
    }

    cout << endl;
    cout << "vec 4";
    cout << endl;

    for (int v: vec4) {
        // vec4 keeps original elements since 'move' almost equals to 'copy'
        // Primitive types are same -> int, double, char etc..
        cout << v << " ";
    }
    cout << endl;

    cout << "------------------------------------------" << endl;

    // in the string type
    vector<string> fruits = {"apple", "banana", "cherry"};
    vector<string> temp;

    temp.insert(temp.end(), make_move_iterator(fruits.begin()), make_move_iterator(fruits.end()));

    for (string f: fruits) {
        cout << f << " ";
    }

    cout << endl;

    for (string f: temp) {
        cout << f << " ";
    }

    cout << endl;

    cout << "------------------------------------------" << endl;

    // Insert used in Set & Map
    unordered_set<string> set1 = {"a", "b", "c"};
    unordered_set<string> set2 = {"a", "d", "e", "f"};

    set1.insert(set2.begin(), set2.end());

    for (string s: set1) {
        cout << s << " ";
    }

    return 0;
}