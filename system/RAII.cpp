#include <iostream>
#include <string>
#include <string_view>
#include <fstream>

using namespace std;

// RAII: Resource Acquisition Is Initialization.
// Tie resources like file, memory, socket or mutex to an object's lifetime


// RAII wrapper for a file
class FileHandler {
private:
    FILE* m_file{};
    string m_filename{};

public:
    FileHandler(string_view filename, string_view mode)
        : m_filename{filename} {
        m_file = fopen(filename.data(), mode.data());
        if (m_file)
            cout << "File opened: " << m_filename << endl;
        else
            cout << "Failed to open: " << m_filename << endl;
    }

    ~FileHandler() {
        if (m_file) {
            fclose(m_file);
            cout << "File closed: " << m_filename << endl;
        }
    }

    void write(string_view text) {
        if (m_file)
            fputs(text.data(), m_file);
    }

    bool isOpen() const { return m_file != nullptr; }
};

// RAII wrapper for heap memory
class Buffer {
private:
    int* m_data{};
    size_t m_size{};

public:
    Buffer(size_t size) : m_size{size} {
        m_data = new int[size];
        cout << "Buffer allocated: " << size << " ints" << endl;
    }

    ~Buffer() {
        delete[] m_data;
        cout << "Buffer freed" << endl;
    }

    int& operator[](size_t index) { return m_data[index]; }
    size_t size() const { return m_size; }
};

void riskyOperation(bool fail) {
    Buffer buf{5};          // memory acquired
    FileHandler file{"test.txt", "w"};  // file acquired

    buf[0] = 42;
    buf[1] = 100;
    file.write("Hello RAII\n");

    if (fail)
        throw runtime_error("something went wrong!");

    cout << "Operation succeeded" << endl;

    // no manual cleanup needed
    // buf and file destructors called automatically
}

int main() {
    cout << "--- Case 1: Normal execution ---" << endl;
    try {
        riskyOperation(false);
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << endl;

    cout << "--- Case 2: Exception thrown ---" << endl;
    try {
        riskyOperation(true);
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}