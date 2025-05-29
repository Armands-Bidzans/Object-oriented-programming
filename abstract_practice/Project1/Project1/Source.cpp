#include <iostream>
#include <string>
using namespace std;

// Абстрактный базовый класс
class Employer {
public:
    virtual ~Employer() {}
    virtual void Print() const = 0;
};

// Класс President
class President : public Employer {
private:
    string name;
    string department;
    double salary;
    string country;
public:
    President(const string& n, const string& dept, double sal, const string& c)
        : name(n), department(dept), salary(sal), country(c) {}

    void Print() const override {
        cout << "Position: President\n";
        cout << "Name: " << name << "\n";
        cout << "Department: " << department << "\n";
        cout << "Country: " << country << "\n";
        cout << "Salary: $" << salary << "\n";
        cout << "-----------------------------\n";
    }
};

// Класс Manager
class Manager : public Employer {
private:
    string name;
    string department;
    double salary;
public:
    Manager(const string& n, const string& dept, double sal)
        : name(n), department(dept), salary(sal) {}

    void Print() const override {
        cout << "Position: Manager\n";
        cout << "Name: " << name << "\n";
        cout << "Department: " << department << "\n";
        cout << "Salary: $" << salary << "\n";
        cout << "-----------------------------\n";
    }
};

// Класс Worker
class Worker : public Employer {
private:
    string name;
    string department;
    double salary;
public:
    Worker(const string& n, const string& dept, double sal)
        : name(n), department(dept), salary(sal) {}

    void Print() const override {
        cout << "Position: Worker\n";
        cout << "Name: " << name << "\n";
        cout << "Department: " << department << "\n";
        cout << "Salary: $" << salary << "\n";
        cout << "-----------------------------\n";
    }
};

int main() {
    // Задаём, сколько какого типа сотрудников создаём
    const int numPresidents = 2;
    const int numManagers = 3;
    const int numWorkers = 4;
    const int COUNT = numPresidents + numManagers + numWorkers;

    // Списки данных для каждого типа сотрудников
    string presidentNames[numPresidents] = { "John Doe", "Alice Brown" };
    string presidentDepartments[numPresidents] = { "Executive Office", "Executive Office" };
    double presidentSalaries[numPresidents] = { 250000.0, 260000.0 };
    string presidentCountries[numPresidents] = { "USA", "Canada" };

    string managerNames[numManagers] = { "Jane Smith", "Tom Lee", "Sara Davis" };
    string managerDepartments[numManagers] = { "Sales", "Marketing", "HR" };
    double managerSalaries[numManagers] = { 90000.0, 95000.0, 92000.0 };

    string workerNames[numWorkers] = { "Bob Johnson", "Jim Beam", "Lisa Wong", "Gary Cole" };
    string workerDepartments[numWorkers] = { "Manufacturing", "Manufacturing", "Logistics", "Maintenance" };
    double workerSalaries[numWorkers] = { 45000.0, 46000.0, 44000.0, 43000.0 };

    // Массив указателей на базовый класс
    Employer* employees[COUNT];

    int idx = 0;
    // Несколько президентов
    for (int i = 0; i < numPresidents; ++i) {
        employees[idx++] = new President(
            presidentNames[i],
            presidentDepartments[i],
            presidentSalaries[i],
            presidentCountries[i]
        );
    }
    // Несколько менеджеров
    for (int i = 0; i < numManagers; ++i) {
        employees[idx++] = new Manager(
            managerNames[i],
            managerDepartments[i],
            managerSalaries[i]
        );
    }
    // Несколько рабочих
    for (int i = 0; i < numWorkers; ++i) {
        employees[idx++] = new Worker(
            workerNames[i],
            workerDepartments[i],
            workerSalaries[i]
        );
    }

    // Выводим всех
    for (int i = 0; i < COUNT; ++i) {
        employees[i]->Print();
    }

    // Освобождаем память
    for (int i = 0; i < COUNT; ++i) {
        delete employees[i];
    }

    return 0;
}



// надо сделать список работников, их позиции типа department, желательно ещё и salary. 
// для этого нужно переменные создать. Типа если президент то country