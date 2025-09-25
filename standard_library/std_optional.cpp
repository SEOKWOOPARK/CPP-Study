#include <optional>
#include <iostream>

using namespace std;

// optional: A lightweight object that may hold a T (engaged) or no value (disengaged) for “maybe there’s a result”.
// Replaces ad-hoc “sentinel values” (returning -1), output parameters, or nullable pointers
// Reference: https://en.cppreference.com/w/cpp/utility/optional.html

optional<int> find_even(int x) {
    if (x % 2 == 0) {
        return x;
    }

    return nullopt;
}

int main() {
    auto result = find_even(6000);

    if (result.has_value()) { // engaged case
        cout << "This is even number. And, the value has "<< *result << endl;
    }

    result = find_even(7);
    if (!result) { // disengaged case
        cout << "Not even number" << endl;
    }

    return 0;
}