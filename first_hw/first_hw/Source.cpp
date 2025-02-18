#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string fullName;
    string birthDate;
    string phone;
    string city;
    string country;
    string institution;
    string institutionCity;
    string institutionCountry;
    string groupNumber;

public:
    Student() {}

    void inputData() {
        cout << "Введите ФИО: ";
        getline(cin, fullName);
        cout << "Введите дату рождения: ";
        getline(cin, birthDate);
        cout << "Введите телефон: ";
        getline(cin, phone);
        cout << "Введите город: ";
        getline(cin, city);
        cout << "Введите страну: ";
        getline(cin, country);
        cout << "Введите учебное заведение: ";
        getline(cin, institution);
        cout << "Введите город учебы: ";
        getline(cin, institutionCity);
        cout << "Введите страну учебы: ";
        getline(cin, institutionCountry);
        cout << "Введите номер группы: ";
        getline(cin, groupNumber);
    }

    void outputData() const {
        cout << "\n--- Данные студента ---\n";
        cout << "ФИО: " << fullName << "\n";
        cout << "Дата рождения: " << birthDate << "\n";
        cout << "Телефон: " << phone << "\n";
        cout << "Город: " << city << "\n";
        cout << "Страна: " << country << "\n";
        cout << "Учебное заведение: " << institution << "\n";
        cout << "Город учебы: " << institutionCity << "\n";
        cout << "Страна учебы: " << institutionCountry << "\n";
        cout << "Группа: " << groupNumber << "\n";
    }
};

int main() {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Показать всех\n";
        cout << "3. Выход\n";
        cout << "Выберите: ";

        cin >> choice;
        cin.clear(); // Сбрасываем флаги ошибок
        cin.ignore(1000, '\n'); // Очищаем буфер

        switch (choice) {
        case 1: {
            if (studentCount < MAX_STUDENTS) {
                students[studentCount].inputData();
                studentCount++;
                cout << "Студент добавлен!\n";
            }
            else {
                cout << "Достигнут максимум студентов!\n";
            }
            break;
        }
        case 2: {
            if (studentCount == 0) {
                cout << "Список пуст!\n";
            }
            else {
                cout << "\n=== Список студентов ===\n";
                for (int i = 0; i < studentCount; i++) {
                    students[i].outputData();
                }
            }
            break;
        }
        case 3: {
            cout << "Выход...\n";
            break;
        }
        default: {
            cout << "Неверный выбор!\n";
            break;
        }
        }
    } while (choice != 3);

    return 0;
}