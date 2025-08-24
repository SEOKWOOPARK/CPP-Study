#include <iostream>
#include <set>
#include <map>

using namespace std;

// Associative container: Automatically sorted, balanced tree-based, Red - black tree
// Implemented with a balanced binary search tree
// Lookup, insertion, deletion -> Average O(log N)

int main() {
    // Set -> Removing duplicate values and leaving just one unique data
    set<int> s1 = {1, 2, 3, 3, 3, 3, 3};

    for (int n: s1) {
        cout << n << " ";
    }

    cout << endl;

    s1.insert(10);
    s1.insert(10);

    for (int n: s1) {
        cout << n << " ";
    }

    cout << endl;
    cout << "----------------------" << endl;

    // Multiset: Allowing duplicates
    multiset<int> s2 = {1, 2, 3, 3, 3, 3, 3};
    s2.insert(10);
    s2.insert(10);

    for (int n: s2) {
        cout << n << " ";
    }

    cout << endl;
    cout << "----------------------" << endl;

    // Map -> (Key, value) & sorted by each key
    map<string, int> m1 = {{"one", 1}, {"two", 2}};
    m1["three"] = 3;
    m1["four"] = 4;
    m1.insert({"five", 5});

    for (const auto& pair: m1) {
        cout << pair.first << " = " << pair.second << endl;
    }

    m1.erase("three");

    cout << "Deleting" << endl;

    for (const auto& pair: m1) {
        cout << pair.first << " = " << pair.second << endl;
    }

    cout << "----------------------" << endl;

    // Multimap: Allowing duplicate keys
    multimap<string, int> m2 = {{"one", 1}, {"two", 2}};
    m2.insert({"one", 1});
    m2.insert({"one", 11});
    m2.insert({"two", 2});
    m2.insert({"two", 22});

    for (const auto& pair: m2) {
        cout << pair.first << " = " << pair.second << endl;
    }

    cout << "After deleting 'one' key" << endl;

    m2.erase("one");

    for (const auto& pair: m2) {
        cout << pair.first << " = " << pair.second << endl;
    }

    return 0;
}