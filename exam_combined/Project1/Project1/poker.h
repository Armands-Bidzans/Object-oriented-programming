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

class Poker {
public:
    Poker() {}

    void run() {
        int playerSum = 0, dealerSum = 0;
        bool playerStand = false, dealerStand = false;
        string choice;

        cout << "=== Игра «Покер» (поочерёдные ходы) ===\n";

        // пока оба не стоят и никто не перебрал
        while (playerSum <= MAX_SCORE && dealerSum <= MAX_SCORE
            && (!playerStand || !dealerStand)) {

            // --- Ход игрока ---
            if (!playerStand) {
                cout << "\nВаш ход: тянуть карту? (y/n): ";
                getline(cin, choice);
                if (choice == "y" || choice == "Y") {
                    int c = drawCard();
                    playerSum += c;
                    cout << "Вам выпала " << cardName(c)
                        << " (" << c << "), сумма = " << playerSum << "\n";
                    if (playerSum > MAX_SCORE) {
                        cout << "Перебор! Вы проиграли.\n";
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
            if (!dealerStand) {
                // дилер тянет, пока не наберёт хотя бы 17
                if (dealerSum < 17) {
                    int c = drawCard();
                    dealerSum += c;
                    cout << "Дилер тянет " << cardName(c)
                        << " (" << c << "), сумма = " << dealerSum << "\n";
                    if (dealerSum > MAX_SCORE) {
                        cout << "Дилер перебрал! Вы выиграли.\n";
                        pauseAndClear();
                        return;
                    }
                }
                else {
                    dealerStand = true;
                    cout << "Дилер встал на " << dealerSum << "\n";
                }
            }
        }

        // Сравниваем, если оба не перебрали
        cout << "\nИтоги: ваш " << playerSum
            << ", дилера " << dealerSum << "\n";
        if (playerSum > dealerSum)
            cout << "Поздравляем, вы выиграли!\n";
        else if (playerSum == dealerSum)
            cout << "Ничья! По правилам дилер выигрывает.\n";
        else
            cout << "Вы проиграли.\n";

        pauseAndClear();
    }

private:
    int drawCard() {
        int r = rand() % 13 + 2; // 2..14
        if (r == 14) return ACE;
        return r;
    }

    string cardName(int v) {
        if (v >= 2 && v <= 10) return to_string(v);
        if (v == JACK)  return "валет";
        if (v == QUEEN) return "дама";
        if (v == KING)  return "король";
        return "туз";
    }

    void pauseAndClear() {
        cout << "Нажмите Enter, чтобы продолжить...";
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
