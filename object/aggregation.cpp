#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// Aggregation: Parent only refer to the child. Child survives even though parent's death

class Teacher {
private:
    string m_name{};

public:
    Teacher(string_view name): m_name{name} {}

    const string& getName() const {
        return m_name;
    }
};

class Department {
private:
    const Teacher& m_teacher; // reference -> no ownership
public:
    // parameter: 'Teacher' by const reference
    // Reference members must be initialized in the initializer list before {} runs
    // By the time {} starts running, all members are expected to already exist and be initialized
    // initializer list: initialize m_teacher with 'teacher'
    Department(const Teacher& teacher): m_teacher(teacher) {}

};

int main() {
    Teacher bob{"Bob"};

    {
        Department department{bob};
    } // Department is destroyed in this part.

    cout << bob.getName() << " Still exists!" << endl;

    return 0;
}



