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

void Player::reinforce(int troops, Country* country)
{
    /*
     * Confirm that the player has enough troops, otherwise give an error
     * message and let the function terminate.
     */
    if (troops <= playerTroops && troops > 0)
    {
        // Marker to validate the presence of the country in the player's collection.
        bool countryFound = false;
        
        for (int i = 0; i < countries.size(); i++)
        {
            if ((*countries.at(i)).getName() == (*country).getName())
            {
                countryFound = true;
            }
        }
        
        if (countryFound)
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