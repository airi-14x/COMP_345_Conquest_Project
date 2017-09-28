/*
 * part4_driver.cpp
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 1, part 4 demo
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "player.h"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) {

    // Set seed for RNG.
    srand(time(NULL));
    
    cout << "Setting up demo map..." << endl;
    
    // Setting up map and continents.
    Map demoMap{"World"};
    Map* pDemoMap = &demoMap;
    Continent continent1{"Continent 1"};\
    Continent* pContinent1 = &continent1;
    Continent continent2{"Continent 2"};\
    Continent* pContinent2 = &continent2;
    demoMap.addContinent(pContinent1);
    demoMap.addContinent(pContinent2);

    // Setting up countries for Continent 1
    Country country1a{"Country 1-A"};
    Country* pCountry1a = &country1a;
    pContinent1->addCountry(pCountry1a);
    Country country1b{"Country 1-B"};
    Country* pCountry1b = &country1b;
    pContinent1->addCountry(pCountry1b);
    
    // Setting up countries for Continent 2
    Country country2a{"Country 2-A"};
    Country* pCountry2a = &country2a;
    pContinent2->addCountry(pCountry2a);
    Country country2b{"Country 2-B"};
    Country* pCountry2b = &country2b;
    pContinent2->addCountry(pCountry2b);
    Country country2c{"Country 2-C"};
    Country* pCountry2c = &country2c;
    pContinent2->addCountry(pCountry2c);
    
    // Linking countries
    demoMap.link(country1a, country1b);
    demoMap.link(country1a, country2a);
    demoMap.link(country1a, country2b);
    demoMap.link(country2a, country2b);
    demoMap.link(country2a, country2c);
    
    // Create two players.
    cout << "Creating Player 1 and Player 2..." << endl;
    Player player1("Player 1");
    Player player2("Player 2");
    
    // Give each player 10 armies and 5 cards.
    cout << "Giving each player 10 armies and 5 cards." << endl;
    player1.addTroops(25);
    player1.getHand().addCard(Card());
    player1.getHand().addCard(Card());
    player1.getHand().addCard(Card());
    player1.getHand().addCard(Card());
    player1.getHand().addCard(Card());
    
    player2.addTroops(25);
    player2.getHand().addCard(Card());
    player2.getHand().addCard(Card());
    player2.getHand().addCard(Card());
    player2.getHand().addCard(Card());
    player2.getHand().addCard(Card());
            
    // Display armies and hands.
    cout << endl << "Player 1 now has " << player1.getTroops() << " armies." << endl;
    cout << "Player 1's hand object is now filled: " << endl;
    player1.getHand().listCards();
    cout << endl << "Player 2 now has " << player2.getTroops() << " armies." << endl;
    cout << "Player 2's hand object is now filled: " << endl;
    player2.getHand().listCards();
    system("PAUSE");
    
    // Distributing countries. Add armies for demo.
    cout << endl << "Giving all of Continent 1 to Player 1..." << endl;
    player1.addCountry(pCountry1a);
    player1.getCountries().at(0)->setArmyNum(1);
    player1.addCountry(pCountry1b);
    player1.getCountries().at(1)->setArmyNum(5);
    
    cout << endl << "Giving Country 2-A to Player 2 and Countries 2-B and 2-C to Player 1..." << endl;
    player2.addCountry(pCountry2a);
    player2.getCountries().at(0)->setArmyNum(5);
    player1.addCountry(pCountry2b);
    player1.getCountries().at(2)->setArmyNum(1);
    player1.addCountry(pCountry2c);
    player1.getCountries().at(3)->setArmyNum(1);
    
    cout << endl << "Listing countries: " << endl;
    cout << country1a.toString() << endl;
    cout << country1b.toString() << endl;
    cout << country2a.toString() << endl;
    cout << country2b.toString() << endl;
    cout << country2c.toString() << endl;
    system("PAUSE");
    
    // Showing reinforcement.
    cout << "=====================================" << endl;
    cout << "============Reinforcement============" << endl;
    cout << "=====================================" << endl;
    
    cout << endl << "Reinforcing Country 2-B with 10 armies for demo purposes." << endl;
    
    cout << "Before reinforcement: " << endl;
    cout << country2b.toString() << endl << endl;
    
    player1.reinforce(10, pCountry2b);
    
    cout << endl << "After reinforcement: " << endl;
    cout << country2b.toString() << endl;
    system("PAUSE");
    
    // Showing reinforcement error cases.
    cout << endl << "Reinforcing an enemy country: " << endl;
    player1.reinforce(1, pCountry2a);
    system("PAUSE");
    
    cout << endl << "Reinforcing with too many armies (Player 1 currently has 15 armies to deploy): " << endl;
    player1.reinforce(20, pCountry1a);
    system("PAUSE");
    
    cout << endl << "Reinforcing with negative armies: " << endl;
    player1.reinforce(-5, pCountry1a);
    system("PAUSE");
    
    cout << endl << "Reinforcing with no army: " << endl;
    player1.reinforce(0, pCountry1a);
    system("PAUSE");
    
    // Showing fortify.
    cout << "====================================" << endl;
    cout << "===============Fortify==============" << endl;
    cout << "====================================" << endl;
    
    cout << "Attempting to fortify with only 1 troop (1-A to 2-B): " << endl;
    player1.fortify(pDemoMap, pCountry1a, pCountry2b);
    system("PAUSE");
    
    cout << "Attempting to fortify unreachable country (1-B to 2-C): " << endl;
    player1.fortify(pDemoMap, pCountry1b, pCountry2c);
    system("PAUSE");
    
    cout << "Fortifying successfully (1-B to 2-B): " << endl;
    player1.fortify(pDemoMap, pCountry1b, pCountry2b);
    cout << endl << country2b.toString() << endl;
    system("PAUSE");
    
    // Showing attack.
    cout << "=====================================" << endl;
    cout << "================Attack===============" << endl;
    cout << "=====================================" << endl;
    
    cout << "Attempting to attack without enough armies: " << endl;
    player1.attack(pDemoMap, pCountry1a, pCountry2a);
    system("PAUSE");
    
    char keepAttacking = 'y';
    
    while (keepAttacking == 'y' && pCountry2a->getPlayerName() != "Player 1" && pCountry2b->getArmyNum() > 1)
    {
        cout << "Attacking 2-A from 2-B" << endl;
        player1.attack(pDemoMap, pCountry2b, pCountry2a);
        
        cout << "Keep attacking? ";
        cin >> keepAttacking;
    }
    
    cout << endl << country2a.toString() << endl;
    cout << endl << country2b.toString() << endl;
    
    return 0;
}

