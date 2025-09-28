#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;

void increment(int id) {
    for (int i = 0; i < 10; i++) {
        lock_guard<mutex> lock(mtx);
        ++counter;
    }
}

int main() {
    jthread t1(increment, 1);
    jthread t2(increment, 2);

    cout << "Final counter = " << counter << endl;
}
