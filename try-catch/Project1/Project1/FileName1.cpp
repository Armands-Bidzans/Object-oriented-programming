#include <iostream>
using namespace std;

const int MAX = 5;

class Stack {
public:
    // Статические поля для хранения данных
    static int arr[MAX];
    static int top;
};

// Определение статических полей
int Stack::arr[MAX];
int Stack::top = -1;

// Ваши свободные функции — никакого вызова методов, только знакомый код:
void push(int value) {
    try {
        if (Stack::top >= MAX - 1)
            throw "Stack overflow!";
        Stack::arr[++Stack::top] = value;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

int pop() {
    try {
        if (Stack::top < 0)
            throw "Stack underflow!";
        return Stack::arr[Stack::top--];
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
        return -1; // Возвращаем -1 как "заглушку", если ошибка
    }
}

int peek() {
    try {
        if (Stack::top < 0)
            throw "Stack is empty!";
        return Stack::arr[Stack::top];
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
        return -1;
    }
}

bool isEmpty() {
    return Stack::top == -1;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // Переполнение

    cout << "Top element: " << peek() << endl;

    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl; // Извлечение из пустого

    return 0;
