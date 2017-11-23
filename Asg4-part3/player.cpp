/*
 * player.cpp
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#include <iostream>
#include "player.h"
using std::cin;
using std::cout;
using std::endl;

vector<Player*> Player::players;

// Creates a new player with no allocated troops.
Player::Player()
{
    playerName = "";
    playerArmies = 0;
    hasConquered = false;
    setDice();
    setHand();

    playerStrategy = new HumanStrategy;

    players.push_back(this);
}

// Creates a new named player with no allocated troops.
Player::Player(string playerName)
{
    this->playerName = playerName;
    playerArmies = 0;
    hasConquered = false;
    setDice();
    setHand();

    playerStrategy = new HumanStrategy;

    players.push_back(this);
}

// Creates a new named player with no allocated troops.
Player::Player(string playerName, Strategy* playerStrategy)
{
    this->playerName = playerName;
    playerArmies = 0;
    hasConquered = false;
    setDice();
    setHand();

    this->playerStrategy = playerStrategy;

    players.push_back(this);
}

string Player::getName(){
    return playerName;
}

void Player::setName(string name)
{
    playerName = name;
}

// Initializes the player's dice object.
void Player::setDice()
{
    Dice playerDice; // Create Dice object with default constructor on heap.
}

// Returns the player's dice object.
Dice* Player::getDice()
{
    return &playerDice;
}

// Initializes the player's hand object.
void Player::setHand()
{
    Hand playerHand;
}

// Returns the player's hand object.
Hand* Player::getHand()
{
    return &playerHand;
}

// Returns the number of armies the player possesses.
int Player::getArmies()
{
    return playerArmies;
}

// Grants new armies to the player.
void Player::setArmies(int armies)
{
    playerArmies = armies;
}

// Returns the collection of countries the player owns.
vector<Country*>* Player::getCountries()
{
    return &countries;
}

// Adds a country to the player's country collection.
void Player::addCountry(Country* country)
{
    countries.push_back(country);

    country->setPlayerName(playerName);

    // Check which strategy is being used and set player type on the country as necessary
    country->setHuman(playerStrategy->isHuman());
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

// Grants the player new armies and allows them to reinforce their countries.
void Player::reinforceLoop(Map* m, Deck* d)
{
    playerStrategy->reinforceLoop(playerName, &countries, &playerHand, &playerDice, &hasConquered, m, d);
}

// Allows the player to attack enemy territories in a loop.
bool Player::attackLoop(Map* m, Deck* d)
{
    playerStrategy->attackLoop(playerName, &countries, &playerHand, &playerDice, &hasConquered, m, d);

    if (countries.size() == m->getMapSize())
    {
        return true;
    }

    return false;
}

// Allows the player to fortify one allied territory.
void Player::fortifyLoop(Map* m, Deck* d)
{
    playerStrategy->fortifyLoop(playerName, &countries, &playerHand, &playerDice, &hasConquered, m, d);
}

bool Player::takeTurn(Map* m, Deck* d)
{
    // Used to check if the player owns all countries.
    bool victorious = false;

    // Refresh countries
    countries.clear();

    for (int i = 0; i < m->getContiSize(); i++)
    {
        for (int j = 0; j < m->getContinent(i)->getCntsSize(); j++)
        {
            if (m->getContinent(i)->getCountry(j)->getPlayerName() == playerName)
                addCountry(m->getContinent(i)->getCountry(j));
        }
    }

    if (countries.size() > 0)
    {
        cout << playerName << "'s turn begins." << endl;

        cout << endl << "Reinforcement phase: " << endl;
        reinforceLoop(m, d);
        cout << endl << "Attack phase: " << endl;
        victorious = attackLoop(m, d);

        // If the game is still not won after attacking, carry on with the turn.
        if (!victorious)
        {
            cout << endl << "Fortification phase: " << endl;
            fortifyLoop(m, d);

            if (hasConquered)
            {
                cout << endl << playerName << " has been granted a card for conquering a country." << endl;
                playerHand.addCard(d->draw());
            }

            hasConquered = false;

            cout << endl << playerName << "'s turn ends." << endl;
        }
    }

    return victorious;
}

// Finds a player by name in the players vector, returns a pointer to the player object.
Player* Player::findPlayer(string searchName)
{
    for (int i = 0; i < players.size(); i++)
    {
        if (players.at(i)->playerName == searchName)
            return players.at(i);
    }

    cout << "ERROR: No player named " << searchName << ". Returning null." << endl;
    return NULL;
}
