#include "Divisor.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

Divisor::Divisor()
    : ExpressionEvaluator()
{
}

Divisor::Divisor(int N)
    : ExpressionEvaluator(N)
{
}

double Divisor::calculate()
{
    for (int i = 0; i < operandCount; ++i)
    {
        if (operands[i] == 0)
            return 0;
    }

    double result = operands[0];

    for (int i = 1; i < operandCount; ++i)
        result /= operands[i];

    return result;
}

void Divisor::logToScreen()
{
    cout << "Expression [" << operandCount << "] : ";

    for (int i = 0; i < operandCount; ++i)
    {
        if (i > 0)
            cout << " / ";

        cout << operands[i];
    }

    cout << " = " << calculate() << '\n';
}

void Divisor::logToFile(string filename)
{
    ofstream file(filename, ios::app);

    if (!file)
        return;

    file << "Expression [" << operandCount << "] : ";

    for (int i = 0; i < operandCount; ++i)
    {
        if (i > 0)
            file << " / ";

        file << operands[i];
    }

    file << " = " << calculate() << '\n';
}

void Divisor::shuffle()
{
    random_device rd;
    mt19937 generator(rd());

    std::shuffle(
        operands,
        operands + operandCount,
        generator
    );
}

void Divisor::shuffle(int i, int j)
{
    if (i >= 0 && i < operandCount &&
        j >= 0 && j < operandCount)
    {
        swap(operands[i], operands[j]);
    }
}
