#include "TitleFrame.h"

TitleFrame::TitleFrame() : BaseFrame(), labelText("Untitled"), labelColor("Black") {}

TitleFrame::TitleFrame(int x1, int y1, int x2, int y2, const std::string& bg,
    const std::string& text, const std::string& textColor)
    : BaseFrame(x1, y1, x2, y2, bg), labelText(text), labelColor(textColor) {
}

TitleFrame::TitleFrame(const TitleFrame& other)
    : BaseFrame(other), labelText(other.labelText), labelColor(other.labelColor) {
}

TitleFrame::TitleFrame(TitleFrame&& other) noexcept
    : BaseFrame(std::move(other)), labelText(std::move(other.labelText)), labelColor(std::move(other.labelColor)) {
}

TitleFrame& TitleFrame::operator=(const TitleFrame& other) {
    if (this != &other) {
        BaseFrame::operator=(other);
        labelText = other.labelText;
        labelColor = other.labelColor;
    }
    return *this;
}

TitleFrame& TitleFrame::operator=(TitleFrame&& other) noexcept {
    if (this != &other) {
        BaseFrame::operator=(std::move(other));
        labelText = std::move(other.labelText);
        labelColor = std::move(other.labelColor);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const TitleFrame& obj) {
    os << static_cast<const BaseFrame&>(obj) << " " << obj.labelText << " " << obj.labelColor;
    return os;
}

std::istream& operator>>(std::istream& is, TitleFrame& obj) {
    is >> static_cast<BaseFrame&>(obj) >> obj.labelText >> obj.labelColor;
    return is;
}

void TitleFrame::displayInfo() const {
    BaseFrame::displayInfo();
    std::cout << " | Шапка: <" << labelText << ">, Колір шрифту: " << labelColor;
}

void TitleFrame::updateStyle(const std::string& newColor) {
    labelColor = newColor;
}