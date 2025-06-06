#include <iostream>
using namespace std;

// Абстрактный базовый класс Shape
class Shape
{
public:
    virtual ~Shape(){}

    // Чисто виртуальная функция print
    virtual void print(ostream& out) const = 0;

    // Общая перегрузка оператора вывода для всех Shape
    friend ostream& operator<<(ostream& out, const Shape& s)
    {
        s.print(out);
        return out;
    }
};

// Класс Point без изменений
class Point
{
private:
    int m_x = 0;
    int m_y = 0;
    int m_z = 0;

public:
    Point(int x, int y, int z) : m_x(x), m_y(y), m_z(z) {}

    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return out;
    }
};

// Класс Circle наследует Shape
class Circle : public Shape
{
private:
    Point m_center;
    int   m_radius;

public:
    Circle(const Point& center, int radius): m_center(center), m_radius(radius){}

    // Переопределяем print
    void print(ostream& out) const override
    {
        out << "Circle(" << m_center << ", radius " << m_radius << ")";
    }
};

// Класс Triangle наследует Shape
class Triangle : public Shape
{
private:
    Point m_p1;
    Point m_p2;
    Point m_p3;

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3) : m_p1(p1), m_p2(p2), m_p3(p3){}

    // Переопределяем print
    void print(ostream& out) const override
    {
        out << "Triangle("
            << m_p1 << ", "
            << m_p2 << ", "
            << m_p3 << ")";
    }
};

int main()
{
    Circle c(Point(1, 2, 3), 7);
    cout << c << '\n';  // Circle(Point(1, 2, 3), radius 7)

    Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
    cout << t << '\n';  // Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9))

    return 0;
}