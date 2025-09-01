#include <cmath>
#include <iostream>
using namespace std;

// sqrt -> the usual way to compute the length of a 2D vector. But it can lead to overflow or underflow
// When it is very large case.

// std::hypot(x, y) -> Helping to avoid overflow or underflow by scaling values before squaring. Getting safety and accuracy
// Scaling trick
// x = number, y = number, r = max(|x|, |y|), result = r * sqrt( (x / r) ** 2, (y / r) ** 2)
// r is the larger magnitude of the two.
// (x/r) and (y/r) are now scaled to values ≤ 1.
// Squaring them will never overflow or underflow.
// After computing the safe square root, multiply back by r.

// Reference document: https://en.cppreference.com/w/cpp/numeric/math/hypot?utm_source=chatgpt.com
int main() {
    double a = 1e308;
    double b = 1e308;

    cout << sqrt(a * a + b * b) << endl;
    cout << hypot(a, b) << endl;

}