#pragma once
#include <vector>
#include "ILoggable.h"
#include "IShuffle.h"
#include "ISetOperands.h"
#include "IExpression.h"
using namespace std;

class Substructor : public ILoggable, public IShuffle, public ISetOperands, public IExpression
{
public:
    int n;
    vector<double> v;
    Substructor();
    Substructor(int n);
    ~Substructor();
    virtual void shuffleOperands() override;
    virtual void shuffleOperands(int i, int j) override;
    virtual void setOperand(double value, size_t pos)override;
    virtual void setOperands(double* new_operands, size_t size)override;
    virtual void displayOperation()override;
    virtual void calculate()override;
    virtual void logcout(string text) override;
    virtual void logtofile(string text, string filename) override;
};