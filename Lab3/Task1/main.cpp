#include <iostream>
#include <iomanip>

#include "Summator.h"
#include "Divisor.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    ExpressionEvaluator* expressions[3];

    // 1. Summator — 7 операндов
    Summator* summator = new Summator(7);

    double sumOperands[] =
    {
        5, 12.5, 9, -1.5, -9.5, 0, 11
    };

    summator->setOperands(sumOperands, 7);

    expressions[0] = summator;


    // 2. Divisor — 4 операнда
    Divisor* divisor = new Divisor(4);

    divisor->setOperand(0, 100);
    divisor->setOperand(1, -4);
    divisor->setOperand(2, 2.5);
    divisor->setOperand(3, -4);

    expressions[1] = divisor;


    // 3. CustomExpressionEvaluator — 5 операндов
    CustomExpressionEvaluator* custom =
        new CustomExpressionEvaluator(5);

    double customOperands[] =
    {
        5, 4, -2, 9, 3
    };

    custom->setOperands(customOperands, 5);

    expressions[2] = custom;


    // Демонстрация полиморфизма
    cout << "INITIAL EXPRESSIONS\n\n";

    for (int i = 0; i < 3; ++i)
    {
        expressions[i]->logToScreen();
        expressions[i]->logToFile("expressions.log");
    }


    // Проверка IShuffle через RTTI
    cout << "\nSHUFFLING\n\n";

    for (int i = 0; i < 3; ++i)
    {
        IShuffle* shuffleInterface =
            dynamic_cast<IShuffle*>(expressions[i]);

        if (shuffleInterface != nullptr)
        {
            cout << "Expression [" << i + 1
                << "] supports IShuffle.\n";

            shuffleInterface->shuffle();

            expressions[i]->logToScreen();
        }
        else
        {
            cout << "Expression [" << i + 1
                << "] does not support IShuffle.\n";
        }

        cout << '\n';
    }


    // Демонстрация shuffle(i, j)
    cout << "SHUFFLE(0, 1) FOR CUSTOM EXPRESSION\n";

    custom->shuffle(0, 1);

    custom->logToScreen();


    // Освобождение памяти
    delete expressions[0];
    delete expressions[1];
    delete expressions[2];

    return 0;
}