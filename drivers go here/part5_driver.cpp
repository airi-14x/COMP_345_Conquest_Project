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
    Country country1c{"Country 1-C"};
    Country* pCountry1c = &country1c;
    pContinent1->addCountry(pCountry1c);
    Country country1d{"Country 1-D"};
    Country* pCountry1d = &country1d;
    pContinent1->addCountry(pCountry1d);
    Country country1e{"Country 1-E"};
    Country* pCountry1e = &country1e;
    pContinent1->addCountry(pCountry1e);
    Country country1f{"Country 1-F"};
    Country* pCountry1f = &country1f;
    pContinent1->addCountry(pCountry1f);
    
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
    Country country2d{"Country 2-D"};
    Country* pCountry2d = &country2d;
    pContinent2->addCountry(pCountry2d);
    Country country2e{"Country 2-E"};
    Country* pCountry2e = &country2e;
    pContinent2->addCountry(pCountry2e);
    Country country2f{"Country 2-F"};
    Country* pCountry2f = &country2f;
    pContinent2->addCountry(pCountry2f);
    Country country2g{"Country 2-G"};
    Country* pCountry2g = &country2g;
    pContinent2->addCountry(pCountry2g);
    Country country2h{"Country 2-H"};
    Country* pCountry2h = &country2h;
    pContinent2->addCountry(pCountry2h);
    Country country2i{"Country 2-I"};
    Country* pCountry2i = &country2i;
    pContinent2->addCountry(pCountry2i);
    
    // Linking countries
    demoMap.link(country1a, country1b);
    demoMap.link(country1b, country1c);
    demoMap.link(country1c, country1d);
    demoMap.link(country1d, country1e);
    demoMap.link(country1e, country1f);
    demoMap.link(country1a, country2a);
    demoMap.link(country1a, country2b);
    demoMap.link(country2a, country2b);
    demoMap.link(country2a, country2c);
    demoMap.link(country2a, country2d);
    demoMap.link(country2a, country2e);
    demoMap.link(country2a, country2f);
    demoMap.link(country2a, country2g);
    demoMap.link(country2a, country2h);
    demoMap.link(country2a, country2i);
    
    // Create a deck based on the map.
    cout << "Creating a new deck using the demo map containing " << demoMap.getMapSize() << " countries." << endl;
    Deck demoDeck(pDemoMap);
    demoDeck.listCards();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    
    // Create hand.
    cout << "Creating a hand object..." << endl;
    Hand demoHand;
    demoHand.listCards();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    
    // Draw all cards.
    cout << "Drawing all cards from the deck..." << endl;
    while (demoDeck.getSize() != 0)
    {
        demoHand.addCard(demoDeck.draw());
    }
    demoHand.listCards();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    
    // Exchange demo.
    char c = 'y';
    
    while (c == 'y')
    {
        cout << endl << "Exchanging cards..." << endl;
        demoHand.exchange();
        
        cout << endl;
        demoHand.listCards();
        cout << endl;
        
        if (demoHand.getSize() != 0)
        {
            cout << "Would you like to continue exchanging cards? ";
            cin >> c;
        }
        else
            c = 'n';
    }
    
    return 0;
}

