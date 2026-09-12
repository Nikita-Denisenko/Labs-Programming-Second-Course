#pragma once

#include "Hand.h"

class Player
{
private:
    Hand hand;
    bool doubled;

public:
    Player();

    Hand& GetHand();
    const Hand& GetHand() const;

    void Hit(const Card& card);

    void DoubleDown(const Card& card);

    bool HasDoubled() const;

    void Reset();
};
