#include "Summator.h"
#include <iostream>
#include <fstream>

using namespace std;

Summator::Summator()
    : ExpressionEvaluator()
{
}

Summator::Summator(int N)
    : ExpressionEvaluator(N)
{
}

double Summator::calculate()
{
    double result = 0;

    for (int i = 0; i < operandCount; ++i)
        result += operands[i];

    return result;
}

void Summator::logToScreen()
{
    cout << "Expression [" << operandCount << "] : ";

    for (int i = 0; i < operandCount; ++i)
    {
        if (i > 0)
            cout << " + ";

        cout << operands[i];
    }

    cout << " = " << calculate() << '\n';
}

void Summator::logToFile(string filename)
{
    ofstream file(filename, ios::app);

    if (!file)
        return;

    file << "Expression [" << operandCount << "] : ";

    for (int i = 0; i < operandCount; ++i)
    {
        if (i > 0)
            file << " + ";

        file << operands[i];
    }

    file << " = " << calculate() << '\n';
}
