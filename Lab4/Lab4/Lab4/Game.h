#pragma once

#include "Dealer.h"
#include "Deck.h"
#include "Player.h"

#include <exception>
#include <string>

class BustException : public std::exception
{
public:
    const char* what() const noexcept override;
};

enum class GameResult
{
    PlayerWin,
    DealerWin,
    Draw,
    Blackjack,
    Lucky777
};

class Game
{
private:
    Deck deck;
    Player player;
    Dealer dealer;

    void DealInitialCards();

    void PlayerTurn();

    void DealerTurn();

    void PrintPlayerHand() const;

    void PrintDealerHand(bool revealAll) const;

    GameResult DetermineResult() const;

    void PrintResult(GameResult result) const;

    void CheckBust(const Hand& hand) const;

public:
    void Play();
};
