#pragma once
#include <vector>
#include "ILoggable.h"
#include "IShuffle.h"
#include "ISetOperands.h"
using namespace std;

class Expression : public ILoggable, public IShuffle, public ISetOperands
{
public:
    char c[100];
    vector<double> v;
    Expression();
    Expression(int n);
    Expression(string some_text);
    ~Expression();
    virtual void setOperand(double value, size_t pos)override;
    virtual void shuffleOperands() override;
    virtual void shufflebetween2(int i, int j) override;
    virtual void setOperands(double* new_operands, size_t size)override;
    virtual void calculate() override;
    virtual void logcout(string text) override;
    virtual void logtofile(string text, string filename) override;
};