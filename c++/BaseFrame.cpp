#include "BaseFrame.h"

BaseFrame::BaseFrame() : startX(0), startY(0), endX(0), endY(0), bgColor("None") {}

BaseFrame::BaseFrame(int x1, int y1, int x2, int y2, const std::string& bg)
    : startX(x1), startY(y1), endX(x2), endY(y2), bgColor(bg) {
}

BaseFrame::BaseFrame(const BaseFrame& other)
    : startX(other.startX), startY(other.startY), endX(other.endX), endY(other.endY), bgColor(other.bgColor) {
}

BaseFrame::BaseFrame(BaseFrame&& other) noexcept
    : startX(other.startX), startY(other.startY), endX(other.endX), endY(other.endY), bgColor(std::move(other.bgColor)) {
    other.startX = other.startY = other.endX = other.endY = 0;
}

int BaseFrame::getStartX() const { return startX; }
void BaseFrame::setStartX(int x) { startX = x; }
std::string BaseFrame::getBgColor() const { return bgColor; }
void BaseFrame::setBgColor(const std::string& color) { bgColor = color; }

BaseFrame& BaseFrame::operator=(const BaseFrame& other) {
    if (this != &other) {
        startX = other.startX; startY = other.startY;
        endX = other.endX; endY = other.endY;
        bgColor = other.bgColor;
    }
    return *this;
}

BaseFrame& BaseFrame::operator=(BaseFrame&& other) noexcept {
    if (this != &other) {
        startX = other.startX; startY = other.startY;
        endX = other.endX; endY = other.endY;
        bgColor = std::move(other.bgColor);
        other.startX = other.startY = other.endX = other.endY = 0;
    }
    return *this;
}

BaseFrame BaseFrame::operator+(const BaseFrame& other) const {
    // Накладання: створюємо вікно, яке охоплює обидва
    return BaseFrame(
        std::min(startX, other.startX), std::min(startY, other.startY),
        std::max(endX, other.endX), std::max(endY, other.endY),
        bgColor
    );
}

BaseFrame& operator+=(BaseFrame& lhs, int offset) {
    lhs.startX += offset; lhs.startY += offset;
    lhs.endX += offset; lhs.endY += offset;
    return lhs;
}

std::ostream& operator<<(std::ostream& os, const BaseFrame& obj) {
    os << obj.startX << " " << obj.startY << " " << obj.endX << " " << obj.endY << " " << obj.bgColor;
    return os;
}

std::istream& operator>>(std::istream& is, BaseFrame& obj) {
    is >> obj.startX >> obj.startY >> obj.endX >> obj.endY >> obj.bgColor;
    return is;
}

void BaseFrame::displayInfo() const {
    std::cout << "Фрейм [" << startX << ":" << startY << " -> "
        << endX << ":" << endY << "], Заливка: " << bgColor;
}

void BaseFrame::updateStyle(const std::string& newColor) {
    bgColor = newColor;
}