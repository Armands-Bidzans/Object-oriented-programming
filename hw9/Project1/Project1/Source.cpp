#include <iostream>
using namespace std;

class Human {
private:
    short age;
    string* name;  // Указатель для строки(по требованиям задания)
public:
    // дефолтный конструктор
    Human() {
        age = 0;
        name = new string("");  // Выделяем память для строки
    }
    // Конструктор с параметрами
    Human(string& n, short a) {
        age = a;
        name = new string(n);  // Выделяем память для строки
    }
    // Конструктор копирования
    Human(Human& other) {
        age = other.age;
        name = new string(*other.name);  // Копируем строку с выделением новой памяти
    }

    // Деструктор
    ~Human() {
        delete name;
    }

    // Геттеры
    string& getName() {
        return *name;
    }

    int getAge() {
        return age;
    }

    // Сеттеры
    void setName(string& n) {
        *name = n;
    }
    void setAge(short a) {
        age = a;
    }

    // Вывод информации о человеке
    void print() {
        cout << "Name: " << *name << ", Age: " << age << endl;
    }
};

class Apartment {
public:
    // Конструктор по умолчанию с вместимостью 1
    Apartment() {
        capacity = 1;
        count = 0;
        residents = new Human[capacity];
    }
    // Конструктор с параметром (задаёт вместимость квартиры)
    Apartment(short cap) {
        capacity = cap;
        count = 0;
        residents = new Human[capacity];
    }
    // Конструктор копирования
    Apartment(Apartment& other) {
        capacity = other.capacity;
        count = other.count;
        residents = new Human[capacity];
        for (short i = 0; i < count; ++i) {
            // Для каждого жителя копируем данные вручную, чтобы обеспечить глубокое копирование
            residents[i].setAge(other.residents[i].getAge());
            string n = other.residents[i].getName();
            residents[i].setName(n);
        }
    }
    void copyFrom(Apartment& other) {
        if (this != &other) {
            delete[] residents;
            capacity = other.capacity;
            count = other.count;
            residents = new Human[capacity];
            for (short i = 0; i < count; ++i) {
                residents[i].setAge(other.residents[i].getAge());
                string n = other.residents[i].getName();
                residents[i].setName(n);
            }
        }
    }
    // Деструктор
    ~Apartment() {
        delete[] residents;
    }
    // Метод добавления жителя
    void addResident(Human& h) {
        if (count < capacity) {
            residents[count].setAge(h.getAge()); //глубокое копирование
            string temp = h.getName();
            residents[count].setName(temp);
            count++;
        }
        else {
            cout << "Apartment is full!" << endl;
        }
    }
    // Метод вывода информации об апартаменте
    void print() {
        cout << "Apartment has " << count << " resident(s):" << endl;
        for (short i = 0; i < count; ++i) {
            residents[i].print();
        }
    }

private:
    Human* residents;  // Динамический массив объектов Human
    short capacity;    // Вместимость квартиры
    short count;       // Текущее число жителей
};

class House {
public:
    House(short cap) {
        capacity = cap;
        count = 0;
        apartments = new Apartment[capacity];
    }

    // Конструктор копирования
    House(House& other) {
        capacity = other.capacity;
        count = other.count;
        apartments = new Apartment[capacity];
        for (short i = 0; i < count; ++i) {
            // Для каждой квартиры копируем данные вручную, чтобы обеспечить глубокое копирование
            apartments[i].copyFrom(other.apartments[i]);
        }
    }

    // Добавление квартиры
    void addApartment(Apartment& apartment) {
        if (count < capacity) {
            apartments[count].copyFrom(apartment);
            count++;
        }
        else {
            cout << "House is full!" << endl;
        }
    }

    // Деструктор для очистки динамической памяти
    ~House() {
        delete[] apartments;
    }

private:
    Apartment* apartments;
    short capacity;
    short count;
};

int main() {
    // Создаем объекты класса Human с вводом со стороны юзера
    string name;
    short age;

    cout << "Введите имя и возраст для первого жителя квартиры 1:" << endl;
    cin >> name >> age;
    Human h1(name, age);

    cout << "Введите имя и возраст для второго жителя квартиры 1:" << endl;
    cin >> name >> age;
    Human h2(name, age);

    cout << "Введите имя и возраст для жителя квартиры 2:" << endl;
    cin >> name >> age;
    Human h3(name, age);

    // Создаем квартиры с заданной вместимостью
    Apartment apt1(2);  // Квартира на 2 человека
    apt1.addResident(h1);
    apt1.addResident(h2);

    Apartment apt2(1);  // Квартира на 1 человека
    apt2.addResident(h3);

    // Создаем дом, который может содержать 2 квартиры
    House house(2);
    house.addApartment(apt1);
    house.addApartment(apt2);

    // Выводим информацию о квартирах
    cout << "Apartment 1:" << endl;
    apt1.print();
    cout << "Apartment 2:" << endl;
    apt2.print();

    return 0;
}