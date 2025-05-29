#include <iostream>
#include <string>
using namespace std;
class Pet {
public:
    Pet(const string& name, const string& type, const string& character, const string& sound) : name_(name), type_(type), character_(character), sound_(sound) {}

    virtual ~Pet() = default;

    virtual void Sound() const = 0;
    virtual void Show() const = 0;
    virtual void Type() const = 0;

protected:
    string name_;
    string type_;
    string character_;
    string sound_;
};

// Собака
class Dog : public Pet {
public:
    Dog(const string& name, const string& character, const string& sound) : Pet(name, "Dog", character, sound) {}

    void Sound() const override {
        cout << name_ << " говорит: " << sound_ << endl;
    }

    void Show() const override {
        cout << "Имя собаки: " << name_ << ", характер: " << character_ << endl;
    }

    void Type() const override {
        cout << "Подвид: " << type_ << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const string& name, const string& character, const string& sound) : Pet(name, "Cat", character, sound) {}

    void Sound() const override {
        cout << name_ << " говорит: " << sound_ << endl;
    }

    void Show() const override {
        cout << "Имя кошки: " << name_ << ", характер: " << character_ << endl;
    }

    void Type() const override {
        cout << "Подвид: " << type_ << endl;
    }
};

class Parrot : public Pet {
public:
    Parrot(const string& name, const string& character, const string& sound) : Pet(name, "Parrot", character, sound) {}

    void Sound() const override {
        cout << name_ << " говорит: " << sound_ << endl;
    }

    void Show() const override {
        cout << "Имя попугая: " << name_ << ", характер: " << character_ << endl;
    }

    void Type() const override {
        cout << "Подвид: " << type_ << endl;
    }
};

class Hamster : public Pet {
public:
    Hamster(const string& name, const string& character, const string& sound) : Pet(name, "Hamster", character, sound) {}

    void Sound() const override {
        cout << name_ << " издает: " << sound_ << endl;
    }

    void Show() const override {
        cout << "Имя хомяка: " << name_ << ", характер: " << character_ << endl;
    }

    void Type() const override {
        cout << "Подвид: " << type_ << endl;
    }
};

int main() {
    Dog dog("Шарик", "игривый", "Гав-гав");
    Cat cat("Мурка", "ласковая", "Мяу");
    Parrot parrot("Кеша", "говорливый", "Привет!");
    Hamster hamster("Пушок", "робкий", "Пи-пи");

    cout << "Работаем с собакой" << endl;
    dog.Show();
    dog.Type();
    dog.Sound();
    cout << endl;

    cout << "Работаем с кошкой" << endl;
    cat.Show();
    cat.Type();
    cat.Sound();
    cout << endl;

    cout << "Работаем с попугаем" << endl;
    parrot.Show();
    parrot.Type();
    parrot.Sound();
    cout << endl;

    cout << "Работаем с хомяком" << endl;
    hamster.Show();
    hamster.Type();
    hamster.Sound();
    cout << endl;
    return 0;
}