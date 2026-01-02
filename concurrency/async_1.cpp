#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

// Reference URL1: https://en.cppreference.com/w/cpp/thread/async.html
// Reference URL2: https://cplusplus.com/reference/future/async/
// Reference URL3: https://en.cppreference.com/w/cpp/thread/async.html
// Reference URL3: https://cplusplus.com/reference/thread/this_thread/sleep_for

// Example function to simulate heavy asynchronous data processing
long long process_data(const vector<int>& data)
{
    long long product_sum = 1;
    const long long MOD = 1000000007;

    cout << "[Async Task] Processing started on " << data.size() << " elements.\n";

    // Simulate heavy work that takes 2.5 seconds
    this_thread::sleep_for(chrono::milliseconds(2500));

    for (int x : data)
    {
        product_sum = (product_sum * (x + 1)) % MOD;
    }

    cout << "[Async Task] Processing finished.\n";

    return product_sum;
}

int main()
{
    auto start_time = chrono::high_resolution_clock::now();
    vector<int> large_data(50000, 2);
    cout << ">>> Main thread starting asynchronous task.\n";
    future<long long> future_result = async(process_data, large_data);

    // Main thread performs its own work concurrently
    cout << ">>> Main thread is busy doing something else (waiting 1 second)...\n";

    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << ">>> Main thread finished its independent task.\n";
    cout << ">>> Waiting for the async result using future.get().\n";

    // Wait for and retrieve the result (blocking call)
    long long final_result = future_result.get();

    cout << "Final Result from Async Task: " << final_result << "\n";

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "Required time: " << duration.count() << " ms.\n";

    return 0;
}