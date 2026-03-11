#include <cassert>
#include <iostream>
#include <unistd.h>
#include <cstdio>

using namespace std;

// "Process layer"
// code: assembly code
// data: global variable, static variable
// heap: malloc, new
// stack: calling functions, local variable

void* heap_start = nullptr;
void* heap_end = nullptr;

void* extend_heap(size_t size) {

    // sbrk: Returning the program break address before extending the memory
    if (heap_start == nullptr) {
        heap_start = sbrk(0);
    }

    void* prev_break = sbrk(size);

    return prev_break;
}


int main() {
    // pointer variable in stack
    void* p1 = extend_heap(1024);
    void* p2 = extend_heap(512);

    assert((char*)p2 - (char*)p1 == 1024);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    return 0;
}

