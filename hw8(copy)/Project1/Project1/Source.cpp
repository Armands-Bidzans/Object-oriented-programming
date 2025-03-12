#include <iostream>
using namespace std;

class AreaCalculator {
private:
    short count; // счётчик вычислений
public:
    // Конструктор, инициализирующий счётчик
    AreaCalculator() : count(0) {}

    // Вычисление площади треугольника по основанию и высоте
    float triangleArea(float base, float height) {
        count++;
        return (base * height) / 2;
    }

    // Вычисление площади прямоугольника
    float rectangleArea(float width, float height) {
        count++;
        return width * height;
    }

    // Вычисление площади квадрата
    float squareArea(float side) {
        count++;
        return side * side;
    }

    // Вычисление площади ромба по длинам диагоналей
    float rhombusArea(float d1, float d2) {
        count++;
        return (d1 * d2) / 2;
    }

    // Функция для получения количества произведённых вычислений
    short getCount() {
        return count;
    }
};

int main() {
    AreaCalculator calc;

    // Примеры вычислений
    float triangle1 = calc.triangleArea(10, 5); // по основанию и высоте
    float rectangle = calc.rectangleArea(4, 6);
    float square = calc.squareArea(5);
    float rhombus = calc.rhombusArea(8, 6);

    // Вывод результатов
    cout << "Площадь треугольника (основание 10, высота 5): " << triangle1 << endl;
    cout << "Площадь прямоугольника (4 x 6): " << rectangle << endl;
    cout << "Площадь квадрата (сторона 5): " << square << endl;
    cout << "Площадь ромба (диагонали 8 и 6): " << rhombus << endl;
    cout << "Всего вычислений: " << calc.getCount() << endl;

    return 0;
}
