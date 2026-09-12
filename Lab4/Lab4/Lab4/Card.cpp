#include "Card.h"

Card::Card(Rank rank, Suit suit)
    : rank(rank), suit(suit)
{
}

Rank Card::GetRank() const
{
    return rank;
}

Suit Card::GetSuit() const
{
    return suit;
}

int Card::GetValue() const
{
    switch (rank)
    {
    case Rank::Two:
        return 2;
    case Rank::Three:
        return 3;
    case Rank::Four:
        return 4;
    case Rank::Five:
        return 5;
    case Rank::Six:
        return 6;
    case Rank::Seven:
        return 7;
    case Rank::Eight:
        return 8;
    case Rank::Nine:
        return 9;
    case Rank::Ten:
    case Rank::Jack:
    case Rank::Queen:
    case Rank::King:
        return 10;
    case Rank::Ace:
        return 11;
    }

    return 0;
}

bool Card::IsSeven() const
{
    return rank == Rank::Seven;
}

bool Card::IsAce() const
{
    return rank == Rank::Ace;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    switch (card.rank)
    {
    case Rank::Two:
        os << '2';
        break;
    case Rank::Three:
        os << '3';
        break;
    case Rank::Four:
        os << '4';
        break;
    case Rank::Five:
        os << '5';
        break;
    case Rank::Six:
        os << '6';
        break;
    case Rank::Seven:
        os << '7';
        break;
    case Rank::Eight:
        os << '8';
        break;
    case Rank::Nine:
        os << '9';
        break;
    case Rank::Ten:
        os << "10";
        break;
    case Rank::Jack:
        os << 'J';
        break;
    case Rank::Queen:
        os << 'Q';
        break;
    case Rank::King:
        os << 'K';
        break;
    case Rank::Ace:
        os << 'A';
        break;
    }

    switch (card.suit)
    {
    case Suit::Clubs:
        os << "♣";
        break;

    case Suit::Diamonds:
        os << "♦";
        break;

    case Suit::Hearts:
        os << "♥";
        break;

    case Suit::Spades:
        os << "♠";
        break;

        return os;
    }
}