#include <iostream>
using namespace std;

class Array
{
public:
    Array() {
        data = 0;
        size = 0;
    }

    // Конструктор с параметром, создающий массив заданного размера
    Array(short size) {
        this->size = size;  // присваиваем размер
        if (size > 0) {
            data = new int[size];
        }
        else {
            data = 0;
        }
    }

    // Конструктор копирования (принимает параметр по константной ссылке)
    Array(const Array& other) {
        size = other.size;  // копируем размер
        if (size > 0) {
            data = new int[size]; // выделяем память для нового массива
            for (short i = 0; i < size; i++) {
                data[i] = other.data[i];  // копируем каждый элемент
            }
        }
        else {
            data = 0;
        }
    }

    // Деструктор для освобождения выделенной памяти
    ~Array() {
        delete[] data;
    }

    // Метод для заполнения массива значениями, вводимых пользователем
    void fill() {
        for (short i = 0; i < size; i++) {
            cout << "Введите элемент " << i << ": ";
            cin >> data[i];
        }
    }

    // Метод для отображения содержимого массива
    void display() {
        for (short i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Метод для изменения размера массива
    void resize(int newSize) {
        int* newData = 0;
        if (newSize > 0) {
            newData = new int[newSize];
            int minSize;
            if (newSize < size) {
                minSize = newSize;
            }
            else {
                minSize = size;
            }
            for (short i = 0; i < minSize; i++) {
                newData[i] = data[i];
            }
            for (short i = minSize; i < newSize; i++) {
                newData[i] = 0; // инициализируем новые элементы нулями
            }
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    // Метод для сортировки массива (сортировка пузырьком)
    void sort() {
        for (short i = 0; i < size - 1; i++) {
            for (short j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    // обмен элементов
                    int temp = data[j];  // используем int для хранения элемента
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    // Метод для получения минимального значения в массиве
    int getMin() {
        if (size == 0) {
            cout << "Массив пуст!" << endl;
            return -1;
        }
        int minVal = data[0];
        for (short i = 1; i < size; i++) {
            if (data[i] < minVal)
                minVal = data[i];
        }
        return minVal;
    }

    // Метод для получения максимального значения в массиве
    int getMax() {
        if (size == 0) {
            cout << "Массив пуст!" << endl;
            return -1;
        }
        int maxVal = data[0];
        for (short i = 1; i < size; i++) {
            if (data[i] > maxVal)
                maxVal = data[i];
        }
        return maxVal;
    }

private:
    int* data;
    int size;
};


int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    // Создаем массив заданного размера
    Array arr(size);

    // Заполнение массива пользователем
    arr.fill();
    cout << "Содержимое массива: ";
    arr.display();

    // Сортировка массива
    cout << "Сортировка массива..." << endl;
    arr.sort();
    cout << "Отсортированный массив: ";
    arr.display();

    // Определение минимального и максимального значения
    int minVal = arr.getMin();
    int maxVal = arr.getMax();
    cout << "Минимальное значение: " << minVal << endl;
    cout << "Максимальное значение: " << maxVal << endl;

    // Изменение размера массива
    int newSize;
    cout << "Введите новый размер массива: ";
    cin >> newSize;
    arr.resize(newSize);
    cout << "Массив после изменения размера: ";
    arr.display();

    return 0;
}
