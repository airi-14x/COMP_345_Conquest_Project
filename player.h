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
<<<<<<< HEAD
//#include "hand.h"
=======
#include "cards.h"
#include "Country.h"
>>>>>>> 8bf31e72ec9d88f442a3cdf0bd84f7021bb79209

// A player with its own hand of cards and troops counter.
class Player
{
public:
    Player(); // Creates a new player with no allocated troops.
    // NOTE: these three functions serve no purpose until the country files are
    // obtained. Not yet implemented to avoid compilation errors.
    void reinforce();
    void attack();
    void fortify();
    // Regular accessors/mutators.
    // NOTE: getHand() appears to return a valid hand object, but can't be used to add new cards; further troubleshooting required...
    //       The player object appears to be able to add cards on its own, so likely a scope or memory issue. Using a player-specific
    //       addCard() function in the meantime.
    //Hand getHand(); // Returns the player's hand object.
    //void addCard(Card newCard); // Adds cards to the player's hand object.
    int getTroops(); // Returns the number of troops the player possesses.
    void addTroops(int troops); // Grants new troops to the player.
    void subtractTroops(int troops); // Takes away troops from the player.
    Dice getDice(); // Get Dice
    void setDice(); // Create Dice object
private:
    //Hand playerHand;
    int playerTroops;
    Dice d1;    // Dice Object
    
};

#endif /* PLAYER_H */

