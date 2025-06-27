#include <iostream>
#include <string>

using namespace std;

// Базовый класс Passport
class Passport {
public:
    Passport(const string& surname, const string& firstName,
        const string& patronymic, const string& passportNumber)
        : surname_(surname), firstName_(firstName), patronymic_(patronymic), passportNumber_(passportNumber) {}
    virtual ~Passport() = default;

    // Виртуальная функция для вывода информации
    virtual void Print() const {
        cout << "Паспорт гражданина Украины:" << endl
            << "Фамилия: " << surname_ << ", Имя: " << firstName_ << ", Отчество: " << patronymic_
            << ", Серия и номер: " << passportNumber_ << endl;
    }

protected:
    string surname_;
    string firstName_;
    string patronymic_; // отчество
    string passportNumber_;
};

// Класс ForeignPassport, производный от Passport
class ForeignPassport : public Passport {
public:
    static const int MAX_VISAS = 10;

    ForeignPassport(const string& surname, const string& firstName,
        const string& patronymic, const string& passportNumber,
        const string& foreignNumber,
        const string visas[], int visaCount)
        : Passport(surname, firstName, patronymic, passportNumber),
        foreignNumber_(foreignNumber), visaCount_(visaCount) {
        for (int i = 0; i < visaCount_ && i < MAX_VISAS; ++i) {
            visas_[i] = visas[i];
        }
    }

    void Print() const override {
        Passport::Print();
        cout << "Заграничный паспорт " << foreignNumber_ << ", Визы: ";
        for (int i = 0; i < visaCount_; ++i) {
            cout << visas_[i];
            if (i + 1 < visaCount_) cout << ", ";
        }
        cout << endl;
    }

private:
    string foreignNumber_;
    string visas_[MAX_VISAS];
    int visaCount_;
};

int main() {
    // Ввод данных для обычного паспорта
    string surname, firstName, patronymic, passportNumber;
    cout << "Введите фамилию: ";
    getline(cin, surname);
    cout << "Введите имя: ";
    getline(cin, firstName);
    cout << "Введите отчество: ";
    getline(cin, patronymic);
    cout << "Введите серию и номер паспорта: ";
    getline(cin, passportNumber);

    Passport p(surname, firstName, patronymic, passportNumber);

    // Ввод данных заграничного паспорта
    string foreignNumber;
    cout << "Введите серию и номер заграничного паспорта: ";
    getline(cin, foreignNumber);

    int visaCount;
    const int MAX_VISAS = ForeignPassport::MAX_VISAS;
    cout << "Введите количество виз (до " << MAX_VISAS << "): ";
    cin >> visaCount;
    if (visaCount > MAX_VISAS) visaCount = MAX_VISAS;
    cin.ignore(1000, '\n');

    string visasList[MAX_VISAS];
    for (int i = 0; i < visaCount; ++i) {
        cout << "Введите название визы #" << (i + 1) << ": ";
        getline(cin, visasList[i]);
    }

    ForeignPassport fp(surname, firstName, patronymic, passportNumber,
        foreignNumber, visasList, visaCount);

    // Вывод информации
    cout << endl << "--- Паспорт ---" << endl;
    p.Print();
    cout << "\n--- Заграничный паспорт ---" << endl;
    fp.Print();

    return 0;
}