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

    // Массив указателей на базовый класс
    Employer* employees[COUNT];

    int idx = 0;
    // Несколько президентов
    for (int i = 0; i < numPresidents; ++i) {
        // Создаём переменные для хранения информации о президенте
        string presName = "John Doe";
        string presDept = "Executive Office";
        double presSalary = 250000.0;
        string presCountry = "USA";
        employees[idx++] = new President(presName, presDept, presSalary, presCountry);
    }
    // Несколько менеджеров
    for (int i = 0; i < numManagers; ++i) {
        // Создаём переменные для хранения информации о менеджере
        string mgrName = "Jane Smith";
        string mgrDept = "Sales";
        double mgrSalary = 90000.0;
        employees[idx++] = new Manager(mgrName, mgrDept, mgrSalary);
    }
    // Несколько рабочих
    for (int i = 0; i < numWorkers; ++i) {
        // Создаём переменные для хранения информации о рабочем
        string wrkName = "Bob Johnson";
        string wrkDept = "Manufacturing";
        double wrkSalary = 45000.0;
        employees[idx++] = new Worker(wrkName, wrkDept, wrkSalary);
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
