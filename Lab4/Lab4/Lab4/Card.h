#pragma once

#include <iostream>

enum class Suit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum class Rank
{
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card
{
private:
    Rank rank;
    Suit suit;

public:
    Card(Rank rank, Suit suit);

    Rank GetRank() const;
    Suit GetSuit() const;

    int GetValue() const;

    bool IsSeven() const;
    bool IsAce() const;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};
