/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#ifndef HAND_H
#define HAND_H

#include <vector>

using std::vector;

#include "card.h"

/*
 * A player's hand, containing a vector collection of cards.
 * Can exchange three cards of the same type or all of different types for
 * a number of troops, starting at 5 and going up by 5 with each new exchange.
 */
class Hand
{
public:
    Hand(); // Creates an empty hand and sets its exchange counter to 0.
    void addCard(Card newCard); // Adds a specified card to the end of the hand's card collection.
    Card cardAt(int index); // Returns the card at the index specified.
    int exchange(int firstCardIndex, int secondCardIndex, int thirdCardIndex); //Exchanges three cards for troops in increments of five with each new exchange.
    void listCards(); // Outputs the cards in hand. For testing purposes.
private:
    vector<Card> cards;
    int exchanges; // Number of times the player has exchanged cards.
};

#endif /* HAND_H */

