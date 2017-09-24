/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#ifndef DECK_H
#define DECK_H

#include <vector>

using std::vector;

#include "card.h"
#include "Map.h"

/*
 * A card deck, holding a vector collection of card objects.
 * Can draw a card at random, removing it from the deck.
 */
class Deck
{
public:
    Deck(Map map); // Populates a deck with as many cards as there are countries on the map.
    Card draw(); // Draws a card at random and removes it from the deck.
private:
    vector<Card> cards;
};

#endif /* DECK_H */

