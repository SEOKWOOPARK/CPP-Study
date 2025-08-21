// 41. Multidimensional arrays
#include <iostream>

using namespace std;

int main() {
    string cars[][3] = {{"car00", "car01", "car02"}, {"car10", "car11", "car12"}};

    int rows = sizeof(cars) / sizeof(cars[0]);
    int cols = sizeof(cars[0]) / sizeof(cars[0][0]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << cars[i][j] << " ";
        }
        cout << endl;
    }
}