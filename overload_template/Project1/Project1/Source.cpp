#include <iostream>
using namespace std;
int main() {
	return -1;
}

template <class T>
T square 


#include <iostream>

// Линейное уравнение
template<typename T>
void solveEquation(T a, T b) {
    if (a == 0) {
        cout << "Нет корней (a = 0)" << endl;
    }
    else {
        cout << "x = " << (-b) / a << endl;
    }
}

// Квадратное уравнение
template<typename T>
void solveEquation(T a, T b, T c) {
    T D = b * b - 4 * a * c;
    if (a == 0) {
        // Это линейное уравнение
        solveEquation(b, c);
        return;
    }
    if (D < 0) {
        cout << "Нет корней" << endl;
    }
    else if (D == 0) {
        cout << "Один корень: x = " << -b / (2 * a) << endl;
    }
    else {
        // Вместо sqrt(D) подставь свое конкретное значение если можешь,
        // или скажи что D > 0 и корни есть, но вычислять их пока не умеешь.
        cout << "Два корня, но вычислять sqrt(D) нельзя по условиям задачи" << endl;
    }
}