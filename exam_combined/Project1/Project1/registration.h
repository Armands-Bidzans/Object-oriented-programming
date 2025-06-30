#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Registration {
protected:
    static const string ADMIN_USER;
    static const string ADMIN_PASS;

private:
    static const string USERS_FILE;
    static const string RED;
    static const string GREEN;
    static const string RESET;

    void initUsersFile() {
        ofstream f(USERS_FILE.c_str(), ios::app);
    }

    void deleteAllUsers() {
        ofstream file(USERS_FILE.c_str(), ios::trunc);
        if (!file) {
            cout << RED << "Ошибка: не удалось очистить файл пользователей" << RESET << '\n';
            return;
        }
        file << ADMIN_USER << ':' << ADMIN_PASS << '\n';
        cout << GREEN << "Все профили удалены. Остается только администратор." << RESET << '\n';
    }

    bool isLoginTaken(const string& user) {
        ifstream infile(USERS_FILE.c_str());
        if (!infile) return false;
        string line;
        while (getline(infile, line)) {
            bool sepFound = false;
            string name = "";
            for (char c : line) {
                if (!sepFound && c == ':') {
                    sepFound = true;
                }
                else if (!sepFound) {
                    name += c;
                }
                else {
                    // дальше нам не нужно ничего
                }
            }
            if (name == user || user == ADMIN_USER) {
                return true;
            }
        }
        return false;
    }

    int manualLength(const string& s) {
        int cnt = 0;
        for (char c : s) {
            (void)c;
            ++cnt;
        }
        return cnt;
    }

public:
    Registration() {
        initUsersFile();
    }

    bool registerUser() {
        cout << "Новый логин: ";
        string user;
        getline(cin, user);

        if (isLoginTaken(user)) {
            cout << RED << "Ошибка: логин уже зарегистрирован" << RESET << '\n';
            return false;
        }

        cout << "Новый пароль: ";
        string pass;
        getline(cin, pass);

        if (manualLength(pass) < 4) {
            cout << RED << "Ошибка: пароль должен содержать не менее 4 символов" << RESET << '\n';
            return false;
        }

        ofstream file(USERS_FILE.c_str(), ios::app);
        if (!file) {
            cout << RED << "Ошибка: не удалось открыть файл пользователей" << RESET << '\n';
            return false;
        }
        file << user << ':' << pass << '\n';
        cout << GREEN << "Регистрация выполнена!" << RESET << '\n';
        return true;
    }

    bool loginUser(string& currentUser) {
        cout << "Логин: ";
        string user;
        getline(cin, user);
        cout << "Пароль: ";
        string pass;
        getline(cin, pass);

        // Админ
        if (user == ADMIN_USER && pass == ADMIN_PASS) {
            currentUser = ADMIN_USER;
            cout << GREEN << "Вход админа успешен!" << RESET << '\n';
            cout << "Удалить все профили кроме админа? (y/n): ";
            string answer;
            getline(cin, answer);
            if (manualLength(answer) > 0 && (answer[0] == 'y' || answer[0] == 'Y')) {
                deleteAllUsers();
            }
            return true;
        }

        ifstream file(USERS_FILE.c_str());
        if (!file) {
            cout << RED << "Ошибка: сначала зарегистрируйтесь" << RESET << '\n';
            return false;
        }

        string line;
        while (getline(file, line)) {
            bool sep = false;
            string u = "", p = "";
            for (char ch : line) {
                if (!sep && ch == ':') {
                    sep = true;
                }
                else if (!sep) {
                    u += ch;
                }
                else {
                    p += ch;
                }
            }
            if (u == user && p == pass) {
                currentUser = user;
                cout << GREEN << "Вход успешен. Привет, " << user << "!" << RESET << '\n';
                // пауза
                string dummy;
                getline(cin, dummy);
                return true;
            }
        }

        cout << RED << "Неверный логин или пароль" << RESET << '\n';
        return false;
    }
};

// Статические константы
const string Registration::USERS_FILE = "users.txt";
const string Registration::RED = "\033[31m";
const string Registration::GREEN = "\033[32m";
const string Registration::RESET = "\033[0m";
const string Registration::ADMIN_USER = "admin";
const string Registration::ADMIN_PASS = "admin";

#endif // REGISTRATION_H