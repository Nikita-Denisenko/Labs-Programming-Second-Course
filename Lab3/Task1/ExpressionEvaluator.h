#pragma once

#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable
{
protected:
    int operandCount;
    double* operands;

public:
    ExpressionEvaluator();
    ExpressionEvaluator(int N);
    virtual ~ExpressionEvaluator();

    void setOperand(int pos, double value);
    void setOperands(double ops[], int N);

    virtual double calculate() = 0;
};
