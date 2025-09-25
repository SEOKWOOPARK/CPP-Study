#include <optional>
#include <iostream>

using namespace std;

optional<int> find_even(int x) {
    if (x % 2 == 0) {
        return x;
    }

    return nullopt;
}

int main() {
    auto result = find_even(6);

    if (result) {
        cout << "This is even number. And, the value has"<< *result << endl;
    }

    result = find_even(7);
    if (!result) {
        cout << "Not even number" << endl;
    }

    return 0;
}