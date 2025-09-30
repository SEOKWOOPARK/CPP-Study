#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

// Synchronization primitive -> signaling/events between threads
// Producer-Consumer pattern

mutex mtx;
condition_variable cv;
queue<int> q;
bool done = false;

void producer() {
    for (int i = 0; i < 10; i++) {
        {
            lock_guard<mutex> lock(mtx);
            q.push(i);
            cout << "Produced " << i << endl;
        }
        cv.notify_one();
    }
    {
        lock_guard<mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{ return !q.empty() || done; });

        if (!q.empty()) {
            int val = q.front();
            q.pop();
            cout << "Consumed " << val << endl;
        } else if (done) {
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

