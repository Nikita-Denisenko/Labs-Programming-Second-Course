#include "Hand.h"

#include <algorithm>
#include <numeric>

void Hand::AddCard(const Card& card)
{
    cards.push_back(card);
}

int Hand::GetScore() const
{
    int score = std::accumulate(
        cards.begin(),
        cards.end(),
        0,
        [](int total, const Card& card)
        {
            return total + card.GetValue();
        });

    int aces = static_cast<int>(
        std::count_if(
            cards.begin(),
            cards.end(),
            [](const Card& card)
            {
                return card.IsAce();
            }));

    while (score > 21 && aces > 0)
    {
        score -= 10;
        --aces;
    }

    return score;
}

bool Hand::IsBust() const
{
    return GetScore() > 21;
}

bool Hand::IsBlackjack() const
{
    return cards.size() == 2 &&
        GetScore() == 21;
}

bool Hand::Is777() const
{
    return cards.size() == 3 &&
        std::count_if(
            cards.begin(),
            cards.end(),
            [](const Card& card)
            {
                return card.IsSeven();
            }) == 3;
}

size_t Hand::GetCardCount() const
{
    return cards.size();
}

const std::vector<Card>& Hand::GetCards() const
{
    return cards;
}

void Hand::Clear()
{
    cards.clear();
}

bool Hand::IsSoft() const
{
    int score = std::accumulate(
        cards.begin(),
        cards.end(),
        0,
        [](int total, const Card& card)
        {
            if (card.IsAce())
            {
                return total + 1;
            }

            return total + card.GetValue();
        });

    int aces = static_cast<int>(
        std::count_if(
            cards.begin(),
            cards.end(),
            [](const Card& card)
            {
                return card.IsAce();
            }));

    return aces > 0 && score + 10 <= 21;
}
