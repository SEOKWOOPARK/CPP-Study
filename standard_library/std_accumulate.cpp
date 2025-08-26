#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v1 = {1,2,3,4,5};
    int sum1 = accumulate(v1.begin(), v1.end(), 0); // Adding sum to 0
    int sum2 = accumulate(v1.begin(), v1.end(), 10); // Adding sum to 10
    int sum3 = accumulate(v1.begin(), v1.end(), 0.0); // Warning -> The initial value should have the same type from the returned value

    cout << "sum1 is " << sum1 << endl;
    cout << "sum2 is " << sum2 << endl;
    cout << "sum3 is " << sum3 << endl;

    vector<double> v2 = {1.0, 2.0, 3.0, 4.0};
    double sum4 = accumulate(v2.begin(), v2.end(), 0.0);

    cout << "sum4 is " << sum4 << endl;

    double v2_mean = accumulate(v2.begin(), v2.end(), 0.0) / v2.size();
    cout << "v2_mean is " << v2_mean << endl;

    // Getting min, max in a vector
    vector<int> v3 = {3, 1, 4, 1, 5, 90, 2, 6, 5, 3, 5};
    int v3_max_value = accumulate(v3.begin(), v3.end(), v3[0], [](int x, int y) {return max(x, y);});
    int v3_min_value = accumulate(v3.begin(), v3.end(), v3[0], [](int x, int y) {return min(x, y);});

    vector<int> v4 = {3, 1, 4, 1, 5, 90, 2, 6, 5, 3, 5, -3};
    int v4_max_value = accumulate(v4.begin(), v4.end(), v4[0], [](int x, int y) {return x > y ? x : y; });
    int v4_min_value = accumulate(v4.begin(), v4.end(), v4[0], [](int x, int y) {return x < y ? x : y;});

    cout << "v3_max_value is " << v3_max_value << endl;
    cout << "v3_min_value is " << v3_min_value << endl;
    cout << "v4_max_value is " << v4_max_value << endl;
    cout << "v4_min_value is " << v4_min_value << endl;
    cout << "---------------------------------------------" << endl;

    


    return 0;
}