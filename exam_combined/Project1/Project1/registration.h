#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const string USERS_FILE = "users.txt";  // файл в текущей директории

// Создает файл пользователей, если его нет
inline void initUsersFile() {
    ofstream f(USERS_FILE, ios::app);
    // при открытии в режиме append файл создается автоматически
}

// Регистрирует нового пользователя, возвращает true при успехе
inline bool registerUser() {
    cout << "Новый логин: ";
    string user;
    getline(cin, user);
    cout << "Новый пароль: ";
    string pass;
    getline(cin, pass);
    ofstream file(USERS_FILE, ios::app);
    if (!file) {
        cout << "Ошибка: не удалось создать или открыть файл пользователей\n";
        return false;
    }
    file << user << ':' << pass << '\n';
    cout << "Регистрация выполнена!\n";
    return true;
}

// Пытается выполнить вход, записывает имя в currentUser, возвращает true при успешном входе
inline bool loginUser(string& currentUser) {
    cout << "Логин: ";
    string user;
    getline(cin, user);
    cout << "Пароль: ";
    string pass;
    getline(cin, pass);

    ifstream file(USERS_FILE);
    if (!file) {
        cout << "Ошибка: файл пользователей не найден, сначала зарегистрируйтесь\n";
        return false;
    }
    string line;
    while (getline(file, line)) {
        bool sep = false;
        string u = "", p = "";
        for (char c : line) {
            if (c == ':' && !sep) { sep = true; continue; }
            if (!sep) u += c;
            else p += c;
        }
        if (u == user && p == pass) {
            currentUser = user;
            cout << "Вход успешен. Привет, " << user << "!\n";
            return true;
        }
    }
    cout << "Неверный логин или пароль\n";
    return false;
}
#endif // REGISTRATION_H