#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

// Synchronization primitive -> signaling/events between threads
// Mutex(mutual exclusion: only one thread can enter a critical section at once)
// Producer(Pushing data a queue) <-> Consumer(Popping data from a queue as soon as each producer trial is over)
// Reference1: https://en.cppreference.com/w/cpp/thread/condition_variable.html
// Reference2: https://wiki.sei.cmu.edu/confluence/display/cplusplus/CON54-CPP.%2BWrap%2Bfunctions%2Bthat%2Bcan%2Bspuriously%2Bwake%2Bup%2Bin%2Ba%2Bloop

// condition_variable: letting one or more threads wait until a certain condition is satisfied.
// The thread responsible for the condition notify them once the condition is over.
// This must always be used together with a mutex for correctness.

mutex mtx; // single mutex protecting all shared state below
condition_variable cv; // condition variable used to signal state changes
queue<int> q; // shared queue: producer pushes, consumer pops
bool done = false;

void producer() {
    for (int i = 0; i < 10; i++) {
        {
            lock_guard<mutex> lock(mtx);
            q.push(i);
            cout << "Produced " << i << endl;
        }
        cv.notify_one(); // wake one waiting consumer; lock is already released
    }
    // lock_guard goes out of scope → unlocks

    {
        lock_guard<mutex> lock(mtx); // acquiring the mutex one more time
        done = true; // update shared state: production finished
    }
    // unlock from this line
    cv.notify_all(); // wake all waiters so they can observe done
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx); // acquiring the mutex

        // atomically: release lock and sleep
        // when notified, re-acquire lock
        // re-check predicate to guard spurious(fake) wakeup
        cv.wait(lock, []{ return !q.empty() || done; });

        if (!q.empty()) {
            int val = q.front(); // read fron item under lock
            q.pop();
            cout << "Consumed " << val << endl;
            // lock is released at end of scope; loop repeats to consume more
        } else if (done) { // no item and production finished → exit loop
            break;
        }
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
}

