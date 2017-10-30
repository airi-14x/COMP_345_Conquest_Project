/*
 * cards.h
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include "Map.h"
using std::vector;

// Enumerator to keep track of a card's type.
enum CardType { ct_infantry, ct_artillery, ct_cavalry };

/*
 * Cards to populate deck and hand objects. Each card has a type used for
 * combining when exchanging for troops.
 */
class Card
{
public:
    Card(); // Generates a card object with a random type.
    Card(CardType cardType); // Generates a card object with a parametized type.
    CardType getCardType(); // Returns the card's type as a CardType enum variable.
    std::string toString(); // Returns a string representation of the card's type.
private:
    CardType cardType; // A card's type, either infantry, artillery, or cavalry.
};

#endif /* CARD_H */

