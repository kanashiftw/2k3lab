#pragma once
class IShuffle {
public:
    virtual void shuffleOperands() = 0;
    virtual void shufflebetween2(int i, int j) = 0;
};