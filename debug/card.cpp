/*
 * cards.cpp
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#include <cstdlib>
#include <iostream>
using std::cin;
using std::endl;
#include "card.h"

// Generates a card object with a random type.
Card::Card()
{
    // Generate a random number between 0 and 2 to determine card type.
    int rng = rand() % 3;

    // Assign card type based on the previously generated number.
    switch(rng)
    {
        case 0:
            this->cardType = ct_infantry;
            break;
        case 1:
            this->cardType = ct_artillery;
            break;
        default:
            this->cardType = ct_cavalry;
    }
}

// Generates a card object with a parametized type.
Card::Card(CardType cardType)
{
    this->cardType = cardType;
}

// Returns the card's type as a CardType enum variable.
CardType Card::getCardType()
{
    return this->cardType;
}

// Returns a string representation of the card's type.
std::string Card::toString()
{
    switch(this->cardType)
    {
        case ct_infantry:
            return "infantry";
            break;
        case ct_artillery:
            return "artillery";
            break;
        default:
            return "cavalry";
    }
}