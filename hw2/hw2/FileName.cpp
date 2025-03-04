#include <iostream>
using namespace std;

class Fraction {
private:
    short numerator, denominator;

    short findGreatestCommonDivisor(short a, short b) {
        while (b != 0) {
            short temp = b;
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
        short gcd = findGreatestCommonDivisor(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction(short aNumerator, short aDenominator) {
        numerator = aNumerator;
        denominator = aDenominator;
        reduce(); // Сразу сокращаем дробь
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction add(const Fraction& b) {
        short newNumerator = (numerator * b.denominator) + (b.numerator * denominator);
        short newDenominator = denominator * b.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction subtract(const Fraction& b) {
        short newNumerator = (numerator * b.denominator) - (b.numerator * denominator);
        short newDenominator = denominator * b.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction multiply(const Fraction& b) {
        short newNumerator = numerator * b.numerator;
        short newDenominator = denominator * b.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction divide(const Fraction& b) {
        if (b.numerator == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        short newNumerator = numerator * b.denominator;
        short newDenominator = denominator * b.numerator;
        return Fraction(newNumerator, newDenominator);
    }
};

int main() {
    cout << "Введите первую дробь (числитель и знаменатель): ";
    short aNumerator, aDenominator;
    cin >> aNumerator >> aDenominator;

    Fraction a(aNumerator, aDenominator);

    cout << "Введите вторую дробь (числитель и знаменатель): ";
    short bNumerator, bDenominator;
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
