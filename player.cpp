/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#include <iostream>
#include "player.h"
using std::cout;
using std::endl;

// Creates a new player with no allocated troops.
Player::Player()
{
    playerName = "";
    playerTroops = 0;
    setDice();
    setHand();
}

// Creates a new named player with no allocated troops.
Player::Player(string playerName)
{
    this->playerName = playerName;
    playerTroops = 0;
    setDice();
    setHand();
}

// Initializes the player's dice object.
void Player::setDice()
{
    Dice playerDice; // Create Dice object with default constructor on heap.
}

// Returns the player's dice object.
Dice Player::getDice()
{
    return playerDice;
}

// Initializes the player's hand object.
void Player::setHand()
{
    Hand playerHand;
}

// Returns the player's hand object.
Hand& Player::getHand()
{
    return playerHand;
}

// Returns the number of troops the player possesses.
int Player::getTroops()
{
    return playerTroops;
}

// Grants new troops to the player.
void Player::addTroops(int troops)
{
    playerTroops += troops;
}

// Takes away troops from the player.
void Player::subtractTroops(int troops)
{
    playerTroops -= troops;
}

// Returns the collection of countries the player owns.
vector<Country*> Player::getCountries()
{
    return countries;
}

// Adds a country to the player's country collection.
void Player::addCountry(Country* country)
{
    countries.push_back(country);
}

// Removes a country to the player's country collection.
void Player::removeCountry(Country* country)
{
    // Search the player's country collection to find where the target is, then erase it.
    for(int i = 0; i < countries.size(); i++)
    {
        if (countries.at(i) == country)
            countries.erase(countries.begin() + i);
    }
}

// Takes troops from a player and deploys them to an owned territory.
void Player::reinforce(int troops, Country* country)
{
    /*
     * Confirm that the player has enough troops, otherwise give an error
     * message and let the function terminate.
     */
    if (troops <= playerTroops && troops > 0)
    {
        // Marker to validate the presence of the country in the player's collection.
        bool countryValid = false;
        
        // Check the player's collection, validate if the country is found.
        for (int i = 0; i < countries.size(); i++)
        {
            if (countries.at(i)->getName() == country->getName())
            {
                countryValid = true;
                break;
            }
        }
        
        // If the country is found, add parametized troops to it and subtract them from the player's troops.
        if (countryValid)
        {
            country->setArmyNum(country->getArmyNum() + troops);
            playerTroops -= troops;
            cout << country->getName() << " reinforced with " << troops << " troops." << endl;
        }
        else
            cout << country->getName() << " is not owned by " << playerName << "; reinforcement aborted." << endl;
        
    }
    else if (troops > 0)
        cout << "Not enough troops; this action cannot be taken." << endl;
    else
        cout << "Cannot reinforce with 0 or fewer troops." << endl;
    
    cout << playerName << " has " << playerTroops << " deployable troops." << endl;
}

void Player::attack(Map map, Country* attackingCountry, Country* defendingCountry)
{
    /* 
     * The following conditions must be met for a valid attack:
     * - The attacking country belongs to the attacker.
     * - The defending country does not belong to the attacker.
     * - The two countries are adjacent.
     * - The attacking country has more than 1 army in it.
     */
    
    // Markers to ensure the attacking country is owned by the correct player 
    // and that the attack as a whole is valid.
    bool attackingCountryValid = false;
    bool attackValid = false;
        
    // Check the player's collection, validate if the country is found.
    for (int i = 0; i < countries.size(); i++)
    {
        if (countries.at(i)->getName() == attackingCountry->getName())
        {
            attackingCountryValid = true;
            break;
        }
    }
    
    // Continue if the attacking country is owned by the attacking player.
    if (attackingCountryValid)
    {
        // Check if the defending country belongs to an opponent.
        if (defendingCountry->getPlayerName() != playerName)
        {
            // Check if the two countries are adjacent.
            if (map.areAdjacent(*attackingCountry, *defendingCountry))
            {
                if (attackingCountry->getArmyNum() > 1)
                {
                    attackValid = true;
                }
                else
                    cout << attackingCountry->getName() << " doesn't have enough troops to attack." << endl;
            }
            else
                cout << attackingCountry->getName() << " and " << defendingCountry->getName() << " are not adjacent." << endl;
        }
        else
            cout << defendingCountry->getName() << " is already owned by " << playerName << "." << endl;
    }
    else
        cout << attackingCountry->getName() << "is not owned by " << playerName << "." << endl;
    
    // If the attack conditions are met
    if (attackValid)
    {
        // CONTINUE FROM HERE
    }
}