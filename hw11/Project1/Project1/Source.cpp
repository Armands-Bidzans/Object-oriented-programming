#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    short year;
    short quantity;
    short pages;
public:
    Book() {
        author = "";
        title = "";
        publisher = "";
        year = 0;
        quantity = 0;
        pages = 0;
    }

    Book(string a, string t, string p, short y, short q, short pg) {
        author = a;
        title = t;
        publisher = p;
        year = y;
        quantity = q;
        pages = pg;
    }

    // Геттеры для доступа к закрытым данным
    string getAuthor() { return author; }
    string getPublisher() { return publisher; }
    int getYear() { return year; }

    // Функция для вывода информации о книге
    void print() {
        cout << "Автор: " << author
            << ", Название: " << title
            << ", Издательство: " << publisher
            << ", Год: " << year
            << ", Количество экземпляров: " << quantity
            << ", Страниц: " << pages << endl;
    }
};

int main() {
    short n;

    cout << "Введите количество книг: ";
    cin >> n;
    // После ввода числа в потоке остаётся символ перевода строки, который может помешать корректному считыванию строк.
    // Поэтому используется cin.ignore() для очистки буфера.
    cin.ignore();

    // Создаём динамический массив объектов Book
    Book* library = new Book[n];

    for (short i = 0; i < n; i++) {
        string author, title, publisher;
        short year, quantity, pages;

        cout << "\nКнига " << i + 1 << endl;

        cout << "Введите автора: ";
        getline(cin, author);

        cout << "Введите название: ";
        getline(cin, title);

        cout << "Введите издательство: ";
        getline(cin, publisher);

        cout << "Введите год издания: ";
        cin >> year;
        cout << "Введите количество экземпляров: ";
        cin >> quantity;
        cout << "Введите количество страниц: ";
        cin >> pages;

        // После ввода числовых значений снова очищаем буфер,
        // чтобы следующий getline() не считал оставшийся символ перевода строки.
        cin.ignore();

        // Сохраняем данные в массиве
        library[i] = Book(author, title, publisher, year, quantity, pages);
    }

    cout << "\nСведения о книгах:\n";
    for (short i = 0; i < n; i++) {
        library[i].print();
    }

    // Фильтрация по автору
    string searchAuthor;
    cout << "\nВведите автора для поиска: ";
    getline(cin, searchAuthor);
    cout << "\nСписок книг заданного автора:\n";
    bool foundAuthor = false;
    for (short i = 0; i < n; i++) {
        if (library[i].getAuthor() == searchAuthor) {
            library[i].print();
            foundAuthor = true;
        }
    }
    if (!foundAuthor) {
        cout << "Книг автора " << searchAuthor << " не найдено.\n";
    }

    // Фильтрация по издательству
    string searchPublisher;
    cout << "\nВведите издательство для поиска: ";
    getline(cin, searchPublisher);
    cout << "\nСписок книг заданного издательства:\n";
    bool foundPublisher = false;
    for (short i = 0; i < n; i++) {
        if (library[i].getPublisher() == searchPublisher) {
            library[i].print();
            foundPublisher = true;
        }
    }
    if (!foundPublisher) {
        cout << "Книг издательства " << searchPublisher << " не найдено.\n";
    }

    delete[] library;
    return 0;
}