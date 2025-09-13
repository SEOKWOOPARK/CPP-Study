#include <iostream>
#include <vector>

using namespace std;

void swap_values(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int& find_max_reference(vector<int>& v) {
    int max_index = 0;

    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > v[max_index]) {
            max_index = i;
        }
    }

    return v[max_index];

}

int main() {
    // Representing addresses
    int a = 42;
    int x = 11;
    int* p = &a;
    cout << p << endl; // Memory address
    cout << *p << endl; // Dereference -> access the value

    p = &x; // Pointing to memory address of 'x'
    *p = 30; // Changing x to 30
    cout << p << endl;
    cout << *p << endl;
    cout << x << endl;

    p = &a; // Pointing to memory address of 'a'
    *p = 100; // Changing x to 100
    cout << p << endl;
    cout << *p << endl;
    cout << a << endl;

    cout << "---------------------" << endl;

    // Defining references (Lvalue which refers to an existing variable)
    int b = 5;
    int& reference_b = b; // reference_b is an alias for b
    reference_b = 250;

    cout << reference_b << endl;
    cout << b << endl;
    cout << "---------------------" << endl;

    // Bitwise: When used between numbers, & means bitwise 'AND'
    int n1 = 6;
    int n2 = 3;
    int n3 = n1 & n2;
    cout << n3 << endl;

    cout << "---------------------" << endl;

    vector<int> nums = {3, 8, 1, 7, 2};
    cout << "Before: ";

    for (int n: nums) {
        cout << n << ' ';
    }

    cout << endl;

    int& max_ref = find_max_reference(nums);
    cout << max_ref << endl;

    max_ref = 99;
    cout << "After changing max: ";

    for (int n: nums) {
        cout << n << ' ';
    }

    cout << endl;

    swap_values(nums[0], nums[1]);

    for (int n: nums) {
        cout << n << ' ';
    }

    cout << endl;

    return 0;
}