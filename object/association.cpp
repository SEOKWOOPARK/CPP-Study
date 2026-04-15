#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Patient;  // forward declaration

class Doctor {
private:
    string m_name{};
    vector<Patient*> m_patients{};

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
    Doctor* m_doctor{};

public:
    Patient(string_view name): m_name{name} {}

    void setDoctor(Doctor* doctor) {
        m_doctor = doctor;
    }

    const string& getName() const { return m_name; }

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