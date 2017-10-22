/*
 * a2_p4_driver.cpp
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#include <iostream>
#include "player.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Player p = Player("Alexia");

    Map m = Map();

    Continent c1 = Continent("c1", 3);
    Country c1c1 = Country("c1c1", "Alexia", 1);
    Continent c2 = Continent("c2", 5);
    Country c2c1 = Country("c2c1", "Alexia", 1);
    Country c2c2 = Country("c2c2", "Not Alexia", 1);
    Country c2c3 = Country("c2c3", "Alexia", 1);
    Country c2c4 = Country("c2c4", "Alexia", 1);
    Country c2c5 = Country("c2c5", "Alexia", 1);
    Country c2c6 = Country("c2c6", "Alexia", 1);

    c1.addCountry(&c1c1);
    c2.addCountry(&c2c1);
    c2.addCountry(&c2c2);
    c2.addCountry(&c2c3);
    c2.addCountry(&c2c4);
    c2.addCountry(&c2c5);
    c2.addCountry(&c2c6);

    m.addContinent(&c1);
    m.addContinent(&c2);

    Deck d = Deck(&m);

    p.getHand().addCard(d.draw());
    p.getHand().addCard(d.draw());
    p.getHand().addCard(d.draw());
    p.getHand().addCard(d.draw());
    p.getHand().addCard(d.draw());
    p.getHand().addCard(d.draw());

    p.addCountry(&c1c1);
    p.addCountry(&c2c1);
    p.addCountry(&c2c3);
    p.addCountry(&c2c4);
    p.addCountry(&c2c5);
    p.addCountry(&c2c6);

    cout << "==================================" << endl;
    cout << "===========Part 4 driver==========" << endl;
    cout << "==================================" << endl;
    cout << "Demo map: " << endl;

    for(int i = 0; i < m.getContiSize(); i++)
    {
        cout << "continent " << m.getContinent(i)->getName() << " control value: " << m.getContinent(i)->getControl() << endl;
        for (int j = 0; j < m.getContinent(i)->getCntsSize(); j++)
        {
            cout << "country " << m.getContinent(i)->getCountry(j).getName() << " owned by " << m.getContinent(i)->getCountry(j).getPlayerName() << endl;
        }
    }

    cout << endl;

    p.beginTurn(&m);
}
