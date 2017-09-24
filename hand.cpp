/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#include <iostream>

#include "hand.h"

// Creates an empty hand and sets its exchange counter to 0.
Hand::Hand()
{
    this->exchanges = 0;
}

// Adds a specified card to the end of the hand's card collection.
void Hand::addCard(Card newCard)
{
    this->cards.push_back(newCard);
}

// Returns the card at the index specified.
// NOTE: Can result in out of bounds exceptions; use exception handling.
Card Hand::cardAt(int index)
{
    return this->cards.at(index);
}

/* 
 * Exchanges three cards for troops in increments of five with each new exchange.
 * Takes three indices, sorts them, and compares the card types.
 * Exchanges the cards for a number of troops if they are all of the same
 * type or all of different types.
 * 
 * NOTE: Can result in out of bounds exceptions; implement exception handling.
 */
int Hand::exchange(int firstIndex, int secondIndex, int thirdIndex)
{
    //Ensure all three indices are in ascending order.
    if (firstIndex > secondIndex)
    {
        int tempIndex = firstIndex;
        firstIndex = secondIndex;
        secondIndex = tempIndex;
    }
    
    if (firstIndex > thirdIndex)
    {
        int tempIndex = firstIndex;
        firstIndex = thirdIndex;
        thirdIndex = tempIndex;
    }
    
    if (secondIndex > thirdIndex)
    {
        int tempIndex = secondIndex;
        secondIndex = thirdIndex;
        thirdIndex = tempIndex;
    }
    
    // If all three cards are of the same type or all of different types,
    // increment the exchanges counter and return the number of troops earned.
    // NOTE: Could use exception handling to handle invalid exchange cases.
    if ((cards.at(firstIndex).getCardType() == cards.at(secondIndex).getCardType() && 
         cards.at(secondIndex).getCardType() == cards.at(thirdIndex).getCardType()) || 
        (cards.at(firstIndex).getCardType() != cards.at(secondIndex).getCardType() && 
         cards.at(secondIndex).getCardType() != cards.at(thirdIndex).getCardType() && 
         cards.at(firstIndex).getCardType() != cards.at(thirdIndex).getCardType()))
    {
        this->exchanges++;
        
        // Erase the target cards while compensating for the hand's decrease
        // in size.
        this->cards.erase(this->cards.begin() + firstIndex);
        this->cards.erase(this->cards.begin() + secondIndex - 1);
        this->cards.erase(this->cards.begin() + thirdIndex - 2);
    
        return this->exchanges * 5;
    }
    else
        return 0;
}

// Outputs the cards in hand. For testing purposes.
void Hand::listCards()
{
    std::cout << "Cards: " << cards.size() << std::endl;
    
    for (int i = 0; i < cards.size(); i++)
    {
        std::cout << "Card " << i << ": " << this->cardAt(i).toString() << std::endl;
    }
}