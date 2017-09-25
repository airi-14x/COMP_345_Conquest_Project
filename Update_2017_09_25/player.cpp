/*
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1
 */

#include "player.h"
#include "Dice.h"

// Creates a new player with no allocated troops.
Player::Player()
{
    playerTroops = 0;
    setDice();
}

void Player::setDice()
{
    Dice d1; // Create Dice object with default constructor on heap.
}
Dice Player::getDice()
{
    return d1;
}

// Returns the player's hand object.
/*
Hand Player::getHand()
{
    return playerHand;
}

// Adds cards to the player's hand object.
void Player::addCard(Card newCard)
{
    playerHand.addCard(newCard);
}
*/
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