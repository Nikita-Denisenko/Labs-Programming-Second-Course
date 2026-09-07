#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Vector
{
private:
    int size;
    T* data;

public:
    Vector(int size) : size(size)
    {
        data = new T[size];
    }

    // Глубокое копирование
    Vector(const Vector& other) : size(other.size)
    {
        data = new T[size];

        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    ~Vector()
    {
        delete[] data;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    // Префиксный ++
    Vector& operator++()
    {
        for (int i = 0; i < size; ++i)
            ++data[i];

        return *this;
    }

    // Постфиксный ++
    Vector operator++(int)
    {
        Vector temp(*this);

        for (int i = 0; i < size; ++i)
            ++data[i];

        return temp;
    }

    // Префиксный --
    Vector& operator--()
    {
        for (int i = 0; i < size; ++i)
            --data[i];

        return *this;
    }

    // Постфиксный --
    Vector operator--(int)
    {
        Vector temp(*this);

        for (int i = 0; i < size; ++i)
            --data[i];

        return temp;
    }

    int getSize() const
    {
        return size;
    }
};


template <typename T>
class Matrix
{
private:
    int rows;
    int cols;
    T** data;

public:
    Matrix(int rows, int cols)
        : rows(rows), cols(cols)
    {
        data = new T * [rows];

        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    // Глубокое копирование
    Matrix(const Matrix& other)
        : rows(other.rows), cols(other.cols)
    {
        data = new T * [rows];

        for (int i = 0; i < rows; ++i)
        {
            data[i] = new T[cols];

            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];

        delete[] data;
    }

    T at(int i, int j) const
    {
        return data[i][j];
    }

    void setAt(int i, int j, T val)
    {
        data[i][j] = val;
    }

    // Префиксный ++
    Matrix& operator++()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                ++data[i][j];
        }

        return *this;
    }

    // Постфиксный ++
    Matrix operator++(int)
    {
        Matrix temp(*this);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                ++data[i][j];
        }

        return temp;
    }

    // Префиксный --
    Matrix& operator--()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                --data[i][j];
        }

        return *this;
    }

    // Постфиксный --
    Matrix operator--(int)
    {
        Matrix temp(*this);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                --data[i][j];
        }

        return temp;
    }

    int getRows() const
    {
        return rows;
    }

    int getCols() const
    {
        return cols;
    }
};


int factorial(int n)
{
    int result = 1;

    for (int i = 1; i <= n; ++i)
        result *= i;

    return result;
}


void initializeMatrix(Matrix<int>& matrix)
{
    for (int i = 0; i < matrix.getRows(); ++i)
    {
        for (int j = 0; j < matrix.getCols(); ++j)
        {
            matrix.setAt(i, j, factorial(i + j));
        }
    }
}


void printMatrix(const Matrix<int>& matrix)
{
    for (int i = 0; i < matrix.getRows(); ++i)
    {
        for (int j = 0; j < matrix.getCols(); ++j)
        {
            cout << setw(8) << matrix.at(i, j);
        }

        cout << '\n';
    }
}


Vector<int> convertToVector(const Matrix<int>& matrix)
{
    int count = 0;

    // Оставляем 1, 3, 5 строки.
    // В C++ это индексы 0, 2, 4.
    for (int i = 0; i < matrix.getRows(); ++i)
    {
        if ((i + 1) % 2 != 0)
            count += matrix.getCols();
    }

    Vector<int> result(count);

    int index = 0;

    for (int i = 0; i < matrix.getRows(); ++i)
    {
        // Пропускаем четные строки
        if ((i + 1) % 2 == 0)
            continue;

        for (int j = 0; j < matrix.getCols(); ++j)
        {
            result[index++] = matrix.at(i, j);
        }
    }

    return result;
}


void printVector(const Vector<int>& vector)
{
    for (int i = 0; i < vector.getSize(); ++i)
        cout << vector[i] << ' ';

    cout << '\n';
}


int main()
{
    Matrix<int> matrix(5, 5);

    initializeMatrix(matrix);

    cout << "Original matrix:\n";
    printMatrix(matrix);

    Vector<int> vector = convertToVector(matrix);

    cout << "\nVector after conversion:\n";
    printVector(vector);

    cout << "\nPrefix ++:\n";
    ++vector;
    printVector(vector);

    cout << "\nPostfix ++:\n";
    vector++;
    printVector(vector);

    cout << "\nPrefix --:\n";
    --vector;
    printVector(vector);

    cout << "\nPostfix --:\n";
    vector--;
    printVector(vector);

    return 0;
}