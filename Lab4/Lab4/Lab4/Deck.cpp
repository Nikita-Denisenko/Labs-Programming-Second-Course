#include "Deck.h"

#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck()
    : currentCard(0)
{
    CreateDecks();
    Shuffle();
}

void Deck::CreateDecks()
{
    cards.clear();

    for (int deck = 0; deck < 4; ++deck)
    {
        for (int suit = 0; suit < 4; ++suit)
        {
            for (int rank = 2; rank <= 14; ++rank)
            {
                cards.emplace_back(
                    static_cast<Rank>(rank),
                    static_cast<Suit>(suit));
            }
        }
    }
}

void Deck::Shuffle()
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(
        cards.begin(),
        cards.end(),
        generator);

    currentCard = 0;
}

Card Deck::Draw()
{
    if (Empty())
    {
        throw std::runtime_error("Колода пуста.");
    }

    return cards[currentCard++];
}

bool Deck::Empty() const
{
    return currentCard >= cards.size();
}

size_t Deck::Remaining() const
{
    return cards.size() - currentCard;
}
