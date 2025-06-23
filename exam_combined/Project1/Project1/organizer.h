// organizer.h
#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const string TASKS_FILE = "tasks.txt";
static const int MAX_TASKS = 100;

struct Task {
    int id;
    string desc;
    string dueDate;     // срок выполнения задачи в формате YYYY-MM-DD
    int priority;       // приоритет задачи (1 — низкий, 2 — средний, 3 — высокий)
};

class Organizer {
private:
    Task tasks[MAX_TASKS];
    int count;

    // Загрузка задач из файла
    void load() {
        count = 0;
        ifstream fin(TASKS_FILE);  // Открываем файл для чтения
        if (!fin) return;
        while (count < MAX_TASKS && fin >> tasks[count].id) {
            fin.ignore();  // Пропускаем лишний символ (например, \n)
            getline(fin, tasks[count].desc, '|');
            getline(fin, tasks[count].dueDate, '|');  // Читаем дату до первого вхождения символа '|'
            fin >> tasks[count].priority;  // Читаем приоритет
            fin.ignore();  // Пропускаем лишний символ (например, \n)
            count++;
        }
    }

    // Сохранение задач в файл
    void save() {
        ofstream fout(TASKS_FILE);
        if (!fout) {
            cout << "Ошибка: не могу сохранить задачи\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            fout << tasks[i].id << ":" << tasks[i].desc << "|" << tasks[i].dueDate << "|" << tasks[i].priority << "\n";
        }
    }

    // Получить следующий ID
    int nextId() {
        int maxId = 0;
        for (int i = 0; i < count; i++) {
            if (tasks[i].id > maxId) maxId = tasks[i].id;
        }
        return maxId + 1;
    }

public:
    Organizer() {
        load();
    }

    void addTask(const string& desc, const string& dueDate, int priority) {
        if (count >= MAX_TASKS) {
            cout << "Достигнут максимум задач\n";
            return;
        }
        Task t;
        t.id = nextId();
        t.desc = desc;
        t.dueDate = dueDate;
        t.priority = priority;
        tasks[count++] = t;
        save();
        cout << "Добавлена задача [" << t.id << "]\n";
    }

    void deleteTask(int id) {
        int pos = -1;
        for (int i = 0; i < count; i++) {
            if (tasks[i].id == id) { pos = i; break; }
        }
        if (pos == -1) {
            cout << "Задача не найдена\n";
            return;
        }
        for (int i = pos; i + 1 < count; i++) {
            tasks[i] = tasks[i + 1];
        }
        count--;
        save();
        cout << "Удалена задача [" << id << "]\n";
    }

    void editTask(int id, const string& newDesc, const string& newDueDate, int newPriority) {
        int pos = -1;
        for (int i = 0; i < count; i++) {
            if (tasks[i].id == id) { pos = i; break; }
        }
        if (pos == -1) {
            cout << "Задача не найдена\n";
            return;
        }
        tasks[pos].desc = newDesc;
        tasks[pos].dueDate = newDueDate;
        tasks[pos].priority = newPriority;
        save();
        cout << "Изменена задача [" << id << "]\n";
    }

    void listTasks() {
        if (count == 0) {
            cout << "Список задач пуст\n";
            return;
        }
        cout << "Текущие задачи:\n";
        for (int i = 0; i < count; i++) {
            cout << "[" << tasks[i].id << "] " << tasks[i].desc;
            cout << " (срок: " << tasks[i].dueDate;
            cout << ", приоритет: " << tasks[i].priority << ")\n";
        }
    }

    void run() {
        while (true) {
            cout << "\nОрганайзер:\n";
            cout << "1 - Показать задачи\n";
            cout << "2 - Добавить задачу\n";
            cout << "3 - Редактировать задачу\n";
            cout << "4 - Удалить задачу\n";
            cout << "5 - Назад\n";
            cout << "Выбор: ";

            string choice;
            getline(cin, choice);

            if (choice == "1") {
                listTasks();
            }
            else if (choice == "2") {
                cout << "Описание: ";
                string desc;
                getline(cin, desc);

                cout << "Срок (YYYY-MM-DD): ";
                string dueDate;
                getline(cin, dueDate);

                cout << "Приоритет (1-3): ";
                string pstr;
                getline(cin, pstr);

                int prLen = 0;
                while (pstr[prLen] != '\0') prLen++;

                int priority = 2;
                if (prLen > 0 && pstr[0] >= '1' && pstr[0] <= '3') {
                    priority = pstr[0] - '0';
                }

                addTask(desc, dueDate, priority);
            }
            else if (choice == "3") {
                cout << "ID задачи: ";
                string s;
                getline(cin, s);

                int id = 0;
                for (int i = 0; s[i] != '\0'; i++) {
                    if (s[i] >= '0' && s[i] <= '9') {
                        id = id * 10 + (s[i] - '0');
                    }
                } //  если символ — цифра, прибавляет её к числу id.

                cout << "Новое описание: ";
                string newDesc;
                getline(cin, newDesc);

                cout << "Новая дата: ";
                string newDueDate;
                getline(cin, newDueDate);

                cout << "Новый приоритет (1-3): ";
                string prStr;
                getline(cin, prStr);

                int len = 0;
                while (prStr[len] != '\0') len++;

                int newPriority = 2;
                if (len > 0 && prStr[0] >= '1' && prStr[0] <= '3') {
                    newPriority = prStr[0] - '0';
                } // Если prStr не пустая и начинается с '1', '2' или '3',
                //то newPriority получает это значение (как число). Иначе остаётся 2.

                editTask(id, newDesc, newDueDate, newPriority);
            }
            else if (choice == "4") {
                cout << "ID задачи: ";
                string s;
                getline(cin, s);

                int id = 0;
                for (int i = 0; s[i] != '\0'; i++) {
                    if (s[i] >= '0' && s[i] <= '9') {
                        id = id * 10 + (s[i] - '0');
                    }
                }

                deleteTask(id);
            }
            else if (choice == "5") {
                break;
            }
            else {
                cout << "Неверный выбор\n";
            }
        }
    }
};

#endif // ORGANIZER_H