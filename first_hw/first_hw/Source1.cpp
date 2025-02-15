#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Point {
private:
    double x;
    double y;
    double z;

public:
    Point() : x(0), y(0), z(0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    // Геттеры
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Сеттеры
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    void setZ(double newZ) { z = newZ; }

    void input() {
        cout << "Введите координату X: ";
        cin >> x;
        cout << "Введите координату Y: ";
        cin >> y;
        cout << "Введите координату Z: ";
        cin >> z;
    }

    // Вывод данных
    void print() const {
        cout << "Координаты точки: ("
            << x << ", " << y << ", " << z << ")\n";
    }

    // Сохранение в файл
    bool saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла для записи!\n";
            return false;
        }
        file << x << " " << y << " " << z;
        file.close();
        return true;
    }

    // Загрузка из файла
    bool loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла для чтения!\n";
            return false;
        }
        file >> x >> y >> z;
        file.close();
        return true;
    }
};

int main() {
    Point p;

    cout << "--- Ввод данных ---\n";
    p.input();
    cout << "\n--- Вывод данных ---\n";
    p.print();

    p.setX(10.5);
    p.setY(20.3);
    cout << "\n--- После изменения через сеттеры ---\n";
    cout << "X: " << p.getX() << ", Y: " << p.getY()
        << ", Z: " << p.getZ() << "\n";

    const string filename = "point.txt";
    if (p.saveToFile(filename)) {
        cout << "\nДанные сохранены в файл '" << filename << "'\n";
    }

    Point p2;
    if (p2.loadFromFile(filename)) {
        cout << "\n--- Данные из файла ---\n";
        p2.print();
    }

    return 0;
}