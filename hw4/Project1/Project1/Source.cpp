#include <iostream>
using namespace std;

class Elevator {
public:
    bool turnOnOff;
    bool workDontwork;
    short minFloor;         // изменено int → short
    short maxFloor;         // изменено int → short
    short currentFloor;     // изменено int → short
    short destinationFloor; // изменено int → short

    Elevator(short minF, short maxF) { // изменено параметры int → short
        turnOnOff = false;
        workDontwork = false;
        minFloor = minF;
        maxFloor = maxF;
        currentFloor = minF;
        destinationFloor = minF;
    }

    void power(bool isOn) {
        turnOnOff = isOn;
    }

    void work(bool isWorking) {
        if (turnOnOff) {
            workDontwork = isWorking;
        }
    }

    void callElevator(short floor) { // изменено параметр int → short
        if (workDontwork && floor >= minFloor && floor <= maxFloor) {
            destinationFloor = floor;
            currentFloor = destinationFloor;
        }
    }

    short getCurrentFloor() {    // изменено int → short
        return currentFloor;
    }

    short getDestinationFloor() { // изменено int → short
        return destinationFloor;
    }
};

void printStatus(Elevator& lift) {
    cout << "\nСостояние лифта:" << endl;
    cout << "Лифт ";
    if (lift.turnOnOff) {
        cout << "включен" << endl;
    }
    else {
        cout << "выключен" << endl;
    }
    if (lift.turnOnOff) {
        cout << "Лифт ";
        if (lift.workDontwork) {
            cout << "работает" << endl;
        }
        else {
            cout << "не работает" << endl;
        }
    }
    cout << "Текущий этаж: " << lift.getCurrentFloor() << endl;
    cout << "Целевой этаж: " << lift.getDestinationFloor() << endl;
}

int main() {
    Elevator lift(1, 9);
    char choice;
    bool exitProgram = false;

    while (!exitProgram) {
        printStatus(lift);

        if (!lift.turnOnOff) {
            cout << "\nДоступные действия:" << endl;
            cout << "1. Включить лифт" << endl;
            cout << "2. Выход" << endl;
            cout << "Ваш выбор: ";
            cin >> choice;
            if (choice == '1') {
                lift.power(true);
                lift.work(true);
                cout << "Лифт включён и готов к работе." << endl;
            }
            else if (choice == '2') {
                exitProgram = true;
            }
            else {
                cout << "Неверный ввод." << endl;
                return 1;
            }
        }
        else {
            cout << "\nДоступные действия:" << endl;
            cout << "1. Выключить лифт" << endl;
            cout << "2. Вызвать лифт на нужный этаж" << endl;
            cout << "3. Выход" << endl;
            cout << "Ваш выбор: ";
            cin >> choice;
            if (choice == '1') {
                lift.power(false);
                lift.work(false);
                cout << "Лифт выключён." << endl;
            }
            else if (choice == '2') {
                short target; // изменено int → short
                cout << "Введите номер этажа, куда хотите поехать: ";
                cin >> target;
                if (target >= lift.minFloor && target <= lift.maxFloor) {
                    cout << "Вы едете на этаж " << target << "." << endl;
                    lift.callElevator(target);
                    cout << "Лифт прибыл на этаж " << lift.getCurrentFloor() << "." << endl;
                }
                else {
                    cout << "Неверный ввод. Этаж должен быть от " << lift.minFloor << " до " << lift.maxFloor << "." << endl;
                    return 1;
                }
            }
            else if (choice == '3') {
                exitProgram = true;
            }
            else {
                cout << "Неверный ввод." << endl;
                return 1;
            }
        }
    }

    cout << "\nПрограмма завершена." << endl;
    return 0;
}
