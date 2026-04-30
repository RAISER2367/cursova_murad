#include "FrameIterator.h"

FrameIterator::FrameIterator(std::vector<TitleFrame*>::iterator start) : current(start) {}

TitleFrame* FrameIterator::operator*() {
    return *current;
}

FrameIterator& FrameIterator::operator++() {
    ++current;
    return *this;
}

bool FrameIterator::operator!=(const FrameIterator& other) const {
    return current != other.current;
}