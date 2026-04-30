#ifndef BASEFRAME_H
#define BASEFRAME_H

#include <iostream>
#include <string>
#include <algorithm>

class BaseFrame {
protected:
    int startX, startY;
    int endX, endY;
    std::string bgColor;

public:
    // 1. Конструктор за замовчуванням та ініціалізації
    BaseFrame();
    BaseFrame(int x1, int y1, int x2, int y2, const std::string& bg);

    // 1. Конструктор копіювання
    BaseFrame(const BaseFrame& other);

    // 1. Конструктор переміщення
    BaseFrame(BaseFrame&& other) noexcept;

    // 1. Деструктор
    virtual ~BaseFrame() = default;

    // 1. Методи для зміни та читання значень (Гетери та Сетери)
    int getStartX() const;
    void setStartX(int x);
    std::string getBgColor() const;
    void setBgColor(const std::string& color);

    // 2. Перевантаження операції = (присвоєння та переміщення)
    BaseFrame& operator=(const BaseFrame& other);
    BaseFrame& operator=(BaseFrame&& other) noexcept;

    // 2. Перевантаження операції + (метод класу) - накладання двох вікон (спільна оболонка)
    BaseFrame operator+(const BaseFrame& other) const;

    // 2. Перевантаження операції += (друг класу) - зсув координат вікна
    friend BaseFrame& operator+=(BaseFrame& lhs, int offset);

    // 2. Перевантаження потокових операцій введення-виведення
    friend std::ostream& operator<<(std::ostream& os, const BaseFrame& obj);
    friend std::istream& operator>>(std::istream& is, BaseFrame& obj);

    virtual void displayInfo() const;
    virtual void updateStyle(const std::string& newColor);
};

#endif // BASEFRAME_H