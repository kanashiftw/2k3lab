#pragma once
#include "IExpression.h"
class IShuffle : public IExpression {
public:
    virtual void shuffleOperands() = 0;
    virtual void shuffleOperands(int i, int j) = 0;
};