#include <iostream>
#include <thread>
#include <atomic>
#include <cassert>

using namespace std;

atomic<int> counter(0);

// CAS: Compare-And-Swap
void cas_increment(int n) {
    for (int i = 0; i < n; i++) {
        int old = counter.load(memory_order_relaxed);

        while (!counter.compare_exchange_weak(old, old + 1, memory_order_acq_rel, memory_order_relaxed))
        {}

    }
}

int main() {
    vector<thread> threads;

    for (int i = 0; i < 8; ++i) {
        threads.emplace_back(cas_increment, 250'000);
    }

    for (auto& t: threads) {
        t.join();
    }

    assert(counter.load() == 2'000'000);
}