#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    Singleton() {
        cout << "Singleton constructor" << endl;
    }

    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void doSomething() {
        cout << "Singleton is working" << endl;
    }
};

int main() {
    auto& s1 = Singleton::getInstance();
    auto& s2 = Singleton::getInstance();

    s1.doSomething();

    cout << "Are they same? " << boolalpha << (&s1 == &s2) << endl;
}