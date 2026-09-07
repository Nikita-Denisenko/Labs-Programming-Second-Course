#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator()
    : ExpressionEvaluator()
{
}

CustomExpressionEvaluator::CustomExpressionEvaluator(int N)
    : ExpressionEvaluator(N)
{
}

double CustomExpressionEvaluator::calculate()
{
    if (operandCount == 0)
        return 0;

    double result = operands[0];

    for (int i = 1; i < operandCount; ++i)
    {
        if (i % 2 == 1)
            result -= operands[i];
        else
            result += operands[i];
    }

    return result;
}

void CustomExpressionEvaluator::logToScreen()
{
    cout << "Expression [" << operandCount << "] : ";

    for (int i = 0; i < operandCount; ++i)
    {
        if (i == 0)
        {
            cout << operands[i];
        }
        else if (i % 2 == 1)
        {
            cout << " - " << operands[i];
        }
        else
        {
            cout << " + " << operands[i];
        }
    }

    cout << " = " << calculate() << '\n';
}

void CustomExpressionEvaluator::logToFile(string filename)
{
    ofstream file(filename, ios::app);

    if (!file)
        return;

    file << "Expression [" << operandCount << "] : ";

    for (int i = 0; i < operandCount; ++i)
    {
        if (i == 0)
        {
            file << operands[i];
        }
        else if (i % 2 == 1)
        {
            file << " - " << operands[i];
        }
        else
        {
            file << " + " << operands[i];
        }
    }

    file << " = " << calculate() << '\n';
}

void CustomExpressionEvaluator::shuffle()
{
    int position = 0;

    // Сначала отрицательные
    for (int i = 0; i < operandCount; ++i)
    {
        if (operands[i] < 0)
        {
            swap(operands[position], operands[i]);
            ++position;
        }
    }
}

void CustomExpressionEvaluator::shuffle(int i, int j)
{
    if (i >= 0 && i < operandCount &&
        j >= 0 && j < operandCount)
    {
        if (operands[i] < 0 && operands[j] >= 0)
            swap(operands[i], operands[j]);
    }
}
