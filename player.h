/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

// TO DO: Consolidate with other parts to add dice rolling facility and 
// countries collection.

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "hand.h"
#include "Country.h"

// A player with its own hand of cards and troops counter.
class Player
{
public:
    Player(); // Creates a new player with no allocated troops.
    
    // Hand functionality
    Hand setHand(); // Initialize the player's hand.
    Hand getHand(); // Returns the player's hand object.
    void addCard(Card newCard); // Adds cards to the player's hand object.
    
    // Map functionality
    vector<Country> getCountries(); // Returns the collection of countries the player owns.
    int getTroops(); // Returns the number of troops the player possesses.
    void addTroops(int troops); // Grants new troops to the player.
    void subtractTroops(int troops); // Takes away troops from the player.
    // NOTE: these three functions serve no purpose until the country files are
    // obtained. Not yet implemented to avoid compilation errors.
    void reinforce();
    void attack();
    void fortify();
    
    // Dice functionality
    Dice getDice(); // Returns the player's dice object.
    void setDice(); // Initializes the player's dice object.
private:
    Hand playerHand;
    int playerTroops;
    vector<Country> countries;
    Dice playerDice;
};

#endif /* PLAYER_H */

