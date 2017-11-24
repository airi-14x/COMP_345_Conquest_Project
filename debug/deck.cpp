/*
 * deck.cpp
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#include <cstdlib>
#include <iostream>
using std::cin;
using std::endl;
#include "deck.h"

// Populates a deck with as many cards as there are countries on the map.
Deck::Deck(Map* map)
{
    CardType newCardType = ct_infantry;

    /*
     * Add as many cards to the deck as there are countries on the map
     * while cycling through card types.
     */
    for (int i = 0; i < map->getMapSize(); i++)
    {
        this->cards.push_back(Card(newCardType));

        switch(newCardType)
        {
            case ct_infantry:
                newCardType = ct_artillery;
                break;
            case ct_artillery:
                newCardType = ct_cavalry;
                break;
            default:
                newCardType = ct_infantry;
        }
    }
}

/*
 * Returns the card at the index specified.
 * NOTE: Currently only used by the object itself, and therefore private to
 * avoid out of bounds exceptions.
 */
Card Deck::cardAt(int index)
{
    return this->cards.at(index);
}

// Draws a card at random and removes it from the deck.
Card Deck::draw()
{
    if (this->getSize() >= 1)
    {
        // Generate a random number from 0 to the number of cards in the deck
        // to determine which one will be drawn.
        int rng = rand() % this->cards.size();

        // Copy the drawn card and remove it from the deck.
        Card drawnCard = this->cards.at(rng);
        this->cards.erase(cards.begin() + rng);

        return drawnCard;
    }
    Notify();
}

// Outputs the cards in hand. For testing purposes.
void Deck::listCards()
{
    // For testing purposes, keeping track of how many cards of each type occur.
    int infantryCards = 0;
    int artilleryCards = 0;
    int cavalryCards = 0;

    for (int i = 0; i < cards.size(); i++)
    {

        // Count the occurrences of each card type. For testing purposes.
        switch(this->cardAt(i).getCardType())
        {
            case ct_infantry:
                infantryCards++;
                break;
            case ct_artillery:
                artilleryCards++;
                break;
            default:
                cavalryCards++;
        }
    }
}

// Returns the number of cards in the deck.
int Deck::getSize()
{
    return cards.size();
}

