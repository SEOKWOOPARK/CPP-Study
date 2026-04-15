#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// Composition is when one object owns another object as a part of itself.
// The part belongs to the whole
// The part is created and destroyed with the whole
// The part can't exist independently

class Heart {
private:
    int m_bpm{};

public:
    Heart(int bpm): m_bpm{bpm} {}

    void beat() const {
        cout << "Heart beating at " << m_bpm << " bpm" << endl;
    }
};

class Person {
private:
    string m_name{};
    Heart m_heart; //

public:
    Person(string_view name, int bpm)
        : m_name{name}, m_heart{bpm} {}

    void live() const {
        cout << m_name << ": ";
        m_heart.beat();
    }
};

int main() {
    Person alice{"Alice", 52}; // Heart is created inside alice
    alice.live();

    return 0;
}
