#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const string USERS_FILE = "users.txt";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";

inline void initUsersFile() {
    ofstream f(USERS_FILE, ios::app);
}

inline bool registerUser() {
    cout << "Новый логин: ";
    string user;
    getline(cin, user);
    cout << "Новый пароль: ";
    string pass;
    getline(cin, pass);

    if (pass == "") {
        cout << RED << "Ошибка: пароль не может быть пустым" << RESET << '\n';
        return false;
    }

    ofstream file(USERS_FILE, ios::app);
    if (!file) {
        cout << RED << "Ошибка: не удалось создать или открыть файл пользователей" << RESET << '\n';
        return false;
    }
    file << user << ':' << pass << '\n';
    cout << GREEN << "Регистрация выполнена!" << RESET << '\n';
    return true;
}

inline bool loginUser(string& currentUser) {
    cout << "Логин: ";
    string user;
    getline(cin, user);
    cout << "Пароль: ";
    string pass;
    getline(cin, pass);

    ifstream file(USERS_FILE);
    if (!file) {
        cout << RED << "Ошибка: файл пользователей не найден, сначала зарегистрируйтесь" << RESET << '\n';
        return false;
    }
    string line;
    while (getline(file, line)) {
        bool sep = false;
        string u = "", p = "";
        for (char c : line) {
            if (c == ':' && !sep) {
                sep = true;
                continue;
            }
            if (!sep) u += c;
            else p += c;
        }
        if (u == user && p == pass) {
            currentUser = user;
            cout << GREEN << "Вход успешен. Привет, " << user << "!" << RESET << '\n';
            cin.get(); // задержка
            return true;
        }
    }
    cout << RED << "Неверный логин или пароль" << RESET << '\n';
    return false;
}

#endif // REGISTRATION_H
