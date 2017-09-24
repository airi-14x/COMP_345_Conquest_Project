/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#include <cstdlib>

#include "deck.h"

/* 
 * Populates a deck with as many cards as specified.
 * NOTE: This solution is temporary; a default Deck() constructor should get
 * deck size from the size of the country collection on the map.
*/ 
Deck::Deck(int size)
{
    /* 
     * NOTE: Will require a way to get the number of countries from the map
     * object..
     */ 
    
    // Add as many cards to the deck as specified in parameters.
    for (int i = 0; i < size; i++)
    {
        this->cards.push_back(Card());
    }
}

// Draws a card at random and removes it from the deck.
Card Deck::draw()
{
    // NOTE: Should have a condition here in case deck is empty. Use exception handling?
    
    // Generate a random number from 0 to the number of cards in the deck
    // to determine which one will be drawn.
    int rng = rand() % this->cards.size();
    
    // Copy the drawn card and remove it from the deck.
    Card drawnCard = this->cards.at(rng);
    this->cards.erase(cards.begin() + rng);
        
    return drawnCard;
}