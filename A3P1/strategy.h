#ifndef STRATEGY_H_INCLUDED
#define STRATEGY_H_INCLUDED

#include "Map.h"
#include "Dice.h"
#include "hand.h"
#include "deck.h"

class Player;

// Strategy superclass containing implementations for reinforcing, attacking,
// and fortifying, as well as declarations for derived functions.
class Strategy
{
public:
    virtual void reinforceLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*) = 0;
    virtual void attackLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*) = 0;
    virtual void fortifyLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*) = 0;
    virtual bool isHuman() = 0;

protected:
    void grantArmies();
    virtual void exchangeLoop() = 0;
    int determineDiceCount(Country*);
    virtual void reinforce(int, Country*);
    virtual void attack(Country*, int, Country*, int);
    virtual void fortify(int, Country*, Country*);

    // Pointers to the calling player's member data
    vector<Country*>* playerCountries;
    Hand* playerHand;
    Dice* playerDice;
    bool* hasConquered;

    string playerName;
    int armies;
    Map* gameMap;
    Deck* gameDeck;
};

// Human concrete strategy containing implementations for reinforcement,
// attack, and fortification loops as well as determining attack and defense dice counts
// with user input.
class HumanStrategy : public Strategy
{
public:
    void reinforceLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
    void attackLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
    void fortifyLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
    bool isHuman();
protected:
    void exchangeLoop();
};


// Computer-controlled derived strategy containing implementation for,
// determining attack and defense dice counts automatically.
class ComputerStrategy : public Strategy
{
public:
    bool isHuman();
protected:
    void exchangeLoop();
};

// Aggressive concrete strategy containing implementations for reinforcement,
// attack, and fortification loops.
class AggressiveStrategy : public ComputerStrategy
{
public:
    void reinforceLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
    void attackLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
    void fortifyLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
};

// Benevolent concrete strategy containing implementations for reinforcement,
// attack, and fortification loops.
class BenevolentStrategy : public ComputerStrategy
{
public:
    void reinforceLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
    void attackLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
    void fortifyLoop(string,vector<Country*>*, Hand*, Dice*, bool*, Map*, Deck*);
};

#endif // STRATEGY_H_INCLUDED
