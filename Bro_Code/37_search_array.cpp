// 37. Search an array for an element
#include <iostream>

using namespace std;

int searchArray1(int array[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }

    return -1; // setinel value
}

int searchArray2(string array[], int size, string element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            cout << "Found!!!!" << endl;
            return i;

        }
    }

    return -1; // setinel value
}

int main() {
    int numbers[] = {6,7,8,9,10,1,2,3,4,5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int index;
    int target;

    cout << "Enter element to search" << endl;
    cin >> target;

    index = searchArray1(numbers, size, target);

    if (index != -1) {
        cout << target << " is at index " << index << endl;
    }
    else {
        cout << "Element not found" << endl;
    }

    // ------------------------------------------------------------

    string foods[] = {"pizza a", "hamburger", "hotdog"};
    int size1 = sizeof(foods) / sizeof(foods[0]);
    int index1;
    string target_food;

    cout << "Enter food type: ";

    // cin: Taking just 1 word for the input
    // getline: Taking multiple words for the input
    // cin >> target_food;
    getline(cin, target_food);


    index1 = searchArray2(foods, size1, target_food);

    if (index1 != -1) {
        cout << target_food << " is at index " << index1 << endl;
    }
    else {
        cout << "Element not found" << endl;
    }


    return 0;
}
