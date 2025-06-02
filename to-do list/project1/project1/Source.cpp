#include <iostream>
#include <string>
using namespace std;

// Базовый класс для хранения и вывода текста задачи
class Text {
protected:
    string text;
public:
    Text(const string& t) : text(t) {}
    virtual ~Text() {}

    // Виртуальный метод для вывода задачи
    virtual void print() const {
        // Изменено: выводим с префиксом "simple task: "
        cout << "simple task: " << text << endl;
    }
};

// Производный класс для «важной задачи»
// При выводе добавляет восклицательные зназки
class GreatTask : public Text {
public:
    GreatTask(const string& t) : Text(t) {}

    // Переопределяем метод базового класса
    void print() const override {
        // Изменено: выводим в формате "important task <текст> !!!"
        cout << "important task " << text << " !!!" << endl;
    }
};

// Производный класс для «срочной задачи» (с дедлайном)
// Добавляет поля месяца и дня
class DeadLineTask : public Text {
private:
    int month;
    int day;
public:
    DeadLineTask(const string& t, int m, int d)
        : Text(t), month(m), day(d) {}

    // Переопределяем метод базового класса
    void print() const override {
        // Изменено: выводим в формате "deadline time: месяц.день <текст>"
        cout << "deadline time: " << month << "." << day << " " << text << endl;
    }
};

// Производный класс для «ежедневной задачи»
// Добавляет поля часов и минут
class DailyTask : public Text {
private:
    int hour;
    int minute;
public:
    // Конструктор с указанием часов и минут (по умолчанию минуты = 0)
    DailyTask(const string& t, int h, int m = 0)
        : Text(t), hour(h), minute(m) {}

    // Переопределяем метод базового класса
    void print() const override {
        // Форматируем часы и минуты двумя цифрами
        cout << "Time: ";
        if (hour < 10) cout << '0';
        cout << hour << ":";
        if (minute < 10) cout << '0';
        cout << minute << " " << text << endl;
    }
};

int main() {
    const int MAX_TASKS = 100;
    Text* all[MAX_TASKS];
    int count = 0;

    while (true) {
        cout << "\n=== Меню ===\n";
        cout << "1. Добавить простую задачу\n";
        cout << "2. Добавить важную задачу\n";
        cout << "3. Добавить задачу с дедлайном\n";
        cout << "4. Добавить ежедневную задачу\n";
        cout << "5. Удалить задачу\n";
        cout << "6. Показать все задачи\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0) {
            break;
        }
        cin.ignore(10000, '\n');  // сбросить остаток строки

        if (choice == 1) {
            if (count >= MAX_TASKS) {
                cout << "Невозможно добавить задачу: достигнуто максимальное количество.\n";
                continue;
            }
            cout << "Введите текст простой задачи: ";
            string txt;
            getline(cin, txt);
            all[count++] = new Text(txt);

        }
        else if (choice == 2) {
            if (count >= MAX_TASKS) {
                cout << "Невозможно добавить задачу: достигнуто максимальное количество.\n";
                continue;
            }
            cout << "Введите текст важной задачи: ";
            string txt;
            getline(cin, txt);
            all[count++] = new GreatTask(txt);

        }
        else if (choice == 3) {
            if (count >= MAX_TASKS) {
                cout << "Невозможно добавить задачу: достигнуто максимальное количество.\n";
                continue;
            }
            cout << "Введите текст задачи с дедлайном: ";
            string txt;
            getline(cin, txt);
            int m, d;
            cout << "Введите месяц дедлайна (1-12): ";
            cin >> m;
            cout << "Введите день дедлайна (1-31): ";
            cin >> d;
            cin.ignore(10000, '\n');
            all[count++] = new DeadLineTask(txt, m, d);

        }
        else if (choice == 4) {
            if (count >= MAX_TASKS) {
                cout << "Невозможно добавить задачу: достигнуто максимальное количество.\n";
                continue;
            }
            cout << "Введите текст ежедневной задачи: ";
            string txt;
            getline(cin, txt);
            int h, mi;
            cout << "Введите час (0-23): ";
            cin >> h;
            cout << "Введите минуты (0-59) или оставьте пустым для 00: ";
            if (!(cin >> mi)) {
                mi = 0;
                cin.clear();
            }
            cin.ignore(10000, '\n');
            all[count++] = new DailyTask(txt, h, mi);

        }
        else if (choice == 5) {
            if (count == 0) {
                cout << "Список задач пуст.\n";
                continue;
            }
            cout << "Введите номер задачи для удаления (1-" << count << "): ";
            int idx;
            cin >> idx;
            cin.ignore(10000, '\n');
            if (idx < 1 || idx > count) {
                cout << "Неверный номер.\n";
                continue;
            }
            // Удаляем задачу и сдвигаем массив
            delete all[idx - 1];
            for (int i = idx - 1; i < count - 1; ++i) {
                all[i] = all[i + 1];
            }
            --count;
            cout << "Задача удалена.\n";

        }
        else if (choice == 6) {
            if (count == 0) {
                cout << "Список задач пуст.\n";
                continue;
            }
            // Оставляем заголовок и последующий вывод задач
            cout << "\nTo Do List.\n\n";
            for (int i = 0; i < count; ++i) {
                all[i]->print();
            }

        }
        else {
            cout << "Неверный пункт. Попробуйте снова.\n";
        }
    }

    // Освобождаем память перед выходом
    for (int i = 0; i < count; ++i) {
        delete all[i];
    }

    cout << "Выход.\n";
    return 0;
}
