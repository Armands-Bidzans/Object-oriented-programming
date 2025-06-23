// source.cpp
#include "registration.h"
#include "organizer.h"
#include "poker.h"
#include <iostream>
#include <string>
#include <cstdlib>  // system()
#include <ctime>    // time()

using namespace std;

void solveSudoku() {
    cout << "[Запуск судоку]\n";
}

void runOrganizer() {
    Organizer org;
    org.run();
}

int main() {
    initUsersFile();
    srand(static_cast<unsigned int>(time(nullptr)));  // Рандом — один раз

    string currentUser;
    while (currentUser.empty()) {
        cout << "1 - Регистрация\n2 - Вход\nВыбор: ";
        string choice;
        getline(cin, choice);
        if (choice == "1") {
            if (registerUser()) system("cls");
        }
        else if (choice == "2") {
            if (loginUser(currentUser)) system("cls");
        }
        else {
            cout << "Неверный выбор\n";
        }
    }

    while (true) {
        cout << "\nВыберите задачу:\n"
            << "1 - Покер\n2 - Судоку\n3 - Органайзер\n4 - Выход\nВыбор: ";
        string choice;
        getline(cin, choice);
        if (choice == "1") playPoker();
        else if (choice == "2") solveSudoku();
        else if (choice == "3") runOrganizer();
        else if (choice == "4") break;
        else cout << "Неверный выбор\n";
    }

    cout << "До свидания!\n";
    return 0;
}
// исправить ввод пароля (принимает пустой сейчас)
// добавить цвета и анимации для пароля