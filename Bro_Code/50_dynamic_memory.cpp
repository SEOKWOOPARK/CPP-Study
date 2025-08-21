#include <iostream>
using namespace std;

// Memory that is allocated after the program is already compiled & running
// 'new' operator to allocate memory in the heap rather than the stack
// Useful When it is not clear how much memory is going to be used.
int main() {

    int *pNum = NULL;
    pNum = new int;
    *pNum = 21;

    cout << "address: "<< pNum << endl;
    cout << "value: " << *pNum << endl;

    delete pNum;

    char *pGrades = NULL;
    int size;

    cout << "How many grades do you want to enter?" << endl;
    cin >> size;

    pGrades = new char[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter grade " << i + 1 << endl;
        cin >> pGrades[i];
    }

    for (int i = 0; i < size; i++) {
        cout << pGrades[i] << endl;
    }

    delete[] pGrades;

    return 0;
}