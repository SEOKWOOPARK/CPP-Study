#include <vector>
#include <iostream>
// #include <array>
#include <map>
#include <cstddef>

using namespace std;

// Reference(Range-based for): https://en.cppreference.com/w/cpp/language/range-for.html
// Reference(auto): https://en.cppreference.com/w/cpp/language/auto.html
// Reference(Structured binding): https://en.cppreference.com/w/cpp/language/structured_binding.html

constexpr int square(int x) {
    return x * x;
}

template <size_t N, size_t... I>
constexpr std::array<int, N> make_iota_array_impl(std::index_sequence<I...>) {
    return { static_cast<int>(I)... };
}

template <size_t N>
constexpr std::array<int, N> iota_array() {
    return make_iota_array_impl<N>(std::make_index_sequence<N>{});
}

int main() {
    // Topic 1: Range-based for

    vector<int> v1 = {1,2,3,4,5};

    for (int x: v1) {
        cout << x << ' ';
    }

    cout << endl;

    // By copying
    // x is a copy of each element from v -> x doesn't change
    for (int x: v1) {
        x *= 2;
    }

    // By reference (modify in place)
    // x is a reference to each element of v
    // Any modification to x directly changes the element inside the container -> No copying + efficient
    for (int& x: v1) {
        x *= 2;
    }

    // const reference is just read-only. Not possible to make a copy and to modify
    // Useful for large objects like string or Eigen::Matrix where copying would be expensive
    for (const int& x: v1) {
        cout << x << ' ';
    }

    cout << endl;
    cout << "------------------------" << endl;

    // Topic 2: auto (type deduction)

    map<string, int> m1 = {{"one", 1}, {"two", 2}};

    // explicit iterator type
    for (map<string, int>::iterator it = m1.begin(); it != m1.end(); ++it) {
        cout << it -> first << ' ' << it -> second << endl;
    }

    // Using auto -> Let the compiter infer types.
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        cout << it -> first << ' ' << it -> second << endl;
    }

    cout << "------------------------" << endl;

    // Structured binding

    map<string, int> m2 = {{"Alice", 20}, {"John", 15}};

    // Decompose key, value while iterating
    for (auto& [name, age]: m2) {
        cout << name << " is " << age << endl;
        age += 1; // modifying the reference value by adding 1
    }

    for (const auto& [name, age]: m2) {
        cout << name << " is " << age << endl;
    }

    cout << "------------------------" << endl;

    // Topic 3: constexpr
    // This marks a variable or function as being eligible for compile-time evaluation
    // When inputs are constant expressions -> the result would be computed at compile time

    // If the inpputs are now kno

    constexpr int a = square(5); // Precomputed in compile time
    int b = 7;
    int c = square(b); // It can be only computed in run time since input b is assigned in run time

    std::cout << a << ' ' << b << ' ' << c << endl;

    constexpr array<int, 5> arr = iota_array<5>();
    static_assert(arr[4] == 4);
    std::cout << "arr[4] is: " << arr[4] << std::endl;

    return 0;
}