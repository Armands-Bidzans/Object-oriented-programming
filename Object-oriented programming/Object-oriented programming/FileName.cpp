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

    Student(const string& fullName, const string& birthDate, const string& phone, const string& city, const string& country,
        const string& institution, const string& institutionCity, const string& institutionCountry, const string& groupNumber)
        : fullName(fullName), birthDate(birthDate), phone(phone), city(city), country(country),
        institution(institution), institutionCity(institutionCity), institutionCountry(institutionCountry), groupNumber(groupNumber) {
    }

    void inputData() {
        cout << "Введите ФИО: ";
        getline(cin, fullName);
        cout << "Введите дату рождения (например, 01.01.2000): ";
        getline(cin, birthDate);
        cout << "Введите контактный телефон: ";
        getline(cin, phone);
        cout << "Введите город проживания: ";
        getline(cin, city);
        cout << "Введите страну проживания: ";
        getline(cin, country);
        cout << "Введите название учебного заведения: ";
        getline(cin, institution);
        cout << "Введите город учебного заведения: ";
        getline(cin, institutionCity);
        cout << "Введите страну учебного заведения: ";
        getline(cin, institutionCountry);
        cout << "Введите номер группы: ";
        getline(cin, groupNumber);
    }

    void outputData() const {
        cout << "\n--- Данные студента ---\n";
        cout << "ФИО: " << fullName << endl;
        cout << "Дата рождения: " << birthDate << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Город проживания: " << city << endl;
        cout << "Страна проживания: " << country << endl;
        cout << "Учебное заведение: " << institution << endl;
        cout << "Город учебного заведения: " << institutionCity << endl;
        cout << "Страна учебного заведения: " << institutionCountry << endl;
        cout << "Номер группы: " << groupNumber << endl;
    }
};

int main() {
    Student student;
    student.inputData();
    student.outputData();
    return 0;
}

