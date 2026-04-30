#ifndef TITLEFRAME_H
#define TITLEFRAME_H

#include "BaseFrame.h"

// 3. Створити похідний клас
class TitleFrame : public BaseFrame {
private:
    std::string labelText;
    std::string labelColor;

public:
    TitleFrame();
    TitleFrame(int x1, int y1, int x2, int y2, const std::string& bg,
        const std::string& text, const std::string& textColor);

    TitleFrame(const TitleFrame& other);
    TitleFrame(TitleFrame&& other) noexcept;
    TitleFrame& operator=(const TitleFrame& other);
    TitleFrame& operator=(TitleFrame&& other) noexcept;

    // Перевантаження введення-виведення для похідного класу
    friend std::ostream& operator<<(std::ostream& os, const TitleFrame& obj);
    friend std::istream& operator>>(std::istream& is, TitleFrame& obj);

    void displayInfo() const override;

    // 4. Поліморфічний метод
    void updateStyle(const std::string& newColor) override;
};

#endif // TITLEFRAME_H