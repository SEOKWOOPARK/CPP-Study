#include <iostream>
#include <string>
#include <string_view>

using namespace std;

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
    const Teacher& m_teacher;
public:
    Department(const Teacher& teacher): m_teacher(teacher) {}

};

int main() {
    Teacher bob{"Bob"};

    {
        Department department{bob};
    }

    cout << bob.getName() << " Still exists!" << endl;

    return 0;
}



