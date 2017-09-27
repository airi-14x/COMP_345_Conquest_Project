/*
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

/*
 * A card deck, holding a vector collection of card objects.
 * Can draw a card at random, removing it from the deck.
 */
class Deck
{
public:
    Deck(Map map); // Populates a deck with as many cards as there are countries on the map.
    Card draw(); // Draws a card at random and removes it from the deck.
    void listCards(); // Outputs the cards in hand. For testing purposes.
private:
    vector<Card> cards;
    Card cardAt(int index); // Returns the card at the index specified.
};

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
private:
    vector<Card> cards;
    Card cardAt(int index); // Returns the card at the index specified.
};

#endif /* CARD_H */

