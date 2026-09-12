#include "DataManager.h"

#include <Windows.h>
#include <iostream>
#include <cstdio>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::remove("dump.dat");

    std::cout << "===== INT =====\n";

    DataManager<int> intManager;

    intManager.push(10);
    intManager.push(20);
    intManager.push(30);

    std::cout << "После push: ";
    intManager.print();

    std::cout << "peek(): "
        << intManager.peek()
        << '\n';

    std::cout << "pop(): "
        << intManager.pop()
        << '\n';

    std::cout << "После pop: ";
    intManager.print();


    std::cout << "\n===== DOUBLE =====\n";

    DataManager<double> doubleManager;

    double values[] =
    {
        1.5,
        2.5,
        3.5,
        4.5
    };

    doubleManager.push(values, 4);

    std::cout << "После push массива: ";
    doubleManager.print();

    std::cout << "peek(): "
        << doubleManager.peek()
        << '\n';

    std::cout << "pop(): "
        << doubleManager.pop()
        << '\n';

    std::cout << "После pop: ";
    doubleManager.print();


    std::cout << "\n===== CHAR =====\n";

    DataManager<char> charManager;

    char chars[] =
    {
        'a',
        '!',
        'b',
        '?',
        'c'
    };

    charManager.push(chars, 5);

    std::cout << "После push массива: ";
    charManager.print();

    std::cout << "peek(): "
        << charManager.peek()
        << '\n';

    std::cout << "popUpper(): "
        << charManager.popUpper()
        << '\n';

    std::cout << "После popUpper: ";
    charManager.print();

    std::cout << "popLower(): "
        << charManager.popLower()
        << '\n';

    std::cout << "После popLower: ";
    charManager.print();


    std::cout << "\n===== PUNCTUATION =====\n";

    DataManager<char> punctuationManager;

    punctuationManager.push('!');
    punctuationManager.push('?');
    punctuationManager.push('.');
    punctuationManager.push('A');

    std::cout << "Пунктуация заменена: ";
    punctuationManager.print();


    std::cout << "\n===== DUMP =====\n";

    DataManager<int> dumpManager;

    for (int i = 1; i <= 64; ++i)
    {
        dumpManager.push(i);
    }

    std::cout << "Размер после заполнения: "
        << dumpManager.getSize()
        << '\n';

    dumpManager.push(65);

    std::cout << "Размер после добавления 65: "
        << dumpManager.getSize()
        << '\n';

    std::cout << "Текущие данные: ";
    dumpManager.print();

    std::cout << "pop(): "
        << dumpManager.pop()
        << '\n';

    std::cout << "Размер после pop: "
        << dumpManager.getSize()
        << '\n';

    std::cout << "Данные после загрузки из dump.dat: ";
    dumpManager.print();


    std::remove("dump.dat");

    return 0;
}