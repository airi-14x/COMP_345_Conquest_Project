/*
 * player.h
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "hand.h"
#include "deck.h"
#include "Map.h"

// A player with its own hand of cards and troops counter.
class Player
{
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
private:
    string playerName;
    int playerArmies;
    bool hasConquered;
    bool hasFortified;
    Dice playerDice;
    Hand playerHand;
    vector<Country*> countries;
};

#endif /* PLAYER_H */

