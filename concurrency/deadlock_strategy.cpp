#include <mutex>
#include <thread>
#include <vector>
#include <iostream>

using namespace std;

// RAII(Resource Acquisition Is Initialization)
// An RAII lock that can lock one or more mutexes at once, without deadlock



struct Account {
    // mutex m in the Account struct is the lock that protects the balance variable
    // from being accessed by multiple threads at the same time
    mutex m;
    int balance = 0;
};

void transfer(Account & from, Account & to, int amount) {
    // from.m & to.m -> They should be managed at the same time for concurrency
    // Available for protecting operations
    scoped_lock lock(from.m, to.m);
    from.balance -= amount;
    to.balance += amount;
}

int main() {
    Account a, b;
    a.balance = 100000;
    b.balance = 0;

    vector<thread> threads;

    for (int i = 0; i < 100; i++) {
        threads.emplace_back(transfer, ref(a), ref(b), 100);
        threads.emplace_back(transfer, ref(b), ref(a), 100);
    }

    for (auto & thread: threads) {
        thread.join();
    }

    cout << a.balance << " " << b.balance << endl;
}