#pragma once
#ifndef POKER_H
#define POKER_H

#include <iostream>
#include <cstdlib>  // rand(), system()
#include <string>

using namespace std;

static const int MAX_SCORE = 21;
static const int JACK = 11;
static const int QUEEN = 12;
static const int KING = 13;
static const int ACE = 15;  // туз

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Примитивная функция, превращающая int в string без to_string и без потоков
inline string intToString(int v) {
    if (v == 0) {
        return "0";
    }
    bool negative = false;
    if (v < 0) {
        negative = true;
        v = -v;
    }
    string s;
    while (v > 0) {
        int digit = v % 10;
        char c = '0' + digit;
        // приписываем символ в начало строки
        s = c + s;
        v = v / 10;
    }
    if (negative) {
        s = "-" + s;
    }
    return s;
}

class Poker {
public:
    Poker() {}

    void run() {
        int playerSum = 0, dealerSum = 0;
        bool playerStand = false, dealerStand = false;
        string choice;

        // Основной игровой цикл
        while (playerSum <= MAX_SCORE && dealerSum <= MAX_SCORE
            && (playerStand == false || dealerStand == false)) {

            system("cls");
            cout << "=== Игра «Покер» (поочерёдные ходы) ===\n";

            // --- Ход игрока ---
            if (playerStand == false) {
                cout << "\nВаш ход: тянуть карту? (y/n): ";
                getline(cin, choice);
                if (choice == "y" || choice == "Y") {
                    int c = drawCard();
                    playerSum = playerSum + c;
                    cout << "Вам выпала " << cardName(c)
                        << " (" << c << "), сумма = " << playerSum << "\n";
                    if (playerSum > MAX_SCORE) {
                        cout << RED << "Перебор! Вы проиграли.\n" << RESET;
                        pauseAndClear();
                        return;
                    }
                }
                else {
                    playerStand = true;
                    cout << "Вы встали на " << playerSum << "\n";
                }
            }

            // --- Ход дилера ---
            if (dealerStand == false) {
                if (dealerSum < 17) {
                    int c = drawCard();
                    dealerSum = dealerSum + c;
                    cout << "Дилер тянет " << cardName(c)
                        << " (" << c << "), сумма = " << dealerSum << "\n";
                    if (dealerSum > MAX_SCORE) {
                        cout << GREEN << "Дилер перебрал! Вы выиграли.\n" << RESET;
                        pauseAndClear();
                        return;
                    }
                }
                else {
                    dealerStand = true;
                    cout << "Дилер встал на " << dealerSum << "\n";
                }
            }

            // Пауза перед следующим «кадром»
            cout << "\n(Нажмите Enter для продолжения хода)";
            getline(cin, choice);
        }

        // Финальный экран — очищаем и показываем результат
        system("cls");
        cout << "=== Игра «Покер» — Результаты ===\n\n";
        cout << "Ваши очки:   " << playerSum << "\n";
        cout << "Очки дилера: " << dealerSum << "\n\n";
        if (playerSum > dealerSum) {
            cout << GREEN << "Поздравляем, вы выиграли!\n" << RESET;
        }
        else if (playerSum == dealerSum) {
            cout << YELLOW << "Ничья! По правилам дилер выигрывает.\n" << RESET;
        }
        else {
            cout << RED << "Вы проиграли.\n" << RESET;
        }

        pauseAndClear();
    }

private:
    int drawCard() {
        int r = rand() % 13 + 2; // 2..14
        if (r == 14) {
            return ACE;
        }
        return r;
    }

    string cardName(int v) {
        if (v >= 2 && v <= 10) {
            return intToString(v); // Чтобы игрок видел карту в виде текста (например, "7"), а не просто число внутри кода — иначе её нельзя корректно вывести в cout, где требуется string.
        }
        if (v == JACK) {
            return "валет";
        }
        if (v == QUEEN) {
            return "дама";
        }
        if (v == KING) {
            return "король";
        }
        return "туз";
    }

    void pauseAndClear() {
        cout << "\nНажмите Enter, чтобы продолжить...";
        string tmp;
        getline(cin, tmp);
        system("cls");
    }
};

inline void playPoker() {
    Poker game;
    game.run();
}

#endif // POKER_H