#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Вычисление факториала
int factorial(int n)
{
    int result = 1;

    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

// Инициализация двумерного массива
void initializeArray(int** array)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(array + i) + j) = factorial(i + j);
        }
    }
}

// Вывод двумерного массива
void print2DArray(int** array)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setw(8) << *(*(array + i) + j);
        }

        cout << endl;
    }
}

// Преобразование 2D массива в 1D
// Четные строки не включаются
int* convertTo1D(int** array, int& size)
{
    // Нечетных строк: 3 (строки 0, 2, 4)
    size = 3 * COLS;

    int* result = new int[size];

    int index = 0;

    for (int i = 0; i < ROWS; i++)
    {
        // Строки с индексами 0, 2, 4 — нечетные по человеческой нумерации
        if (i % 2 == 0)
        {
            for (int j = 0; j < COLS; j++)
            {
                *(result + index) = *(*(array + i) + j);
                index++;
            }
        }
    }

    return result;
}

// Вывод одномерного массива
void print1DArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(8) << *(array + i);
    }

    cout << endl;
}

int main()
{
    // Выделяем память под двумерный массив
    int** array = new int* [ROWS];

    for (int i = 0; i < ROWS; i++)
    {
        *(array + i) = new int[COLS];
    }

    initializeArray(array);

    cout << "2D array:" << endl;
    print2DArray(array);

    int size = 0;

    int* result = convertTo1D(array, size);

    cout << "\n1D array:" << endl;
    print1DArray(result, size);

    // Освобождаем память 1D массива
    delete[] result;

    // Освобождаем память 2D массива
    for (int i = 0; i < ROWS; i++)
    {
        delete[] * (array + i);
    }

    delete[] array;

    return 0;
}
