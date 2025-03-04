#include <iostream>
#include <string>
using namespace std;

class WallpaperRoll {
public:
    string name;
    float rollLength;
    float rollWidth;
    float price;

    WallpaperRoll() {
        name = "";
        rollLength = 0.0f;
        rollWidth = 0.0f;
        price = 0.0f;
    }
    WallpaperRoll(string n, float rl, float rw, float p) {
        name = n;
        rollLength = rl;
        rollWidth = rw;
        price = p;
    }

    float area() {
        return rollLength * rollWidth;
    }
};

class Room {
public:
    string name;
    float length;
    float width;
    float height;
    bool wallpaperCeiling;
    short wallpaperTypeIndex;

    Room() {
        name = "";
        length = 0.0f;
        width = 0.0f;
        height = 0.0f;
        wallpaperCeiling = false;
        wallpaperTypeIndex = 0;
    }
    Room(string n, float l, float w, float h, bool wc, short typeIndex) {
        name = n;
        length = l;
        width = w;
        height = h;
        wallpaperCeiling = wc;
        wallpaperTypeIndex = typeIndex;
    }

    float wallArea() {
        return 2 * (length + width) * height;
    }
    float ceilingArea() {
        return length * width;
    }
    float totalArea() {
        if (wallpaperCeiling) {
            return wallArea() + ceilingArea();
        }
        return wallArea();
    }
};

class Apartment {
public:
    Room* rooms;
    short roomCount;

    Apartment() {
        rooms = nullptr;
        roomCount = 0;
    }
};

int main() {
    short numWallpaperTypes;
    cout << "Введите количество типов обоев: ";
    cin >> numWallpaperTypes;

    WallpaperRoll* wallpaperTypes = new WallpaperRoll[numWallpaperTypes];

    for (short i = 0; i < numWallpaperTypes; i++) {
        cout << "\nВведите параметры для типа обоев " << (i + 1) << ":\n";
        string name;
        cout << "Название: ";
        cin >> name;
        float rollLength, rollWidth, price;
        cout << "Длина рулона (м): ";
        cin >> rollLength;
        cout << "Ширина рулона (м): ";
        cin >> rollWidth;
        cout << "Цена за рулон: ";
        cin >> price;

        wallpaperTypes[i] = WallpaperRoll(name, rollLength, rollWidth, price);
    }

    short numRooms;
    cout << "\nВведите количество комнат в квартире: ";
    cin >> numRooms;

    Apartment apartment;
    apartment.roomCount = numRooms;
    apartment.rooms = new Room[numRooms];

    for (short i = 0; i < numRooms; i++) {
        cout << "\nВведите данные для комнаты " << (i + 1) << ":\n";
        string roomName;
        cout << "Название комнаты: ";
        cin >> roomName;
        float length, width, height;
        cout << "Длина комнаты (м): ";
        cin >> length;
        cout << "Ширина комнаты (м): ";
        cin >> width;
        cout << "Высота комнаты (м): ";
        cin >> height;
        short ceilingChoice;
        cout << "Клеить потолок? (1 - да, 0 - нет): ";
        cin >> ceilingChoice;
        bool wallpaperCeiling = (ceilingChoice == 1);
        short typeIndex;
        cout << "Номер типа обоев для этой комнаты (от 1 до " << numWallpaperTypes << "): ";
        cin >> typeIndex;
        typeIndex -= 1;

        apartment.rooms[i] = Room(roomName, length, width, height, wallpaperCeiling, typeIndex);
    }

    float* totalAreaForType = new float[numWallpaperTypes];
    for (short i = 0; i < numWallpaperTypes; i++) {
        totalAreaForType[i] = 0.0f;
    }

    for (short i = 0; i < numRooms; i++) {
        short type = apartment.rooms[i].wallpaperTypeIndex;
        if (type >= 0 && type < numWallpaperTypes) {
            totalAreaForType[type] += apartment.rooms[i].totalArea();
        }
    }

    float totalCost = 0.0f;
    cout << "\nНеобходимое количество рулонов и стоимость для каждого типа обоев:\n";
    for (short i = 0; i < numWallpaperTypes; i++) {
        float rollArea = wallpaperTypes[i].area();
        short rollsNeeded = totalAreaForType[i] / rollArea;
        if (totalAreaForType[i] > rollsNeeded * rollArea) {
            rollsNeeded++;
        }
        float cost = rollsNeeded * wallpaperTypes[i].price;
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