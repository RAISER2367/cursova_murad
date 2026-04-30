#include <iostream>
#include <string>
#include <windows.h>
#include "FrameManager.h"
#include "TitleFrame.h"

using namespace std;

void showMenu() {
    cout << "\n=========================================\n";
    cout << "       СИСТЕМА УПРАВЛІННЯ ФРЕЙМАМИ       \n";
    cout << "=========================================\n";
    cout << "1. Відкрити нове вікно\n";
    cout << "2. Вивести список вікон\n";
    cout << "3. Змінити фокус вікна\n";
    cout << "4. Закрити вікно\n";
    cout << "5. Оновити стиль\n";
    cout << "6. Зсув вікна\n";
    cout << "7. Зберегти дані у файл\n";
    cout << "8. Завантажити дані з файлу\n";
    cout << "9. Накладання вікон\n";
    cout << "0. Вихід\n";
    cout << "Оберіть дію: ";
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    FrameManager manager;
    int choice;

    // Автоматичне завантаження на старті (Пункт 7 - 10)
    manager.importData("frames_data.txt");

    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << ">>> Помилка вводу! Введіть число.\n";
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            int x1, y1, x2, y2;
            string bg, txt, txtClr;
            cout << "Введіть лівий верхній кут (X Y): ";
            cin >> x1 >> y1;
            cout << "Введіть правий нижній кут (X Y): ";
            cin >> x2 >> y2;
            cout << "Введіть колір фону (без пробілів): ";
            cin >> bg;
            cout << "Введіть текст шапки (без пробілів): ";
            cin >> txt;
            cout << "Введіть колір тексту (без пробілів): ";
            cin >> txtClr;

            manager.openFrame(new TitleFrame(x1, y1, x2, y2, bg, txt, txtClr));
            break;
        }
        case 2:
            manager.showAll();
            break;
        case 3: {
            size_t id;
            cout << "Введіть ID вікна для фокусування: ";
            cin >> id;
            manager.focusFrame(id);
            break;
        }
        case 4: {
            size_t id;
            cout << "Введіть ID вікна для закриття: ";
            cin >> id;
            manager.closeFrame(id);
            break;
        }
        case 5: {
            string newClr;
            cout << "Введіть новий колір: ";
            cin >> newClr;
            manager.massUpdateStyle(newClr);
            break;
        }
        case 6: {
            // Демонстрація оператора +=
            cout << "Зсув координат:\n";
            BaseFrame tempFrame(10, 10, 50, 50, "Blue");
            cout << "До:  " << tempFrame << "\n";
            tempFrame += 20; // Зсув на 20
            cout << "Після зсуву (+20): " << tempFrame << "\n";
            break;
        }
        case 7:
            manager.exportData("frames_data.txt");
            break;
        case 8:
            manager.importData("frames_data.txt"); 
            break;

        case 9: {
            size_t id1, id2;
            cout << "Введіть ID першого вікна: ";
            cin >> id1;
            cout << "Введіть ID другого вікна: ";
            cin >> id2;
            manager.demonstrateAddition(id1, id2);
            break;
        }

        default:
            cout << ">>> Невідома команда.\n";
        }
    }

    return 0;
}