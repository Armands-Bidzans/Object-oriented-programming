#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

    int findGreatestCommonDivisor(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a); // Возвращаем положительное значение
    }

    void reduce() {
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть равен нулю!" << endl;
            exit(1);
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int gcd = findGreatestCommonDivisor(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
   /* Fraction(int aNumerator, int aDenominator) : numerator(aNumerator), denominator(aDenominator) {
        reduce(); // Сразу сокращаем дробь
    }*/
    Fraction(int aNumerator, int aDenominator) {
        numerator = aNumerator;
        denominator = aDenominator;
        reduce(); // Сразу сокращаем дробь
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction add(const Fraction& b) {
        int newNumerator = (numerator * b.denominator) + (b.numerator * denominator);
        int newDenominator = denominator * b.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction subtract(const Fraction& b) {
        int newNumerator = (numerator * b.denominator) - (b.numerator * denominator);
        int newDenominator = denominator * b.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction multiply(const Fraction& b) {
        int newNumerator = numerator * b.numerator;
        int newDenominator = denominator * b.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction divide(const Fraction& b) {
        if (b.numerator == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        int newNumerator = numerator * b.denominator;
        int newDenominator = denominator * b.numerator;
        return Fraction(newNumerator, newDenominator);
    }
};

int main() {
    cout << "Введите первую дробь (числитель и знаменатель): ";
    int aNumerator, aDenominator;
    cin >> aNumerator >> aDenominator;

    Fraction a(aNumerator, aDenominator);

    cout << "Введите вторую дробь (числитель и знаменатель): ";
    int bNumerator, bDenominator;
    cin >> bNumerator >> bDenominator;

    Fraction b(bNumerator, bDenominator);

    // Сложение
    Fraction sum = a.add(b);
    cout << "Сумма: ";
    sum.print();

    // Вычитание
    Fraction diff = a.subtract(b);
    cout << "Разность: ";
    diff.print();

    // Умножение
    Fraction prod = a.multiply(b);
    cout << "Произведение: ";
    prod.print();

    // Деление
    Fraction quot = a.divide(b);
    cout << "Частное: ";
    quot.print();

    return 0;
}