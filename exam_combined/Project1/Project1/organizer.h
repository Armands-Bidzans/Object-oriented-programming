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
};

class Organizer {
private:
    Task tasks[MAX_TASKS];
    int count;

    // Загрузка задач из файла
    void load() {
        count = 0;
        ifstream fin(TASKS_FILE);
        if (!fin) return;
        char line[256];
        while (count < MAX_TASKS && fin.getline(line, 256)) {
            char num[16] = "";
            string text = "";
            bool sep = false;
            int ni = 0;
            for (int i = 0; line[i] != '\0'; i++) {
                if (!sep) {
                    if (line[i] == ':') sep = true;
                    else if (line[i] >= '0' && line[i] <= '9') num[ni++] = line[i];
                }
                else {
                    text += line[i];
                }
            }
            if (ni == 0) continue;
            num[ni] = '\0';
            int nid = 0;
            for (int i = 0; num[i] != '\0'; i++) {
                nid = nid * 10 + (num[i] - '0');
            }
            tasks[count].id = nid;
            tasks[count].desc = text;
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
            fout << tasks[i].id << ":" << tasks[i].desc << "\n";
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

    void addTask(const string& desc) {
        if (count >= MAX_TASKS) {
            cout << "Достигнут максимум задач\n";
            return;
        }
        Task t;
        t.id = nextId();
        t.desc = desc;
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

    void editTask(int id, const string& newDesc) {
        int pos = -1;
        for (int i = 0; i < count; i++) {
            if (tasks[i].id == id) { pos = i; break; }
        }
        if (pos == -1) {
            cout << "Задача не найдена\n";
            return;
        }
        tasks[pos].desc = newDesc;
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
            cout << "[" << tasks[i].id << "] " << tasks[i].desc << "\n";
        }
    }

    void run() {
        string choice;
        while (true) {
            cout << "\nОрганайзер:\n"
                << "1 - Показать задачи\n"
                << "2 - Добавить задачу\n"
                << "3 - Редактировать задачу\n"
                << "4 - Удалить задачу\n"
                << "5 - Назад\n"
                << "Выбор: ";
            getline(cin, choice);
            if (choice == "1") listTasks();
            else if (choice == "2") {
                cout << "Описание: ";
                string d; getline(cin, d);
                addTask(d);
            }
            else if (choice == "3") {
                cout << "ID задачи: "; string s; getline(cin, s);
                int id = 0;
                for (int i = 0; s[i] != '\0'; i++) {
                    if (s[i] >= '0' && s[i] <= '9') id = id * 10 + (s[i] - '0');
                }
                cout << "Новое описание: "; string d; getline(cin, d);
                editTask(id, d);
            }
            else if (choice == "4") {
                cout << "ID задачи: "; string s; getline(cin, s);
                int id = 0;
                for (int i = 0; s[i] != '\0'; i++) {
                    if (s[i] >= '0' && s[i] <= '9') id = id * 10 + (s[i] - '0');
                }
                deleteTask(id);
            }
            else if (choice == "5") break;
            else cout << "Неверный выбор\n";
        }
    }
};

#endif // ORGANIZER_H