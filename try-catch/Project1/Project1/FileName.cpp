#include <iostream>
using namespace std;
void input() {
    try {
        int a, b;
        cout << "enter first value" << endl;
        cin >> a;
        if (!cin) throw "Not a number";         // поймаем любой некорректный ввод
        cout << "Enter second value" << endl;
        cin >> b;
        if (!cin) throw "Not a number";         // опять же — если ввели не‑число
        if (a < 1 || a > 10 || b < 1 || b > 10)
            throw "Incorrect size";
    }
    catch (...) {
        // При любом не‑числовом вводе или числе вне диапазона
        cout << "Isn't correct" << endl;
        // После вывода сообщения можно, если нужно, очищать поток:
    }
}

namespace Add {
    unsigned int Add(unsigned int a, int b) {
        return a + b;
    }
    double Add(double a, double b) {
        return a + b;
    }
}

namespace Substract {
    unsigned int substract(unsigned int a, int b) {
        return a - b;
    }
    double substract(double a, double b) {
        return a - b;
    }
}

/*
    Новая функция принимает строку символов (массив char, завершающийся '\0'),
      проверяет, что строка действительно содержит только десятичные цифры (с опциональным '+' или '-'),
      и «собирает» из неё целое.
    Если встречается нелегальный символ — бросаем "Invalid character".
    Если при накоплении числа выходим за пределы int (2147483647 или -2147483648) — бросаем "Overflow" или "Underflow".
*/
int parseDecimal(char s[]) {
    // Если строка пуста (первый символ '\0'), считаем за ошибку формата
    if (s[0] == '\0') {
        throw "Empty string";
    }

    int i = 0;
    int sign = 1;

    // Проверяем, есть ли в начале знак '+' или '-'
    if (s[0] == '+' || s[0] == '-') {
        if (s[0] == '-') sign = -1;
        i++;
        // Если строка — только '+' или '-', без цифр дальше — это тоже ошибка
        if (s[i] == '\0') {
            throw "Invalid format";
        }
    }

    // Будем накапливать «абсолютное значение» в переменной long. 
    // (long обычно 32‑ или 64‑битный, но здесь мы предполагаем, что его хватит, 
    //  чтобы отследить переполнение выше границы int.)
    long result = 0;

    // Жёстко прописанные константы границ int:
    const int MAX_INT = 2147483647;        // +2^31‑1
    const int MIN_INT_ABS = 2147483648;    // «абсолютное значение» – при sign = −1

    // Пробегаем по всей строке, пока не встретим '\0'
    for (; s[i] != '\0'; i++) {
        char c = s[i];
        if (c < '0' || c > '9') {
            // Нашли недопустимый символ
            throw "Invalid character";
        }
        int digit = c - '0';

        // Проверяем на следующем шаге переполнение
        if (sign > 0) {
            // хотим сделать result = result*10 + digit, проверить, не превысит ли MAX_INT
            if (result > ((long)MAX_INT - digit) / 10) {
                throw "Overflow";
            }
            result = result * 10 + digit;
        }
        else {
            // для отрицательного числа мы тоже считаем «абсолютное значение», 
            // а в конце сделаем result*sign
            if (result > ((long)MIN_INT_ABS - digit) / 10) {
                throw "Underflow";
            }
            result = result * 10 + digit;
        }
    }

    // Применяем знак
    long signedResult = sign * result;

    // (Дополнительная проверка «на всякий случай» — но обычно мы уже проверили внутри цикла.)
    if (signedResult > MAX_INT) {
        throw "Overflow";
    }
    if (signedResult < -MIN_INT_ABS) {
        throw "Underflow";
    }

    return (int)signedResult;
}

int main() {
    // Сначала ваша старая часть
    input();

    // А теперь — демонстрация «группы 1» (задание №1)
    cout << endl << "---- Задание №1: введите строку-число:" << endl;
    // Возьмём буфер на 20 символов (оно отработает на любом int‑числе, 
    // потому что int не больше 10 знаков + знак).
    char buf[20];
    cin >> buf;      // читаем «строку‑число»

    try {
        int x = parseDecimal(buf);
        cout << "Parsed value = " << x << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}


//#include <iostream>
//using namespace std;
//
//void input() {
//    try
//    {
//        int a, b;
//        cout << "enter first value" << endl;
//        cin >> a;
//        cout << "Enter second value" << endl;
//        cin >> b;
//        // Вместо некорректного "if (a, b < 1 | a, b > 10)"
//        // нужно проверить каждую переменную отдельно и использовать логическое ИЛИ (||)
//        if (a < 1 || a > 10 || b < 1 || b > 10)
//            throw "Incorrect size";
//    }
//    catch (...) { //при любом значении не являеющимся числом должно срабатывать
//        // Добавил точку с запятой после вывода
//        cout << "Isn't correct";
//    }
//}
//
//namespace Add {
//    unsigned int Add(unsigned int a, int b) {
//        return a + b;
//    }
//    double Add(double a, double b) {
//        return a + b;
//    }
//}
//
//namespace Substract {
//    unsigned int substract(unsigned int a, int b) {
//        return a - b;
//    }
//    double substract(double a, double b) {
//        return a - b;
//    }
//}
//
//int main() {
//    // Для проверки можно вызвать функцию input(), но это не обязательно
//    input(); // пока только вводится но операции не выводятся
//    return -1;
//}

/*
Задание №1
Написать функцию вычисления значения по заданной строке символов, являющихся записью этого числа в десятичной системе исчисления.
Предусмотреть случай выхода за границы диапазона определяемого типом int.
Используйте механизм исключений.
*/


 /*Задание №1
Написать функцию вычисления значения по заданной строке символов, являющихся записью этого числа в десятичной системе исчисления.
Предусмотреть случай выхода за границы диапазона определяемого типом int.
Используйте механизм исключений. */