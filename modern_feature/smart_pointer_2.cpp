#include <iostream>
#include <memory>

using namespace std;

// Reference document2: https://en.cppreference.com/w/cpp/memory/shared_ptr.html
// Reference document3: https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared

class Cat {
public:
    Cat() {
        cout << "The cat is created" << endl;
    }
    ~Cat() {
        cout << "The cat is removed" << endl;
    }

    void running() {
        cout << "The cat is running.." << endl;
    }
};

int main() {
    // shared_ptr: Multiple pointers can share the same object
    // When the reference count reaches 0, the object is destroyed

    shared_ptr<Cat> cat1 = make_shared<Cat>();

    // {...} braces create a new scope inside main()
    // Any variable declared inside this block will be destroyed automatically once the block ends
    // Cat2 -> it is gone after the closing brace.
    {
        shared_ptr<Cat> cat2 = cat1;
        cat2 -> running();

        // use_count: the number of shared_ptr objects owning the same resource currently
        cout << "Reference count by cat1: " << cat1.use_count() << endl;
        cout << "Reference count by cat2: " << cat2.use_count() << endl;
    }

    cout << "Reference count: " << cat1.use_count() << endl;


    return 0;
}
