#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Карта
class Card {
public:
    int code; // 0..51
    Card() : code(-1) {}
    Card(int c) : code(c) {}
};

// Колода
class Deck {
public:
    int cards[52];
    int top;
    Deck() {
        // Создаем и тасуем в конструкторе
        for (int i = 0; i < 52; ++i) cards[i] = i;
        top = 0;
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 51; i > 0; --i) {
            int j = rand() % (i + 1);
            int tmp = cards[i]; cards[i] = cards[j]; cards[j] = tmp;
        }
    }
    Card getCard() {
        if (top >= 52) throw "Колода пуста";
        return Card(cards[top++]);
    }
};

// Рука
class Hand {
public:
    Card c[5];
    int cat;    // категория
    int tb[5];  // для сравнения
    Hand() : cat(0) {}
    void score() {
        int freq[13] = { 0 }, vals[5];
        for (int i = 0; i < 5; ++i) {
            int r = c[i].code % 13;
            freq[r]++;
            vals[i] = r;
        }
        // пузырь
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4 - i; ++j)
                if (vals[j] > vals[j + 1]) {
                    int t = vals[j]; vals[j] = vals[j + 1]; vals[j + 1] = t;
                }
        bool fl = true;
        int s0 = c[0].code / 13;
        for (int i = 1; i < 5; ++i)
            if (c[i].code / 13 != s0) fl = false;
        bool st = true;
        for (int i = 1; i < 5; ++i)
            if (vals[i] != vals[i - 1] + 1) st = false;
        if (!st && vals[0] == 0 && vals[1] == 1 && vals[2] == 2 && vals[3] == 3 && vals[4] == 12) {
            st = true; vals[4] = 3;
        }
        int c2 = 0, c3 = 0, c4 = 0;
        for (int i = 0; i < 13; ++i) {
            if (freq[i] == 2) c2++;
            if (freq[i] == 3) c3++;
            if (freq[i] == 4) c4++;
        }
        if (st && fl)      cat = 8;
        else if (c4 == 1)    cat = 7;
        else if (c3 == 1 && c2 == 1) cat = 6;
        else if (fl)       cat = 5;
        else if (st)       cat = 4;
        else if (c3 == 1)    cat = 3;
        else if (c2 == 2)    cat = 2;
        else if (c2 == 1)    cat = 1;
        else               cat = 0;
        for (int i = 0; i < 5; ++i) tb[i] = vals[4 - i];
    }
    void show() {
        const char* R = "23456789TJQKA";
        const char* S = "CDHS";
        for (int i = 0; i < 5; ++i) {
            int rc = c[i].code % 13;
            int sc = c[i].code / 13;
            cout << R[rc] << S[sc] << " ";
        }
    }
};

int main() {
    try {
        Deck deck; // сразу готова
        const int P = 2;
        Hand h[P];
        for (int p = 0; p < P; ++p)
            for (int i = 0; i < 5; ++i)
                h[p].c[i] = deck.getCard();
        for (int p = 0; p < P; ++p) {
            h[p].score();
            cout << "Игрок " << p + 1 << ": ";
            h[p].show();
            cout << "=> " << h[p].cat << endl;
        }
        int w = 0;
        for (int p = 1; p < P; ++p) {
            if (h[p].cat > h[w].cat) w = p;
            else if (h[p].cat == h[w].cat) {
                for (int i = 0; i < 5; ++i) {
                    if (h[p].tb[i] > h[w].tb[i]) { w = p; break; }
                    if (h[p].tb[i] < h[w].tb[i]) break;
                }
            }
        }
        cout << "Победитель: Игрок " << w + 1 << endl;
    }
    catch (const char* e) {
        cout << "Ошибка: " << e << endl;
    }
    return 0;
}
//  для tester class person, class user, class question, open type
// для admin части регистрация авторизация
// string root - путь