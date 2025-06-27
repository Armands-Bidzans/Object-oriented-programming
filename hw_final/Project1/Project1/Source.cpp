//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// Абстрактный базовый класс Служащий
//class Служащий {
//public:
//    Служащий(const string& name) : name_(name) {}
//    virtual ~Служащий() = default;
//
//    // Чисто виртуальная функция для отображения информации
//    virtual void Print() const = 0;
//
//protected:
//    string name_;
//};
//
//// Класс Президент
class Президент : public Служащий {
public:
    Президент(const string& name, const string& country)
        : Служащий(name), country_(country) {}

    void Print() const override {
        cout << "Президент: " << name_
            << ", Страна: " << country_ << endl;
    }

private:
    string country_;
};

// Класс Менеджер
class Менеджер : public Служащий {
public:
    Менеджер(const string& name, int team_size)
        : Служащий(name), team_size_(team_size) {}

    void Print() const override {
        cout << "Менеджер: " << name_
            << ", Размер команды: " << team_size_ << endl;
    }

private:
    int team_size_;
};

// Класс Рабочий
class Рабочий : public Служащий {
public:
    Рабочий(const string& name, const string& department)
        : Служащий(name), department_(department) {}

    void Print() const override {
        cout << "Рабочий: " << name_
            << ", Отдел: " << department_ << endl;
    }

private:
    string department_;
};

int main() {
    // Массив указателей на служащих
    Служащий* сотрудники[3];

    // Ввод данных для Президента
    string pres_name, pres_country;
    cout << "Введите имя Президента: ";
    getline(cin, pres_name);
    cout << "Введите страну Президента: ";
    getline(cin, pres_country);
    сотрудники[0] = new Президент(pres_name, pres_country);
    // Ввод данных для Менеджера
    string mgr_name;
    int mgr_team;
    cout << "Введите имя Менеджера: ";
    getline(cin, mgr_name);
    cout << "Введите размер команды Менеджера: ";
    cin >> mgr_team;
    cin.ignore(1000, '\n');
    сотрудники[1] = new Менеджер(mgr_name, mgr_team);

    // Ввод данных для Рабочего
    string worker_name, worker_dept;
    cout << "Введите имя Рабочего: ";
    getline(cin, worker_name);
    cout << "Введите отдел Рабочего: ";
    getline(cin, worker_dept);
    сотрудники[2] = new Рабочий(worker_name, worker_dept);

    // Вывод информации о каждом служащем
    cout << "\n--- Информация о сотрудниках ---" << endl;
    for (size_t i = 0; i < 3; ++i) {
        сотрудники[i]->Print();
    }

    // Освобождение памяти
    for (size_t i = 0; i < 3; ++i) {
        delete сотрудники[i];
    }

    return 0;
}
