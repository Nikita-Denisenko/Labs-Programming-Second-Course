#include "Dealer.h"

Hand& Dealer::GetHand()
{
    return hand;
}

const Hand& Dealer::GetHand() const
{
    return hand;
}

void Dealer::Hit(const Card& card)
{
    hand.AddCard(card);
}

bool Dealer::MustHit() const
{
    return hand.GetScore() < 17 ||
        (hand.GetScore() == 17 && hand.IsSoft());
}

void Dealer::Reset()
{
    hand.Clear();
}
