#include "FrameManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

FrameManager::~FrameManager() {
    clearAll();
}

// Додавання нового елементу в масив на НУЛЬОВУ позицію (Пункт 5)
void FrameManager::openFrame(TitleFrame* frame) {
    frames.insert(frames.begin(), frame);
    std::cout << ">>> Вікно відкрито (додано на початок списку)!\n";
}

// Видалення елементу з масиву (Пункт 5)
void FrameManager::closeFrame(size_t index) {
    if (index < frames.size()) {
        delete frames[index];
        frames.erase(frames.begin() + index);
        std::cout << ">>> Вікно закрито (видалено)!\n";
    }
    else {
        std::cout << ">>> Помилка: Невірний індекс!\n";
    }
}

// Змінити фокус (розмістити на нульову позицію) (Пункт 5)
void FrameManager::focusFrame(size_t index) {
    if (index > 0 && index < frames.size()) {
        TitleFrame* target = frames[index];
        frames.erase(frames.begin() + index);
        frames.insert(frames.begin(), target);
        std::cout << ">>> Фокус змінено (вікно на передньому плані)!\n";
    }
    else if (index == 0) {
        std::cout << ">>> Вікно вже у фокусі!\n";
    }
    else {
        std::cout << ">>> Помилка: Невірний індекс!\n";
    }
}

void FrameManager::clearAll() {
    for (auto f : frames) delete f;
    frames.clear();
}

// Демонстрація перевантаження оператора + (накладання вікон)
void FrameManager::demonstrateAddition(size_t id1, size_t id2) {
    if (id1 < frames.size() && id2 < frames.size()) {
        // Використовуємо перевантажений оператор +
        BaseFrame combined = (*frames[id1]) + (*frames[id2]);
        std::cout << ">>> Результат об'єднання (спільна оболонка):\n";
        combined.displayInfo();
        std::cout << "\n";
    }
    else {
        std::cout << ">>> Помилка: Невірні індекси вікон!\n";
    }
}

void FrameManager::showAll() {
    if (frames.empty()) {
        std::cout << ">>> Список вікон порожній.\n";
        return;
    }
    int i = 0;
    // Використання ітератора (Пункт 6)
    for (auto it = begin(); it != end(); ++it) {
        std::cout << "ID[" << i++ << "] -> ";
        (*it)->displayInfo();
        std::cout << "\n";
    }
}

void FrameManager::massUpdateStyle(const std::string& newColor) {
    for (auto it = begin(); it != end(); ++it) {
        // Демонстрація поліморфізму (Пункт 4)
        (*it)->updateStyle(newColor);
    }
    std::cout << ">>> Масове оновлення стилю (поліморфізм) завершено!\n";
}

void FrameManager::exportData(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (auto f : frames) {
            outFile << *f << "\n"; // Використовуємо перевантажений оператор <<
        }
        outFile.close();
        std::cout << ">>> Дані збережено у файл!\n";
    }
}


void FrameManager::importData(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << ">>> Файл не знайдено, починаємо з порожнього списку.\n";
        return;
    }

    clearAll();
    std::string line;
    std::vector<TitleFrame*> tempFrames;

    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        TitleFrame* tf = new TitleFrame();
        ss >> *tf; // Використовуємо перевантажений оператор >>
        tempFrames.push_back(tf);
    }
    inFile.close();

    // Записуємо у зворотному порядку, оскільки openFrame додає на початок (індекс 0)
    for (auto it = tempFrames.rbegin(); it != tempFrames.rend(); ++it) {
        openFrame(*it);
    }
    std::cout << ">>> Дані успішно завантажено!\n";
}

FrameIterator FrameManager::begin() { return FrameIterator(frames.begin()); }
FrameIterator FrameManager::end() { return FrameIterator(frames.end()); }