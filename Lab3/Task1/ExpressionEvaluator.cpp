#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator()
{
    operandCount = 20;
    operands = new double[operandCount];

    for (int i = 0; i < operandCount; ++i)
        operands[i] = 0;
}

ExpressionEvaluator::ExpressionEvaluator(int N)
{
    operandCount = N;
    operands = new double[operandCount];

    for (int i = 0; i < operandCount; ++i)
        operands[i] = 0;
}

ExpressionEvaluator::~ExpressionEvaluator()
{
    delete[] operands;
}

void ExpressionEvaluator::setOperand(int pos, double value)
{
    if (pos >= 0 && pos < operandCount)
        operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], int N)
{
    int count = N;

    if (count > operandCount)
        count = operandCount;

    for (int i = 0; i < count; ++i)
        operands[i] = ops[i];
}