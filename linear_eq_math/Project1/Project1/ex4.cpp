//#include <iostream>
//#include <string>
//using namespace std;
//
//// Задание №4: шаблон функции для нахождения минимума из двух параметров
//template <typename T>
//T getMin(T a, T b) {
//    if (a < b) {
//        return a;
//    }
//    else {
//        return b;
//    }
//}
//
//int main() {
//    // Пример для int
//    int i1 = 5, i2 = 12;
//    cout << "Из целых: min(" << i1 << ", " << i2 << ") = " << getMin(i1, i2) << endl;
//
//    // Пример для double
//    double d1 = 3.14, d2 = 2.71;
//    cout << "Из двойных: min(" << d1 << ", " << d2 << ") = " << getMin(d1, d2) << endl;
//
//    // Пример для строк (лексикографическое сравнение)
//    string s1 = "apple", s2 = "banana";
//    cout << "Из строк: min(\"" << s1 << "\", \"" << s2 << "\") = \"" << getMin(s1, s2) << "\"" << endl;
//
//    return 0;
//}