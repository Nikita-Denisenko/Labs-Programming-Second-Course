#pragma once

#include "Card.h"

#include <vector>

class Hand
{
private:
    std::vector<Card> cards;

public:
    void AddCard(const Card& card);

    int GetScore() const;
    bool IsBust() const;
    bool IsBlackjack() const;
    bool Is777() const;

    size_t GetCardCount() const;
    const std::vector<Card>& GetCards() const;

    void Clear();
    bool IsSoft() const;
};
