#include <iostream>
using namespace std;

class String {
private:
    char* str;
    int size;

public:
    String() {
        size = 80;             // инициализируем размер
        str = new char[size];  // выделяем память под строку
    }
    String(int s) {
        size = s;
        str = new char[size];
    }
    // Конструктор копирования
    String(const String& other) {
        size = other.size;
        str = new char[size];
        for (int i = 0; i < size; ++i)
            str[i] = other.str[i];
    }
    String(const char* s) {
        size = 0;
        while (s[size]) size++;
        str = new char[size + 1];
        for (int i = 0; i <= size; i++)
            str[i] = s[i];
    }

    ~String() {
        delete[] str;
    }

    void input() {
        cout << "Enter string: ";
        cin.getline(str, size);
    }
    void output() const {
        cout << "String: " << str << endl;
    }
};

int main() {
    String s1;
    s1.input();
    s1.output();

    String s2(50);
    s2.input();
    s2.output();

    return 0;
}