#include <iostream>
#include <thread>
#include <mutex>

// Mutex: Synchronization primitive used to prevent multiple threads from accessing shared resources at the same time
// which could otherwise lead to race conditions and unpredictable behavior

// Race condition: Two or more threads(processes) access the same shared resource simultaneously.
// The final outcome depends on the timing or interleaving of their operations


// Reference 1(Mutex): https://en.cppreference.com/w/cpp/thread/mutex.html / https://cplusplus.com/reference/mutex/mutex/
// Reference 2(lock_guard): https://en.cppreference.com/w/cpp/thread/lock_guard.html / https://cplusplus.com/reference/mutex/lock_guard/
// Reference 2(unique_lock): https://en.cppreference.com/w/cpp/thread/unique_lock.html

// Modern Operating Systems (Andrew S. Tanenbaum)
// Linux Kernel Development (Robert Love)
// https://www.youtube.com/@silvinahanonowachman3310/videos
// Neso Academy (YouTube)
// https://www.youtube.com/@JacobSorber/videos

using namespace std;

int counter = 0; // A shared variable between all threads
mutex mtx; // Mmutex that will make sure only one thread at a time can change counter.

void increment(int id) {
    for (int i = 0; i < 10; i++) {
        // lock on entry + unlock on exit
        // If another thread is already holding the lock, the current thread waits
        // When the lock object goes out of 'for' scope, it automatically unlocks the mutex(RAII pattern)

        // From <mutex>, this is RAII (Resource Acquisition Is Initialization) wrapper.
        // This locks the mutex immediately. And, out of scope, its destructor automatically unlocks the mutex
        lock_guard<mutex> lock(mtx);

        ++counter; // critical section: where shared resources are accessed or modified -> only one thread should execute it at once to avoid race conditions
    }
}

int main() { // The thread for main works when compiling and build is over
    // Since each increment is protected, no two threads can increment 'counter' at the exact same time
    thread t1(increment, 1); // thread 1 is running
    thread t2(increment, 2); // thread 2 is running

    t1.join(); // The thread for main waits for t1 thread until t1 is completely done
    t2.join(); // The thread for main waits for t2 thread until t2 is completely done

    cout << "Final counter = " << counter << endl;
}
