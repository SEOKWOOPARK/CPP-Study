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

struct BlockHeader {
    size_t size; // 8 bytes
    bool free; // 1 byte
    // padding 7 bytes since compiler adds 7 bytes for alignment
};

void* extend_heap(size_t size) {

    // sbrk(size): Returning the program break address before extending the memory as much as 'size'
    if (heap_start == nullptr) {
        heap_start = sbrk(0);
    }

    // prev_break (old break = start of new block = start of header)
    // 'void*' just means "some address". No size, no fields, no type nothing.
    // header(metadata for corresponding data) 16bytes = sizeof(BlockHeader), data 1024bytes = size
    // [header][data] in a row, not separate.
    void* prev_break = sbrk(size + sizeof(BlockHeader));

    BlockHeader* header = (BlockHeader*)prev_break; // casting
    // Compiler needs to know the layout of memory at that address.
    // 'header' has 16 bytes size from most front of header address meaning prev_break

    header->size = size; // compiler knows where size field is
    header->free = false; // compiler knows where free field is

    heap_end = sbrk(0);

    // Returning data part to exclude header
    // + 1 = 16 bytes = sizeof(BlockHeader) = Move forward by one unit size of the pointer type
    return (void*)(header + 1);
}

// void* -> this allocator function doesn't recognize what the type comes out
void* my_malloc(size_t size) {
    // traverse blocks
    BlockHeader* current = (BlockHeader*)heap_start;

    // Keep going until we hit the end of heap and making current and heap_and the same type
    while ((void*)current < heap_end) {
        if (current->free && current->size >= size) {
            current->free = false;  // mark as used
            return (void*)(current + 1);  // return data part
        }
        // move to next block
        // Without 'char*', current->size follows just the type of 'current'. It can lead to 1024(size) * type size 16 bytes(Blockhead)
        // With 'char*', current->size follows char*. It can lead to 1024(size) * type size 1 byte(char)
        current = (BlockHeader*)((char*)(current + 1) + current->size);
    }

    // No free block found -> taking new space for the size
    return extend_heap(size);
}

void my_free(void* ptr) {
    if (ptr == nullptr) {
        return;
    }

    BlockHeader* header = (BlockHeader*)ptr - 1;

    header->free = true;
}

int main() {
    // pointer variable in stack
    void* p1 = extend_heap(1024);
    void* p2 = extend_heap(512);

    assert((char*)p2 - (char*)p1 == 1040);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    cout << "Stage 1 is over" << endl;

    cout << "----------------------------" << endl;

    BlockHeader* header = (BlockHeader*)heap_start;

    assert(header->size == 1024);
    assert(header->free == false);

    cout << "Stage 2 is over" << endl;

    cout << "----------------------------" << endl;

    void* p3 = my_malloc(1024);
    void* p4 = my_malloc(512);

    BlockHeader* h3 = (BlockHeader*)p3 - 1;
    h3->free = true;

    void* p5 = my_malloc(512);
    assert(p5 == p3);

    cout << "Stage 3 is over" << endl;

    cout << "----------------------------" << endl;

    void* p6 = my_malloc(1024);
    void* p7 = my_malloc(512);

    my_free(p6);
    BlockHeader* h6 = (BlockHeader*)p6 - 1;
    assert(h6->free == true);

    void* p8 = my_malloc(512);
    assert(p8 == p6);

    cout << "Stage 4 is over" << endl;

    return 0;
}

