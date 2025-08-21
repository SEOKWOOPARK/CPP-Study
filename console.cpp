#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace  std;

int console() {
    double sales = 95000;

    const double state_tax_rate = .04;
    double state_tax = sales * state_tax_rate;
    cout << state_tax << endl;

    // ------------------------------------------

    // cout << "Enter values for x and y: ";
    // double x;
    // double y;
    // cin >> x >> y;
    // cout << x << endl;
    // cout << y << endl;
    // cout << x * y << endl;
    // cout << x / y << endl;

    // ------------------------------------------

    double p = pow(3, 5);
    // cout << p << endl;
    double price = 99.99;
    float interest = 3.67f;
    long file_size = 900L;
    char letter = 'A';
    auto c = 1000;

    double n = pow(3, 2);
    int arr[4] = {43,2,52,64};
    // cout << arr[0] << endl;

    // ------------------------------------------

    long elapsed_seconds = time(0); // 1970 Jan
    srand(elapsed_seconds);

    int random = rand() % 10;
    cout << random << endl;
    cout << elapsed_seconds << endl;
    // ------------------------------------------

    const short min_value = 1;
    const short max_value = 13;
    srand(time(0));
    short first = (rand() %  (max_value - min_value)) + min_value;
    short second = (rand() %  (max_value - min_value)) + min_value;

    cout << first << ", " << second << endl;


}

int main() {
    console();
    return 0;
}
