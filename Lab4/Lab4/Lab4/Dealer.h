#pragma once

#include "Hand.h"

class Dealer
{
private:
    Hand hand;

public:
    Hand& GetHand();
    const Hand& GetHand() const;

    void Hit(const Card& card);

    bool MustHit() const;

    void Reset();
};
