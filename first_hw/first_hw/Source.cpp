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
    // Конструкторы
    Student() {}

    Student(const string& fullName, const string& birthDate, const string& phone,
        const string& city, const string& country, const string& institution,
        const string& institutionCity, const string& institutionCountry, const string& groupNumber)
        : fullName(fullName), birthDate(birthDate), phone(phone), city(city), country(country),
        institution(institution), institutionCity(institutionCity), institutionCountry(institutionCountry),
        groupNumber(groupNumber) {}

    // Функция для ввода данных
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

    // Функция для вывода данных
    void outputData() const {
        cout << "\n--- Данные студента ---\n";
        cout << "ФИО: " << fullName << "\n";
        cout << "Дата рождения: " << birthDate << "\n";
        cout << "Телефон: " << phone << "\n";
        cout << "Город проживания: " << city << "\n";
        cout << "Страна проживания: " << country << "\n";
        cout << "Учебное заведение: " << institution << "\n";
        cout << "Город учебного заведения: " << institutionCity << "\n";
        cout << "Страна учебного заведения: " << institutionCountry << "\n";
        cout << "Номер группы: " << groupNumber << "\n";
    }

    // Аксессоры (геттеры) для доступа к отдельным переменным-членам
    string getFullName() const { return fullName; }
    string getBirthDate() const { return birthDate; }
    string getPhone() const { return phone; }
    string getCity() const { return city; }
    string getCountry() const { return country; }
    string getInstitution() const { return institution; }
    string getInstitutionCity() const { return institutionCity; }
    string getInstitutionCountry() const { return institutionCountry; }
    string getGroupNumber() const { return groupNumber; }

    // Дополнительно можно добавить и сеттеры, если потребуется изменять данные
    void setFullName(const string& fullName) { this->fullName = fullName; }
    void setBirthDate(const string& birthDate) { this->birthDate = birthDate; }
    void setPhone(const string& phone) { this->phone = phone; }
    void setCity(const string& city) { this->city = city; }
    void setCountry(const string& country) { this->country = country; }
    void setInstitution(const string& institution) { this->institution = institution; }
    void setInstitutionCity(const string& institutionCity) { this->institutionCity = institutionCity; }
    void setInstitutionCountry(const string& institutionCountry) { this->institutionCountry = institutionCountry; }
    void setGroupNumber(const string& groupNumber) { this->groupNumber = groupNumber; }
};

int main() {
    Student student;
    student.inputData();
    student.outputData();

    // Пример использования аксессора:
    cout << "\nПолучение ФИО через аксессор: " << student.getFullName() << "\n";

    return 0;
}
