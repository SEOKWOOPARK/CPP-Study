#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

// Association is when two objects know about each other, but neither owns the other.


class Patient;  // forward declaration

class Doctor {
private:
    string m_name{};
    vector<Patient*> m_patients{}; // Doctor knows about Patient by a pointer

public:
    Doctor(string_view name): m_name{name} {}

    void addPatient(Patient* patient) {
        m_patients.push_back(patient);
    }

    const string& getName() const { return m_name; }

    void listPatients() const;  // defined after Patient
};

class Patient {
private:
    string m_name{};
    Doctor* m_doctor{}; // Patient knows about Doctor by a pointer

public:
    Patient(string_view name): m_name{name} {}

    void setDoctor(Doctor* doctor) {
        m_doctor = doctor;
    }

    // The returned reference is read-only -> Caller can't change m_name through it
    const string& getName() const { return m_name; }

    // Function without modifying the object. When changing variables inside the class, compiler error can happen
    void listDoctor() const {
        if (m_doctor)
            cout << m_name << "'s doctor: " << m_doctor->getName() << endl;
    }
};

void Doctor::listPatients() const {
    cout << m_name << "'s patients: ";
    for (auto* p : m_patients)
        cout << p->getName() << " ";
    cout << endl;
}

int main() {
    Doctor gregory{"Gregory"};

    Patient alice{"Alice"};
    Patient bob{"Bob"};

    gregory.addPatient(&alice);
    gregory.addPatient(&bob);
    alice.setDoctor(&gregory);
    bob.setDoctor(&gregory);

    gregory.listPatients();
    alice.listDoctor();
    bob.listDoctor();

    return 0;
}