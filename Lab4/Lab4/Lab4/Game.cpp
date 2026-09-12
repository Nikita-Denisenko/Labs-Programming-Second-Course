#include "Game.h"

#include <iostream>

const char* BustException::what() const noexcept
{
    return "Перебор! Сумма очков больше 21.";
}

void Game::DealInitialCards()
{
    player.Hit(deck.Draw());
    dealer.Hit(deck.Draw());

    player.Hit(deck.Draw());
    dealer.Hit(deck.Draw());
}

void Game::PrintPlayerHand() const
{
    std::cout << "Карты игрока: ";

    for (const Card& card : player.GetHand().GetCards())
    {
        std::cout << card << ' ';
    }

    std::cout << "\nОчки игрока: "
        << player.GetHand().GetScore()
        << "\n";
}

void Game::PrintDealerHand(bool revealAll) const
{
    std::cout << "Карты дилера: ";

    const auto& cards = dealer.GetHand().GetCards();

    for (size_t i = 0; i < cards.size(); ++i)
    {
        if (!revealAll && i == 1)
        {
            std::cout << "?? ";
        }
        else
        {
            std::cout << cards[i] << ' ';
        }
    }

    std::cout << '\n';

    if (revealAll)
    {
        std::cout << "Очки дилера: "
            << dealer.GetHand().GetScore()
            << "\n";
    }
}

void Game::CheckBust(const Hand& hand) const
{
    if (hand.IsBust())
    {
        throw BustException();
    }
}

void Game::PlayerTurn()
{
    while (true)
    {
        PrintPlayerHand();

        if (player.GetHand().Is777())
        {
            std::cout << "\n777! Особая комбинация!\n";
            return;
        }

        if (player.GetHand().IsBlackjack())
        {
            if (dealer.GetHand().IsBlackjack())
            {
                PrintDealerHand(true);
                PrintResult(GameResult::Draw);
            }
            else
            {
                PrintDealerHand(true);
                PrintResult(GameResult::Blackjack);
            }

            return;
        }

        std::cout << "\nВыберите действие:\n";
        std::cout << "1 - Hit\n";
        std::cout << "2 - Stand\n";

        if (player.GetHand().GetCardCount() == 2)
        {
            std::cout << "3 - Double\n";
        }

        std::cout << "> ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            player.Hit(deck.Draw());

            try
            {
                CheckBust(player.GetHand());
            }
            catch (const BustException& exception)
            {
                std::cout << "\n" << exception.what() << "\n";
                throw;
            }
        }
        else if (choice == 2)
        {
            return;
        }
        else if (
            choice == 3 &&
            player.GetHand().GetCardCount() == 2)
        {
            std::cout << "\nDouble! Ставка удвоена.\n";

            player.DoubleDown(deck.Draw());

            try
            {
                CheckBust(player.GetHand());
            }
            catch (const BustException& exception)
            {
                std::cout << "\n" << exception.what() << "\n";
                throw;
            }

            PrintPlayerHand();
            return;
        }
        else
        {
            std::cout << "Некорректный выбор.\n";
        }
    }
}

void Game::DealerTurn()
{
    std::cout << "\nХод дилера.\n";

    PrintDealerHand(true);

    while (dealer.MustHit())
    {
        std::cout << "Дилер берет карту.\n";

        dealer.Hit(deck.Draw());

        PrintDealerHand(true);
    }

    if (dealer.GetHand().IsBust())
    {
        std::cout << "Дилер перебрал.\n";
    }
    else
    {
        std::cout << "Дилер останавливается.\n";
    }
}

GameResult Game::DetermineResult() const
{
    const Hand& playerHand = player.GetHand();
    const Hand& dealerHand = dealer.GetHand();

    if (playerHand.Is777())
    {
        return GameResult::Lucky777;
    }

    if (playerHand.IsBlackjack())
    {
        return GameResult::Blackjack;
    }

    if (playerHand.IsBust())
    {
        return GameResult::DealerWin;
    }

    if (dealerHand.IsBust())
    {
        return GameResult::PlayerWin;
    }

    if (playerHand.GetScore() > dealerHand.GetScore())
    {
        return GameResult::PlayerWin;
    }

    if (playerHand.GetScore() < dealerHand.GetScore())
    {
        return GameResult::DealerWin;
    }

    return GameResult::Draw;
}

void Game::PrintResult(GameResult result) const
{
    std::cout << "\n========== РЕЗУЛЬТАТ ==========\n";

    switch (result)
    {
    case GameResult::PlayerWin:
        std::cout << "Победа игрока!\n";
        break;

    case GameResult::DealerWin:
        std::cout << "Победа дилера!\n";
        break;

    case GameResult::Draw:
        std::cout << "Ровно! Ничья.\n";
        break;

    case GameResult::Blackjack:
        std::cout << "BLACKJACK! Победа игрока с бонусом 3:2.\n";
        break;

    case GameResult::Lucky777:
        std::cout << "777! Особый бонус за три семерки!\n";
        break;
    }

    std::cout << "================================\n";
}

void Game::Play()
{
    player.Reset();
    dealer.Reset();

    std::cout << "================================\n";
    std::cout << "      EUROPEAN BLACKJACK\n";
    std::cout << "       SPECIAL 777\n";
    std::cout << "================================\n\n";

    DealInitialCards();

    PrintPlayerHand();
    PrintDealerHand(false);

    try
    {
        PlayerTurn();
    }
    catch (const BustException&)
    {
        PrintResult(GameResult::DealerWin);
        return;
    }

    if (player.GetHand().Is777())
    {
        PrintResult(GameResult::Lucky777);
        return;
    }

    if (player.GetHand().IsBlackjack())
    {
        PrintResult(GameResult::Blackjack);
        return;
    }

    DealerTurn();

    PrintResult(DetermineResult());
}
