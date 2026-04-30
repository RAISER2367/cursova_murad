#ifndef FRAMEMANAGER_H
#define FRAMEMANAGER_H

#include <vector>
#include <string>
#include "TitleFrame.h"
#include "FrameIterator.h"

// 5. Клас СПИСОК ВІКОН
class FrameManager {
private:
    std::vector<TitleFrame*> frames; // Масив об'єктів класу ВІКНО З ЗАГОЛОВКОМ

public:
    ~FrameManager();

    void openFrame(TitleFrame* frame); // Відкривання (додавання на нульову позицію)
    void closeFrame(size_t index);     // Закривання (видалення з масиву)
    void focusFrame(size_t index);     // Зміна фокусу (переміщення на нульову позицію)
    void demonstrateAddition(size_t id1, size_t id2); // Демонстрація оператора +

    void clearAll();
    void showAll();
    void massUpdateStyle(const std::string& newColor);

    // 7. Читання і запис у файл
    void exportData(const std::string& filename);
    void importData(const std::string& filename);

    FrameIterator begin();
    FrameIterator end();
};

#endif // FRAMEMANAGER_H