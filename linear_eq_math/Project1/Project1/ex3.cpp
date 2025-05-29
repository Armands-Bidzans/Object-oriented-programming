#include <iostream>
#include <string>
using namespace std;

// Задание №3: шаблон функции для нахождения максимума из двух параметров
template <typename T>
T getMax(T a, T b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {
    // Пример для int
    int i1 = 5, i2 = 12;
    cout << "Из целых: max(" << i1 << ", " << i2 << ") = " << getMax(i1, i2) << endl;

    // Пример для double
    double d1 = 3.14, d2 = 2.71;
    cout << "Из двойных: max(" << d1 << ", " << d2 << ") = " << getMax(d1, d2) << endl;

    // Пример для строк (лексикографическое сравнение)
    string s1 = "apple", s2 = "banana";
    cout << "Из строк: max(\"" << s1 << "\", \"" << s2 << "\") = \"" << getMax(s1, s2) << "\"" << endl;

    return 0;
}
