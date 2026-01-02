#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;
// "--------------------------------------------"
// Quiz1

int task_a()
{
    this_thread::sleep_for(chrono::milliseconds(1500));
    return 1;
}

int task_b()
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    return 2;
}

// "--------------------------------------------"
// Quiz2

int long_task()
{
    cout << "Heavy calculation started (3.0s)" << endl;
    this_thread::sleep_for(3s);
    cout << "Heavy calculation finished" << endl;
    return 10;
}

// "--------------------------------------------"

int main()
{
    auto start_time = chrono::high_resolution_clock::now();
    future<int> future_a = async(launch::async, task_a);
    future<int> future_b = async(launch::async, task_b);

    future_a.get();
    future_b.get();

    auto end_time = chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end_time - start_time;

    cout << difference.count() << endl;
    cout << "--------------------------------------------" << endl;

    future<int> future_c = async(launch::async, long_task);
    int check_count = 0;
    auto start_time2 = chrono::high_resolution_clock::now();

    while (true)
    {
        check_count++;
        cout << "Check count is : " << check_count << "Waiting 1s" << endl;

        future_status status = future_c.wait_for(1s);

        if (status == future_status::ready)
        {
            cout << "Main is ready!" << endl;
            break;
        }
    }

    int result = future_c.get();
    auto end_time2 = chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference2 = end_time2 - start_time2;
    cout << result << " -> " << difference2.count() << endl;

    return 0;
}
