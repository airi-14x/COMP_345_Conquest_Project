/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "cards.h"

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

// Populates a deck with as many cards as there are countries on the map.
Deck::Deck(Map map)
{
    CardType newCardType = ct_infantry;
    
    /*
     * Add as many cards to the deck as there are countries on the map
     * while cycling through card types.
     */
    for (int i = 0; i < map.getMapSize(); i++)
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
    // NOTE: Should have a condition here in case deck is empty. Use exception handling?
    
    // Generate a random number from 0 to the number of cards in the deck
    // to determine which one will be drawn.
    int rng = rand() % this->cards.size();
    
    // Copy the drawn card and remove it from the deck.
    Card drawnCard = this->cards.at(rng);
    this->cards.erase(cards.begin() + rng);
        
    return drawnCard;
}

// Outputs the cards in hand. For testing purposes.
void Deck::listCards()
{
    // For testing purposes, keeping track of how many cards of each type occur.
    int infantryCards = 0;
    int artilleryCards = 0;
    int cavalryCards = 0;
    
    std::cout << "Cards in deck: " << cards.size() << std::endl;
    
    for (int i = 0; i < cards.size(); i++)
    {
        std::cout << "Card " << i << ": " << this->cardAt(i).toString() << std::endl;
        
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
    
    cout << "Infantry cards: " << infantryCards << endl;
    cout << "Artillery cards: " << artilleryCards << endl;
    cout << "Cavalry cards: " << cavalryCards << endl;
}

// Creates an empty hand.
Hand::Hand()
{
    
}

// Adds a specified card to the end of the hand's card collection.
void Hand::addCard(Card newCard)
{
    this->cards.push_back(newCard);
}

/*
 * Returns the card at the index specified.
 * NOTE: Currently only used by the object itself, and therefore private to
 * avoid out of bounds exceptions.
 */
Card Hand::cardAt(int index)
{
    return this->cards.at(index);
}

/* 
 * Exchanges three cards for troops in increments of five with each new exchange.
 * Takes three indices, sorts them, and compares the card types.
 * Exchanges the cards for a number of troops if they are all of the same
 * type or all of different types. Returns the number of troops earned or 0 if
 * no valid exchange was made.
 * 
 * NOTE: Eventually useful to alter this function to work with less user input
 * and handle out of bounds, etc. with exceptions.
 */
int Hand::exchange()
{
    // Keeps track of the number of times an exchange has been successfully made.
    static int exchanges = 0;
    
    // The three indices for card removal.
    int firstIndex, secondIndex, thirdIndex;
    
    /*
     * Ask for three indices and ensure their validity.
     * Return an error message and loop request if the input is invalid.
     */
    while (firstIndex < 0 || 
           firstIndex >= this->cards.size())
    {
        cout << "Enter the index of the first card to exchange: ";
        cin >> firstIndex;
        
        if (firstIndex < 0 || firstIndex >= this->cards.size())
            cout << endl << "ERROR: The input index is out of bounds; try again." << endl;
    }
    
    while (secondIndex < 0 || 
           secondIndex >= this->cards.size() || 
           secondIndex == firstIndex)
    {
        cout << "Enter the index of the second card to exchange: ";
        cin >> secondIndex;
        
        if (secondIndex < 0 || secondIndex >= this->cards.size())
            cout << "ERROR: index out of bounds; try again." << endl;
        
        if (secondIndex == firstIndex)
            cout << "ERROR: index already selected; try again." << endl;
    }
    
    while (thirdIndex < 0 || 
           thirdIndex >= this->cards.size() || 
           thirdIndex == firstIndex || 
           thirdIndex == secondIndex)
    {
        cout << "Enter the index of the second card to exchange: ";
        cin >> thirdIndex;
        
        if (thirdIndex < 0 || thirdIndex >= this->cards.size())
            cout << "ERROR: index out of bounds; try again." << endl;
        
        if (thirdIndex == firstIndex || thirdIndex == secondIndex)
            cout << "ERROR: index already selected; try again." << endl;
    }
    
    // Ensure all three indices are in ascending order.
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
        exchanges++;
        
        // Erase the target cards while compensating for the hand's decrease
        // in size.
        this->cards.erase(this->cards.begin() + firstIndex);
        this->cards.erase(this->cards.begin() + secondIndex - 1);
        this->cards.erase(this->cards.begin() + thirdIndex - 2);
    
        cout << "Granting " << exchanges * 5 << " troops." << endl;
        return exchanges * 5;
    }
    else
    {
        cout << "Invalid trade; exactly two cards match." << endl;
        return 0;
    }
}

// Outputs the cards in hand. For testing purposes.
void Hand::listCards()
{
    // For testing purposes, keeping track of how many cards of each type occur.
    int infantryCards = 0;
    int artilleryCards = 0;
    int cavalryCards = 0;
    
    std::cout << "Cards in hand: " << cards.size() << std::endl;
    
    for (int i = 0; i < cards.size(); i++)
    {
        cout << "Card " << i << ": " << this->cardAt(i).toString() << endl;
        
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
    
    cout << "Infantry cards: " << infantryCards << endl;
    cout << "Artillery cards: " << artilleryCards << endl;
    cout << "Cavalry cards: " << cavalryCards << endl;
}