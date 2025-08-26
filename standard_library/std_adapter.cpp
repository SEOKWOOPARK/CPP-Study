#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

// Adapter: Stack, Queue, Priority Queue

int main() {
    // Queue
    queue<int> q1;
    q1.push(2); // Adding Number
    q1.push(20);
    q1.push(200);

    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }

    cout << endl;
    cout << "------------------------" << endl;

    // Stack
    stack<int> s1;
    s1.push(5);
    s1.push(50);
    s1.push(500);

    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }

    cout << endl;
    cout << "------------------------" << endl;

    // Priority Queue -> pop based on the max value
    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(200);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }



    return 0;
}