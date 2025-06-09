#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class SlotMachine {
private:
    static const int n = 4;                     // количество символов на барабане
    string symbols[n];                           // массив символов
public:
    SlotMachine() {
        symbols[0] = "Cherry";
        symbols[1] = "Lemon";
        symbols[2] = "Orange";
        symbols[3] = "Seven";
    }

    void playRound() {
        // Генерируем случайное число вращений для каждого барабана
        int spins1 = rand() % 10 + 1;
        int spins2 = rand() % 10 + 1;
        int spins3 = rand() % 10 + 1;

        // Начальный индекс символа
        int idx1 = 0, idx2 = 0, idx3 = 0;

        // Симуляция вращения (вычисляем конечный индекс через цикл)
        for (int i = 0; i < spins1; i++) {
            idx1 = (idx1 + 1);
            if (idx1 == n) idx1 = 0;
        }
        for (int i = 0; i < spins2; i++) {
            idx2 = (idx2 + 1);
            if (idx2 == n) idx2 = 0;
        }
        for (int i = 0; i < spins3; i++) {
            idx3 = (idx3 + 1);
            if (idx3 == n) idx3 = 0;
        }

        // Показываем результат
        cout << "[ " << symbols[idx1]
            << " | " << symbols[idx2]
                << " | " << symbols[idx3] << " ]\n";

                // Проверяем выигрыш
                if (idx1 == idx2 && idx2 == idx3) {
                    cout << "Поздравляем! Все три совпали. Вы выиграли!\n";
                }
                else {
                    cout << "Нет совпадений. Попробуйте ещё раз.\n";
                }
                cout << "-----------------------------\n";
                cout << "Нажмите Enter для нового вращения или 'q' + Enter для выхода.\n";
    }
};

int main() {
    srand(time(NULL));

    SlotMachine machine;

    cout << "=== Однорукий бандит ===\n";
    cout << "Для вращения нажмите Enter (или введите 'q' + Enter для выхода).\n";

    while (true) {
        string input;
        getline(cin, input);

        if (input == "q") {
            break;
        }

        machine.playRound();
    }

    cout << "Игра окончена. Спасибо за игру!\n";
    return 0;
}
