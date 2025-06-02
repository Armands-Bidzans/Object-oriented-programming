//#include <iostream>
//#include <cmath>
//using namespace std;
//
//// Перегруженные шаблонные функции для нахождения корней уравнений
//
//// Решение линейного уравнения a*x + b = 0
//template <typename T>
//void findRoots(T a, T b) {
//    cout << "=== Линейное уравнение ===" << endl;
//    cout << "Коэффициенты: a = " << a << ", b = " << b << endl;
//
//    if (a != 0) {
//        // Покажем, как считается корень
//        T numerator = -b;
//        T denominator = a;
//        cout << "Вычисляем числитель: -b = " << numerator << endl;
//        cout << "Вычисляем знаменатель: a = " << denominator << endl;
//
//        T x = numerator / denominator;
//        cout << "Корень x = (-b) / a = " << x << endl;
//    }
//    else {
//        // a == 0: вырожденное уравнение
//        cout << "Так как a = 0, уравнение вырождается в:" << endl;
//        cout << "    0 * x + b = 0" << endl;
//        if (b != 0) {
//            cout << "b = " << b << " ≠ 0 → решений нет." << endl;
//        }
//        else {
//            cout << "b = " << b << " = 0 → бесконечно много решений." << endl;
//        }
//    }
//    cout << endl;
//}
//
//// Решение квадратного уравнения a*x^2 + b*x + c = 0
//template <typename T>
//void findRoots(T a, T b, T c) {
//    cout << "=== Квадратное уравнение ===" << endl;
//    cout << "Коэффициенты: a = " << a << ", b = " << b << ", c = " << c << endl;
//
//    if (a == 0) {
//        cout << "Так как a = 0, уравнение вырождается в линейное:" << endl;
//        cout << "    b * x + c = 0" << endl;
//        findRoots(b, c);
//        return;
//    }
//
//    // Вычисляем b^2 и 4ac отдельно
//    T bb = b * b;
//    T four_ac = 4 * a * c;
//    cout << "Вычисляем b^2: b^2 = " << bb << endl;
//    cout << "Вычисляем 4ac: 4 * a * c = " << four_ac << endl;
//
//    // Дискриминант D = b^2 - 4ac
//    T D = bb - four_ac;
//    cout << "Дискриминант: D = b^2 - 4ac = " << D << endl;
//
//    if (D > 0) {
//        // Два разных вещественных корня
//        cout << "D > 0 → два разных вещественных корня." << endl;
//        T sqrtD = sqrt(D);
//        cout << "Вычисляем sqrt(D) = " << sqrtD << endl;
//
//        T numerator1 = -b + sqrtD;
//        T numerator2 = -b - sqrtD;
//        T denominator = 2 * a;
//        cout << "Вычисляем числитель для x1: -b + sqrt(D) = " << numerator1 << endl;
//        cout << "Вычисляем числитель для x2: -b - sqrt(D) = " << numerator2 << endl;
//        cout << "Вычисляем знаменатель: 2 * a = " << denominator << endl;
//
//        T x1 = numerator1 / denominator;
//        T x2 = numerator2 / denominator;
//        cout << "x1 = (" << -b << " + " << sqrtD << ") / (" << denominator << ") = " << x1 << endl;
//        cout << "x2 = (" << -b << " - " << sqrtD << ") / (" << denominator << ") = " << x2 << endl;
//    }
//    else if (D == 0) {
//        // Один (двукратный) корень
//        cout << "D = 0 → один (двукратный) вещественный корень." << endl;
//        T denominator = 2 * a;
//        cout << "Вычисляем знаменатель: 2 * a = " << denominator << endl;
//
//        T numerator = -b;
//        cout << "Вычисляем числитель: -b = " << numerator << endl;
//
//        T x = numerator / denominator;
//        cout << "x = (-b) / (2a) = " << x << endl;
//    }
//    else {
//        // Действительных корней нет
//        cout << "D < 0 → действительных корней нет." << endl;
//    }
//    cout << endl;
//}
//
//int main() {
//    cout << "Выберите тип уравнения:\n";
//    cout << "1 – линейное (a*x + b = 0)\n";
//    cout << "2 – квадратное (a*x^2 + b*x + c = 0)\n";
//    cout << "Введите 1 или 2: ";
//
//    int choice;
//    cin >> choice;
//
//    if (choice == 1) {
//        // Линейное уравнение
//        double a, b;
//        cout << "Введите коэффициенты a и b через пробел: ";
//        cin >> a >> b;
//        findRoots(a, b);
//    }
//    else if (choice == 2) {
//        // Квадратное уравнение
//        double a, b, c;
//        cout << "Введите коэффициенты a, b и c через пробел: ";
//        cin >> a >> b >> c;
//        findRoots(a, b, c);
//    }
//    else {
//        cout << "Неверный выбор. Программа завершена." << endl;
//    }
//
//    return 0;
//}
