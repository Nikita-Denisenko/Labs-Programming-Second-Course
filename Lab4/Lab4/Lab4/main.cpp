#include "Game.h"

#include <Windows.h>
#include <iostream>

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Game game;

    char answer;

    do
    {
        game.Play();

        std::cout << "\nСыграть еще раз? (y/n): ";
        std::cin >> answer;

        std::cout << '\n';

    } while (answer == 'y' || answer == 'Y');

    std::cout << "Игра завершена.\n";

    return 0;
}