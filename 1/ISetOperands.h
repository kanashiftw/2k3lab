#pragma once
class ISetOperands {
public:
    virtual void setOperand(double value, size_t pos) = 0;
    virtual void setOperands(double* array, size_t size) = 0;
};