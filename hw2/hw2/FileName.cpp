#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
    int findGreatestCommonDivisor(int a, int b) const {
        // Приводим аргументы к положительным значениям
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        // Если один из аргументов равен нулю, возвращаем другой (избегая деления на 0)
        if (a == 0) return b;
        if (b == 0) return a;

        while (a != b) {
            if (a > b) {
                a = a - b;
            }
            else {
                b = b - a;
            }
        }
        return a;
    }
    void reduce() {
        int divisor = findGreatestCommonDivisor(numerator, denominator);
        // Избегаем деления на 0
        if (divisor != 0) {
            numerator /= divisor;
            denominator /= divisor;
        }
    }
public:
    Fraction(int aNumerator, int bDenominator) {
        numerator = aNumerator;
        denominator = bDenominator;
        reduce();
    }
    void input(int aNumerator, int bDenominator) {
        numerator = aNumerator;
        denominator = bDenominator;
        reduce();
    }
    void print() const {
        cout << "Результат: " << numerator << "/" << denominator << endl;
    }
    Fraction add(const Fraction& b) const {
        Fraction result(numerator * b.denominator + b.numerator * denominator, denominator * b.denominator);
        result.reduce();
        return result;
    }
    Fraction subtract(const Fraction& b) const {
        Fraction result(numerator * b.denominator - b.numerator * denominator, denominator * b.denominator);
        result.reduce();
        return result;
    }
    Fraction multiply(const Fraction& b) const {
        Fraction result(numerator * b.numerator, denominator * b.denominator);
        result.reduce();
        return result;
    }
    Fraction divide(const Fraction& b) const {
        Fraction result(numerator * b.denominator, denominator * b.numerator);
        result.reduce();
        return result;
    }
};

int main() {
    Fraction a(1, 2), b(3, 4);
    cout << "Введите первую дробь (числитель и знаменатель): ";
    int aNumerator, aDenominator;
    cin >> aNumerator >> aDenominator;
    a.input(aNumerator, aDenominator);

    cout << "Введите вторую дробь (числитель и знаменатель): ";
    int bNumerator, bDenominator;
    cin >> bNumerator >> bDenominator;
    b.input(bNumerator, bDenominator);

    Fraction sum = a.add(b);
    cout << "Сумма: ";
    sum.print();

    Fraction diff = a.subtract(b);
    cout << "Разность: ";
    diff.print();

    Fraction prod = a.multiply(b);
    cout << "Произведение: ";
    prod.print();

    Fraction quot = a.divide(b);
    cout << "Частное: ";
    quot.print();

    return 0;
}
