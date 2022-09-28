#pragma once
using namespace std;

class IExpression
{
public:
    virtual void calculate() = 0;
    virtual void displayOperation() = 0;
};