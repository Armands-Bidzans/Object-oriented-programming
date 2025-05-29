#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string firstName;
    string lastName;

public:
    Employee(const string& fn, const string& ln)
        : firstName(fn), lastName(ln) {}

    virtual ~Employee() {}

    virtual double calculateSalary() const = 0;
    virtual void display() const = 0;

    // Геттеры
    string getFirstName() const { return firstName; }
    string getLastName()  const { return lastName; }

    // Сеттеры
    void setFirstName(const string& fn) { firstName = fn; }
    void setLastName(const string& ln) { lastName = ln; }
};

// Класс почасового работника
class Worker : public Employee {
private:
    int hoursNumber;
    double hourlyRate;

public:
    Worker(const string& fn, const string& ln, int hours, double rate)
        : Employee(fn, ln), hoursNumber(hours), hourlyRate(rate) {}

    // Геттеры / Сеттеры
    int    getHoursNumber() const { return hoursNumber; }
    double getHourlyRate()  const { return hourlyRate; }
    void   setHoursNumber(int h) { hoursNumber = h; }
    void   setHourlyRate(double r) { hourlyRate = r; }

    // Расчёт зарплаты с учётом переработки
    double calculateSalary() const override {
        if (hoursNumber <= 40)
            return hoursNumber * hourlyRate;
        int overtime = hoursNumber - 40;
        return 40 * hourlyRate + overtime * hourlyRate * 2;
    }

    // Отображение информации о работнике
    void display() const override {
        cout << firstName << " " << lastName
            << " — Worker: hours=" << hoursNumber
            << ", rate=" << hourlyRate
            << ", salary=" << calculateSalary()
            << endl;
    }
};

// Базовый класс для сотрудников с фиксированной зарплатой и бонусом
class SalaryWorker : public Employee {
protected:
    double baseSalary;
    double bonus;

public:
    SalaryWorker(const string& fn, const string& ln, double salary, double b)
        : Employee(fn, ln), baseSalary(salary), bonus(b) {}

    // Геттеры / Сеттеры
    double getBaseSalary() const { return baseSalary; }
    double getBonus()      const { return bonus; }
    void   setBaseSalary(double s) { baseSalary = s; }
    void   setBonus(double b) { bonus = b; }

    virtual double calculateBonus() const = 0;

    // Расчёт итоговой зарплаты
    double calculateSalary() const override {
        return baseSalary + calculateBonus();
    }

    void display() const override {
        cout << firstName << " " << lastName
            << " — Base=" << baseSalary
            << ", bonus=" << calculateBonus()
            << ", total=" << calculateSalary()
            << endl;
    }
};

class Salesman : public SalaryWorker {
private:
    double planPercentage; // Процент выполнения плана

public:
    Salesman(const string& fn, const string& ln,
        double salary, double b, double percent)
        : SalaryWorker(fn, ln, salary, b),
        planPercentage(percent) {}

    // Геттер / Сеттер
    double getPlanPercentage() const { return planPercentage; }
    void   setPlanPercentage(double p) { planPercentage = p; }

    // Расчёт бонуса на основе процента выполнения плана
    double calculateBonus() const override {
        return bonus * (planPercentage / 100.0);
    }

    void display() const override {
        cout << firstName << " " << lastName
            << " — Salesman: plan%=" << planPercentage
            << ", bonus=" << calculateBonus()
            << ", total=" << calculateSalary()
            << endl;
    }
};

class Manager : public SalaryWorker {
private:
    int clientCount;

public:
    Manager(const string& fn, const string& ln, double salary, double b, int clients) :
        SalaryWorker(fn, ln, salary, b), clientCount(clients) {}

    // Геттер / Сеттер
    int  getClientCount() const { return clientCount; }
    void setClientCount(int c) { clientCount = c; }

    // Расчёт бонуса на основе количества клиентов
    double calculateBonus() const override {
        if (clientCount > 200) return bonus * 3;
        if (clientCount > 100) return bonus * 2;
        return bonus;
    }

    void display() const override {
        cout << firstName << " " << lastName
            << " — Manager: clients=" << clientCount
            << ", bonus=" << calculateBonus()
            << ", total=" << calculateSalary()
            << endl;
    }
};

int main() {
    Employee* employees[7] = {
        new Worker("Kate", "Jordan", 30, 10.0),
        new Worker("Jack", "Peterson", 50, 10.0),
        new Salesman("Peter", "Brown", 800, 100.0, 80.0),
        new Salesman("Antony", "Norton", 1000, 100.0, 150.0),
        new Manager("David", "Flynn", 2000, 200.0, 50),
        new Manager("Marian", "Wood", 1800, 200.0, 120),
        new Manager("Brent", "Simpson", 2200, 200.0, 250)
    };

    for (int i = 0; i < 7; ++i) {
        employees[i]->display();   // Вывод данных
        delete employees[i];
    }

    return 0;
}
