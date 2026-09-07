#pragma once

#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator
{
public:
    Summator();
    Summator(int N);

    double calculate() override;

    void logToScreen() override;
    void logToFile(std::string filename) override;
};
