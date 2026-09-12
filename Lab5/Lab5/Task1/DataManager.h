#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cctype>

template <typename T>
class DataManager
{
protected:
    static const int Capacity = 64;

    T data[Capacity];
    int size;

    void DumpToFile()
    {
        std::ofstream file(
            "dump.dat",
            std::ios::binary | std::ios::app);

        if (!file)
        {
            throw std::runtime_error(
                "Не удалось открыть dump.dat.");
        }

        file.write(
            reinterpret_cast<const char*>(data),
            size * sizeof(T));

        file.close();

        size = 0;
    }

    void LoadFromFile()
    {
        std::ifstream file(
            "dump.dat",
            std::ios::binary);

        if (!file)
        {
            return;
        }

        file.seekg(0, std::ios::end);

        std::streamoff fileSize = file.tellg();

        if (fileSize <= 0)
        {
            file.close();
            return;
        }

        file.seekg(0, std::ios::beg);

        int count = static_cast<int>(
            fileSize / sizeof(T));

        if (count > Capacity)
        {
            count = Capacity;
        }

        file.read(
            reinterpret_cast<char*>(data),
            count * sizeof(T));

        file.close();

        size = count;

        std::ofstream clearFile(
            "dump.dat",
            std::ios::binary | std::ios::trunc);

        clearFile.close();
    }

public:
    DataManager()
        : size(0)
    {
    }

    void push(T elem)
    {
        if (size == Capacity)
        {
            DumpToFile();
        }

        for (int i = size; i > 0; --i)
        {
            data[i] = data[i - 1];
        }

        data[0] = elem;
        ++size;
    }

    void push(T elems[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            push(elems[i]);
        }
    }

    T peek() const
    {
        if (size < 2)
        {
            return T();
        }

        return data[1];
    }

    T pop()
    {
        if (size == 0)
        {
            throw std::runtime_error(
                "Набор пуст.");
        }

        T result = data[size - 1];

        --size;

        if (size == 0)
        {
            LoadFromFile();
        }

        return result;
    }

    int getSize() const
    {
        return size;
    }

    bool empty() const
    {
        return size == 0;
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ';
        }

        std::cout << '\n';
    }
};


template <>
class DataManager<char>
{
private:
    static const int Capacity = 64;

    char data[Capacity];
    int size;

    bool IsPunctuation(char ch) const
    {
        return std::ispunct(
            static_cast<unsigned char>(ch)) != 0;
    }

    void DumpToFile()
    {
        std::ofstream file(
            "dump.dat",
            std::ios::binary | std::ios::app);

        if (!file)
        {
            throw std::runtime_error(
                "Не удалось открыть dump.dat.");
        }

        file.write(data, size);

        file.close();

        size = 0;
    }

    void LoadFromFile()
    {
        std::ifstream file(
            "dump.dat",
            std::ios::binary);

        if (!file)
        {
            return;
        }

        file.seekg(0, std::ios::end);

        std::streamoff fileSize = file.tellg();

        if (fileSize <= 0)
        {
            file.close();
            return;
        }

        file.seekg(0, std::ios::beg);

        int count = static_cast<int>(fileSize);

        if (count > Capacity)
        {
            count = Capacity;
        }

        file.read(data, count);

        file.close();

        size = count;

        std::ofstream clearFile(
            "dump.dat",
            std::ios::binary | std::ios::trunc);

        clearFile.close();
    }

public:
    DataManager()
        : size(0)
    {
    }

    void push(char elem)
    {
        if (IsPunctuation(elem))
        {
            elem = '_';
        }

        if (size == Capacity)
        {
            DumpToFile();
        }

        for (int i = size; i > 0; --i)
        {
            data[i] = data[i - 1];
        }

        data[0] = elem;
        ++size;
    }

    void push(char elems[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            push(elems[i]);
        }
    }

    char peek() const
    {
        if (size < 2)
        {
            return '\0';
        }

        return data[1];
    }

    char pop()
    {
        if (size == 0)
        {
            throw std::runtime_error(
                "Набор пуст.");
        }

        char result = data[size - 1];

        --size;

        if (size == 0)
        {
            LoadFromFile();
        }

        return result;
    }

    char popUpper()
    {
        char result = pop();

        return static_cast<char>(
            std::toupper(
                static_cast<unsigned char>(result)));
    }

    char popLower()
    {
        char result = pop();

        return static_cast<char>(
            std::tolower(
                static_cast<unsigned char>(result)));
    }

    int getSize() const
    {
        return size;
    }

    bool empty() const
    {
        return size == 0;
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ';
        }

        std::cout << '\n';
    }
};