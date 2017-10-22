/*
 * hand.h
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"
using std::vector;

/*
 * A player's hand, containing a vector collection of cards.
 * Can exchange three cards of the same type or all of different types for
 * a number of troops, starting at 5 and going up by 5 with each new exchange.
 */
class Hand
{
public:
    Hand(); // Creates an empty hand.
    void addCard(Card newCard); // Adds a specified card to the end of the hand's card collection.
    int exchange(); //Exchanges three cards for troops in increments of five with each new exchange.
    void listCards(); // Outputs the cards in hand. For testing purposes.
    int getSize(); // Returns the number of cards in hand.
private:
    vector<Card> cards;
    Card cardAt(int index); // Returns the card at the index specified.
    int exchanges; // The number of exchanges this hand has made.
};

#endif /* HAND_H */

