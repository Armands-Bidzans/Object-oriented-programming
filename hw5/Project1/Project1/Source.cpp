#include <iostream>
#include <string>
using namespace std;

class WallpaperRoll {
public:
    string name;
    double rollLength;
    double rollWidth;
    double price;

    WallpaperRoll() {
        name = "";
        rollLength = 0;
        rollWidth = 0;
        price = 0;
    }
    WallpaperRoll(string n, double rl, double rw, double p) {
        name = n;
        rollLength = rl;
        rollWidth = rw;
        price = p;
    }

    double area() {
        return rollLength * rollWidth;
    }
};

class Room {
public:
    string name;
    double length;
    double width;
    double height;
    bool wallpaperCeiling;
    int wallpaperTypeIndex;

    Room() {
        name = "";
        length = 0;
        width = 0;
        height = 0;
        wallpaperCeiling = false;
        wallpaperTypeIndex = 0;
    }
    Room(string n, double l, double w, double h, bool wc, int typeIndex) {
        name = n;
        length = l;
        width = w;
        height = h;
        wallpaperCeiling = wc;
        wallpaperTypeIndex = typeIndex;
    }

    double wallArea() {
        return 2 * (length + width) * height;
    }
    double ceilingArea() {
        return length * width;
    }
    double totalArea() {
        if (wallpaperCeiling) {
            return wallArea() + ceilingArea();
        }
        return wallArea();
    }
};

class Apartment {
public:
    Room* rooms;
    int roomCount;

    Apartment() {
        rooms = 0;
        roomCount = 0;
    }
};

int main() {
    int numWallpaperTypes;
    cout << "Введите количество типов обоев: ";
    cin >> numWallpaperTypes;

    WallpaperRoll* wallpaperTypes = new WallpaperRoll[numWallpaperTypes];

    for (int i = 0; i < numWallpaperTypes; i++) {
        cout << "\nВведите параметры для типа обоев " << (i + 1) << ":\n";
        string name;
        cout << "Название: ";
        cin >> name;
        double rollLength, rollWidth, price;
        cout << "Длина рулона (м): ";
        cin >> rollLength;
        cout << "Ширина рулона (м): ";
        cin >> rollWidth;
        cout << "Цена за рулон: ";
        cin >> price;

        wallpaperTypes[i] = WallpaperRoll(name, rollLength, rollWidth, price);
    }

    int numRooms;
    cout << "\nВведите количество комнат в квартире: ";
    cin >> numRooms;

    Apartment apartment;
    apartment.roomCount = numRooms;
    apartment.rooms = new Room[numRooms];

    for (int i = 0; i < numRooms; i++) {
        cout << "\nВведите данные для комнаты " << (i + 1) << ":\n";
        string roomName;
        cout << "Название комнаты: ";
        cin >> roomName;
        double length, width, height;
        cout << "Длина комнаты (м): ";
        cin >> length;
        cout << "Ширина комнаты (м): ";
        cin >> width;
        cout << "Высота комнаты (м): ";
        cin >> height;
        int ceilingChoice;
        cout << "Клеить потолок? (1 - да, 0 - нет): ";
        cin >> ceilingChoice;
        bool wallpaperCeiling = (ceilingChoice == 1);
        int typeIndex;
        cout << "Номер типа обоев для этой комнаты (от 1 до " << numWallpaperTypes << "): ";
        cin >> typeIndex;
        typeIndex -= 1;

        apartment.rooms[i] = Room(roomName, length, width, height, wallpaperCeiling, typeIndex);
    }

    double* totalAreaForType = new double[numWallpaperTypes];
    for (int i = 0; i < numWallpaperTypes; i++) {
        totalAreaForType[i] = 0.0;
    }

    for (int i = 0; i < numRooms; i++) {
        int type = apartment.rooms[i].wallpaperTypeIndex;
        if (type >= 0 && type < numWallpaperTypes) {
            totalAreaForType[type] += apartment.rooms[i].totalArea();
        }
    }

    double totalCost = 0.0;
    cout << "\nНеобходимое количество рулонов и стоимость для каждого типа обоев:\n";
    for (int i = 0; i < numWallpaperTypes; i++) {
        double rollArea = wallpaperTypes[i].area();
        int rollsNeeded = totalAreaForType[i] / rollArea;
        if (totalAreaForType[i] > rollsNeeded * rollArea) {
            rollsNeeded++;
        }
        double cost = rollsNeeded * wallpaperTypes[i].price;
        cout << "Тип обоев \"" << wallpaperTypes[i].name << "\": "
            << rollsNeeded << " рулонов, стоимость = " << cost << "\n";
        totalCost += cost;
    }
    cout << "\nОбщая стоимость: " << totalCost << "\n";

    delete[] wallpaperTypes;
    delete[] apartment.rooms;
    delete[] totalAreaForType;

    return 0;
}