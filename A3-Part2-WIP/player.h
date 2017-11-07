/*
 * player.h
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "card.h"
#include "Map.h"
#include "Subject.h"
#include "hand.h"
#include "deck.h"
// A player with its own hand of cards and troops counter.
class Player : public Subject{
public:
    Player(); // Creates a new player with no allocated troops and no name.
    Player(string); // Creates a new named player with no allocated troops.
    int getArmies(); // Returns the number of armies the player possesses.
    void setArmies(int); // Sets a new value for the player's armies
    string getName(); // Returns the player's name.
    void setName(string); // Gives the player a name.
    
    
    // Hand functionality
    void setHand(); // Initialize the player's hand.
    Hand& getHand(); // Returns the player's hand object.

    // Map functionality
    vector<Country*> getCountries(); // Returns the collection of countries the player owns.
    void addCountry(Country*); // Adds a country to the player's country collection.
    void removeCountry(Country*); // Removes a country to the player's country collection.
    void reinforcementPhase(Map*); // Grants the player new armies and allows them to reinforce their countries.
    void grantArmies(Map*); // Grants the player new armies based on the countries and continents they control.
    void reinforce(int, Country*); // Takes troops from a player and deploys them to an owned territory.
    void attackPhase(Map*); // Allows the player to attack enemy territories in a loop.
    void attack(Map*, Country*, Country*); // Attacks an enemy country.
    void fortifyPhase(Map*); // Allows the player to fortify an allied territory.
    void fortify(Map*, Country*, Country*); // Allows the player to move armies from a country to another one, as long as they are connected.
    void resetTurn(); // Resets the value of hasConquered back to false.

    // Dice functionality
    Dice getDice(); // Returns the player's dice object.
    void setDice(); // Initializes the player's dice object.

    /*
     * Vector of players in the game.
     * Is used to keep track of player data during turns, from other player
     * objects' perspectives.
     */
    static vector<Player*> players;
    static Player* findPlayer(string); // Finds a player by name in the players vector.
    
    
    //accessors for the observer trackers
    Country* getCountryTo(){return countryTo;};
    Country* getCountryFrom(){return countryFrom;};
    int getArmyChange(){return armyChange;};
    string getCurrentPhase(){return currentPhase;};
    int getBestAttack(){return bestAttack;};    
    int getSecondBestAttack(){return secondBestAttack;};
    int getBestDefense(){return bestDefense;};    
    int getSecondBestDefense(){return secondBestDefense;};
    int getAttackDiceCount(){return attackDiceCount;};
    int getDefenseDiceCount(){return defenseDiceCount;};
    int getAttackWins(){return attackWins;};
    int getDefenseWins(){return defenseWins;}; 
    
    bool getCountryValid(){return countryValid;};
    char getContinueAttacking(){return continueAttacking;};


private:
    string playerName;
    int playerArmies;
    bool hasConquered;
    bool hasFortified;
    Dice playerDice;
    Hand playerHand;
    vector<Country*> countries;


     //Below are the variables to keep track of actions(for observer)
    Country* countryFrom; // holds country that we'd attack with/take army from
    Country* countryTo; // holds country to be attacked or fortified
    int armyChange; // any loss, or gain in army number ("Lost #{armyChange} during this attack")
    string currentPhase; //We can use this for flow control and to print which stage we're at
    int bestAttack;
    int secondBestAttack;
    int bestDefense;
    int secondBestDefense;
    
    int attackDiceCount;
    int defenseDiceCount;
    int attackWins;
    int defenseWins;
    bool countryValid;
    char continueAttacking;


};

#endif /* PLAYER_H */

