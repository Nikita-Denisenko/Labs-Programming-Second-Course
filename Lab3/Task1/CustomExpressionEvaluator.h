#pragma once

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator
    : public ExpressionEvaluator,
    public IShuffle
{
public:
    CustomExpressionEvaluator();
    CustomExpressionEvaluator(int N);

    double calculate() override;

    void logToScreen() override;
    void logToFile(std::string filename) override;

    void shuffle() override;
    void shuffle(int i, int j) override;
};
