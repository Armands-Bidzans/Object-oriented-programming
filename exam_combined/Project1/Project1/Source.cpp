#include "registration.h"
#include "organizer.h"
#include <iostream>
#include <string>
#include <cstdlib>  // для system()

using namespace std;

void playPoker() {
    cout << "[Запуск покера]\n";
}

void solveSudoku() {
    cout << "[Запуск судоку]\n";
}

void runOrganizer() {
    Organizer org;
    org.run();
}

int main() {
    initUsersFile();
    string currentUser = "";

    // Регистрация или вход
    while (currentUser == "") {
        cout << "1 - Регистрация\n2 - Вход\nВыбор: ";
        string choice;
        getline(cin, choice);
        if (choice == "1") {
            if (registerUser()) {
                system("cls"); // очистка консоли после регистрации
            }
        }
        else if (choice == "2") {
            if (loginUser(currentUser)) {
                system("cls"); // очистка консоли после входа
            }
        }
        else {
            cout << "Неверный выбор\n";
        }
    }

    // Меню задач после входа
    while (true) {
        cout << "\nВыберите задачу:\n"
            << "1 - Покер\n"
            << "2 - Судоку\n"
            << "3 - Органайзер\n"
            << "4 - Выход\n"
            << "Выбор: ";
        string choice;
        getline(cin, choice);
        if (choice == "1") {
            playPoker();
        }
        else if (choice == "2") {
            solveSudoku();
        }
        else if (choice == "3") {
            runOrganizer();
        }
        else if (choice == "4") {
            break;
        }
        else {
            cout << "Неверный выбор\n";
        }
    }

    cout << "До свидания!\n";
    return 0;
}
