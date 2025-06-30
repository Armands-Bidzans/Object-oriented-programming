#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <array>
#include <cctype>

using namespace std;

// Пользовательская функция swap
template <typename T>
void swap(T* a, T* b) {
    T temp = *a;
    a = b;
    *b = temp;
}

namespace sudoku {

    using Board = array<array<int, 9>, 9>;

    inline void printBoard(const Board& b) {
        cout << "   1 2 3   4 5 6   7 8 9\n";
        for (int r = 0; r < 9; ++r) {
            if (r % 3 == 0) cout << "  +-------+-------+-------+\n";
            cout << static_cast<char>('A' + r) << " |";
            for (int c = 0; c < 9; ++c) {
                if (b[r][c] == 0) cout << " .";
                else cout << " " << b[r][c];
                if ((c + 1) % 3 == 0) cout << " |";
            }
            cout << "\n";
        }
        cout << "  +-------+-------+-------+\n";
    }

    inline bool isValidMove(const Board& b, int row, int col, int val) {
        for (int i = 0; i < 9; ++i) {
            if (b[row][i] == val || b[i][col] == val) return false;
        }
        int br = (row / 3) * 3;
        int bc = (col / 3) * 3;
        for (int r = br; r < br + 3; ++r) {
            for (int c = bc; c < bc + 3; ++c) {
                if (b[r][c] == val) return false;
            }
        }
        return true;
    }

    inline bool fillBoard(Board& b, int cell = 0) {
        if (cell == 81) return true;
        int row = cell / 9;
        int col = cell % 9;
        if (b[row][col] != 0) return fillBoard(b, cell + 1);
        array<int, 9> nums = { 1,2,3,4,5,6,7,8,9 };
        for (int i = 8; i > 0; --i) {
            int j = rand() % (i + 1);
            // используем пользовательскую swap
            swap(&nums[i], &nums[j]);
        }
        for (int idx = 0; idx < 9; ++idx) {
            int v = nums[idx];
            if (isValidMove(b, row, col, v)) {
                b[row][col] = v;
                if (fillBoard(b, cell + 1)) return true;
                b[row][col] = 0;
            }
        }
        return false;
    }

    inline void generatePuzzle(Board& initial, Board& solution) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                initial[r][c] = 0;
                solution[r][c] = 0;
            }
        }
        fillBoard(solution);
        initial = solution;
        int removeCount = 40;
        while (removeCount > 0) {
            int rr = rand() % 9;
            int cc = rand() % 9;
            if (initial[rr][cc] != 0) {
                initial[rr][cc] = 0;
                --removeCount;
            }
        }
    }

    inline bool isComplete(const Board& b, const Board& solution) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (b[r][c] != solution[r][c]) return false;
            }
        }
        return true;
    }

    inline void play() {
        Board initial;
        Board solution;
        generatePuzzle(initial, solution);
        Board board = initial;
        string input;
        while (true) {
            // Очищаем экран и выводим доску
            system("cls");
            printBoard(board);
            if (isComplete(board, solution)) {
                cout << "Поздравляем, судоку решено!\n";
                break;
            }
            cout << "Введите ход (например A1 5) или \"q\" для выхода: ";
            if (!getline(cin, input)) break;
            // Очищаем экран перед отображением результата хода
            system("cls");
            if (input == "q" || input == "Q") break;
            if (input.size() >= 4) {
                int row = toupper(input[0]) - 'A';
                int col = input[1] - '1';
                int val = input[3] - '0';
                if (row >= 0 && row < 9 && col >= 0 && col < 9 && val >= 1 && val <= 9) {
                    if (initial[row][col] == 0 && isValidMove(board, row, col, val)) {
                        board[row][col] = val;
                    }
                    else {
                        cout << "Неверный ход. Попробуйте снова.\n";
                    }
                }
                else {
                    cout << "Некорректный ввод. Формат: A1 5\n";
                }
            }
            else {
                cout << "Некорректный ввод. Формат: A1 5\n";
            }
            // Задержка, чтобы пользователь успел прочитать сообщение
            cin.get();
        }
    }

}
#endif // SUDOKU_H