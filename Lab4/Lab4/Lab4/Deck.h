#pragma once

#include "Card.h"

#include <vector>

class Deck
{
private:
    std::vector<Card> cards;
    size_t currentCard;

    void CreateDecks();

public:
    Deck();

    void Shuffle();

    Card Draw();

    bool Empty() const;
    size_t Remaining() const;
};
