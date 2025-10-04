#include <iostream>
#include <thread>
#include <atomic>
#include <cassert>

using namespace std;

// Atomic operation without Mutex
// Testing whether multiple threads can safely and correctly increment a shared 'counter variable' exactly 2M times total without race conditions

// atomic integer -> Not interleaving from other threads
atomic<int> counter(0);

// CAS: Compare-And-Swap
void cas_increment(int n) {
    for (int i = 0; i < n; i++) {
        // load reads the current value of counter without synchronization cost
        // the operation is atomic, but no ordering or synchronization is guaranteed with respect to other operations
        // => The read or write itself is safe and atomic (no partial updates). But the compiler and CPU are free to reorder it around other reads/writes.
        int old = counter.load(memory_order_relaxed);

        // compare_exchange_weak(expected, desired, ...)
        while (!counter.compare_exchange_weak(old, old + 1, memory_order_acq_rel, memory_order_relaxed))
        {}
    }
}

int main() {
    vector<thread> threads;

    // 8 threads
    for (int i = 0; i < 8; ++i) {
        threads.emplace_back(cas_increment, 250'000);
    }

    for (auto& t: threads) { // threads are working in parallel
        t.join(); // waiting for all threads to finish before continuing
    }

    assert(counter.load() == 2'000'000);
}