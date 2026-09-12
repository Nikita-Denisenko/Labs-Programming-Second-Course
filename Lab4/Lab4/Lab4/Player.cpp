#include "Player.h"

Player::Player()
    : doubled(false)
{
}

Hand& Player::GetHand()
{
    return hand;
}

const Hand& Player::GetHand() const
{
    return hand;
}

void Player::Hit(const Card& card)
{
    hand.AddCard(card);
}

void Player::DoubleDown(const Card& card)
{
    doubled = true;
    hand.AddCard(card);
}

bool Player::HasDoubled() const
{
    return doubled;
}

void Player::Reset()
{
    hand.Clear();
    doubled = false;
}
