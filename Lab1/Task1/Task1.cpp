#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdio>

const int N = 18;

double processArray(double input[], double output[])
{
    // Заполняем массив случайными числами от -20.0 до 70.0
    for (int i = 0; i < N; i++)
    {
        input[i] = -20.0 + (rand() / (double)RAND_MAX) * 90.0;
    }

    // Ищем максимальное по модулю значение
    double maxAbs = fabs(input[0]);
    int maxIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (fabs(input[i]) > maxAbs)
        {
            maxAbs = fabs(input[i]);
            maxIndex = i;
        }
    }

    // Нормализуем входной массив
    for (int i = 0; i < N; i++)
    {
        input[i] /= maxAbs;
    }

    // Формируем выходной массив
    double x;

    printf("Enter X: ");
    scanf_s("%lf", &x);

    for (int i = 0; i < N; i++)
    {
        if (i <= maxIndex)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = x;
        }
    }

    return maxAbs;
}

int main()
{
    srand((unsigned)time(nullptr));

    double input[N] = {};
    double output[N] = {};

    double maxValue = processArray(input, output);

    printf("\nMax absolute value = %.6f\n", maxValue);

    printf("Normalized array:\n");

    for (int i = 0; i < N; i++)
    {
        printf("%.6f ", input[i]);
    }

    printf("\n\nResulting array:\n");

    for (int i = 0; i < N; i++)
    {
        printf("%.6f ", output[i]);
    }

    printf("\n");

    return 0;
}