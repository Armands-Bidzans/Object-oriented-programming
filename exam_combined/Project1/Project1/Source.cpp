#include "registration.h"
#include "organizer.h"
#include "sudoku.h"
#include "poker.h"
#include <iostream>
#include <string>
#include <cstdlib>  // system()
#include <ctime>    // time()

using namespace std;

#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define ORANGE      "\033[33m"
#define LIGHT_GREEN "\033[92m"
#define GRAY        "\033[90m"
#define RESET       "\033[0m"

inline void solveSudoku() {
    sudoku::play();
}

void runOrganizer() {
    Organizer org;
    org.run();
}

int main() {
    // Создаём объект Registration — в его конструкторе уже вызывается initUsersFile()
    Registration reg;

    srand(static_cast<unsigned int>(time(nullptr)));  // Рандом — один раз

    string currentUser = "";  // Начально пустая строка

    while (currentUser == "") {
        cout << GRAY << "1 - Регистрация" << RESET
            << "\n2 - Вход\nВыбор: ";
        string choice;
        getline(cin, choice);
        if (choice == "1") {
            if (reg.registerUser())
                system("cls");
        }
        else if (choice == "2") {
            if (reg.loginUser(currentUser))
                system("cls");
        }
        else {
            system("cls");
            cout << "Неверный выбор\n";
        }
    }

    // Основное меню после входа
    while (true) {
        cout << "\nВыберите задачу:\n"
            << GREEN << "1 - Покер" << RESET << "\n"
            << ORANGE << "2 - Судоку" << RESET << "\n"
            << LIGHT_GREEN << "3 - Органайзер" << RESET << "\n"
            << GRAY << "4 - Выход" << RESET << "\n"
            << "Выбор: ";
        string choice;
        getline(cin, choice);
        if (choice == "1")
            playPoker();
        else if (choice == "2")
            solveSudoku();
        else if (choice == "3")
            runOrganizer();
        else if (choice == "4")
            break;
        else
            system("cls");
            cout << "Неверный выбор\n";
    }

    cout << "До свидания!\n";
    return 0;
}
