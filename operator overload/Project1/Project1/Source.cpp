#include <iostream>
using namespace std;

class Date
{
public:
    // Конструктор по умолчанию и с параметрами
    Date(short d = 1, short m = 1, short y = 1970) : day(d), month(m), year(y) {}
    ~Date();
    // Разность дат (в днях)
    int operator-(const Date& other) const;

    // Увеличение даты на указанное число дней
    Date operator+(int days) const;

    // Вывод даты в формате Д.М.ГГГГ
    void print() const {
        cout << day << "." << month << "." << year;
    }

private:
    short day, month, year;

    // Является ли год високосным?
    bool isVisokosny(short y) {
        if (y % 400 == 0) return true;
        if (y % 100 == 0) return false;
        if (y % 4 == 0)   return true;
        return false;
    }
    // Сколько дней в данном месяце данного года?
    short daysInMonth(short m, short y) {
        if (m == 2) {
            if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
                return 29;
            }
            else {
                return 28;
            }
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        if (m == 1 || m == 3 || m == 5 || m == 7 ||
            m == 8 || m == 10 || m == 12) {
            return 31;
        }
        return 0;
    }
};

// Определение деструктора
Date::~Date() {}

// Моя собственная реализация swap
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Разность дат в днях
int Date::operator-(const Date& other) const
{
    Date start = other;
    Date end = *this;
    int days = 0;
    bool isNegative = false;
    // Проверяем, если дата start позже даты end, то меняем их местами, чтобы считать разницу от меньшей к большей
    if (start.year > end.year ||
        (start.year == end.year && start.month > end.month) ||
        (start.year == end.year && start.month == end.month && start.day > end.day)) {
        ::swap(start, end);  // явно вызываем глобальную swap
        isNegative = true;
    }
    // Считаем количество дней между start и end, двигаясь по одному дню вперёд
    while (!(start.day == end.day && start.month == end.month && start.year == end.year)) {
        start = start + 1;
        ++days;
    }

    if (isNegative)
        return -days;
    else
        return days;
}

// Увеличение даты на указанное число дней
Date Date::operator+(int days) const
{
    Date result = *this;
    for (int i = 0; i < days; ++i) {
        ++result.day;
        if (result.day > result.daysInMonth(result.month, result.year)) {
            result.day = 1;
            if (result.month == 12) {
                result.month = 1;
                ++result.year;
            }
            else {
                ++result.month;
            }
        }
    }
    return result;
}

int main() {
    Date d1(20, 4, 2025);
    Date d2(15, 4, 2025);

    // Вывод подробной информации о датах и их разнице
    cout << "Date d1 = "; d1.print(); cout << endl;
    cout << "Date d2 = "; d2.print(); cout << endl;

    int diff = d1 - d2;
    cout << "Разница между датами (d1 - d2) составляет " << diff << " ";
    if (diff == 1 || diff == -1) cout << "день";
    else cout << "дней";
    cout << endl;

    Date d3 = d2 + 10;
    cout << "Прибавляем 10 дней к дате d2 (";
    d2.print();
    cout << "): получаем ";
    d3.print();
    cout << endl;

    return 0;
}