#ifndef FRAMEITERATOR_H
#define FRAMEITERATOR_H

#include <vector>
#include "TitleFrame.h"

// 6. Клас-ітератор
class FrameIterator {
private:
    std::vector<TitleFrame*>::iterator current;
public:
    FrameIterator(std::vector<TitleFrame*>::iterator start);

    TitleFrame* operator*();
    FrameIterator& operator++();
    bool operator!=(const FrameIterator& other) const;
};

#endif // FRAMEITERATOR_H