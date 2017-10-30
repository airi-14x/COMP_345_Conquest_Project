/*
 * deck.h
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Map.h"
#include "card.h"
using std::vector;

/*
 * A card deck, holding a vector collection of card objects.
 * Can draw a card at random, removing it from the deck.
 */
class Deck
{
public:
    Deck(Map* map); // Populates a deck with as many cards as there are countries on the map.
    Card draw(); // Draws a card at random and removes it from the deck.
    void listCards(); // Outputs the cards in hand. For testing purposes.
    int getSize(); // Returns the number of cards in the deck.
private:
    vector<Card> cards;
    Card cardAt(int index); // Returns the card at the index specified.
};

#endif /* DECK_H */

