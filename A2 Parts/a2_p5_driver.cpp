/*
 * a2_p5_driver.cpp
 * Author: Alexia Soucy, 40014822
 * Course: COMP 345, section D
 * Assignment: 2
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "player.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    srand(time(NULL));

    Player p1 = Player("P1");
    Player p2 = Player("P2");

    Map m = Map();

    Continent c1 = Continent("c1", 3);
    Country c1c1 = Country("c1c1", "P1", 1);
    Country c1c2 = Country("c1c2", "P1", 1);
    Country c1c3 = Country("c1c3", "P1", 1);
    Continent c2 = Continent("c2", 5);
    Country c2c1 = Country("c2c1", "P2", 5);
    Country c2c2 = Country("c2c2", "P2", 5);
    Country c2c3 = Country("c2c3", "P1", 10);
    Country c2c4 = Country("c2c4", "P2", 5);

    m.link(&c1c1, &c1c2);
    m.link(&c1c2, &c1c3);
    m.link(&c1c2, &c2c1);
    m.link(&c1c2, &c2c2);
    m.link(&c2c1, &c2c2);
    m.link(&c2c2, &c2c3);
    m.link(&c2c3, &c2c4);

    c1.addCountry(&c1c1);
    c1.addCountry(&c1c2);
    c1.addCountry(&c1c3);
    c2.addCountry(&c2c1);
    c2.addCountry(&c2c2);
    c2.addCountry(&c2c3);
    c2.addCountry(&c2c4);

    m.addContinent(&c1);
    m.addContinent(&c2);

    p1.addCountry(&c1c1);
    p1.addCountry(&c1c2);
    p1.addCountry(&c1c3);
    p1.addCountry(&c2c3);
    p2.addCountry(&c2c1);
    p2.addCountry(&c2c2);
    p2.addCountry(&c2c4);



    cout << "==================================" << endl;
    cout << "===========Part 5 driver==========" << endl;
    cout << "==================================" << endl;
    cout << "Map state:" << endl;

    for(int i = 0; i < m.getContiSize(); i++)
    {
        cout << "continent " << m.getContinent(i)->getName() << " control value: " << m.getContinent(i)->getControl() << endl;
        for (int j = 0; j < m.getContinent(i)->getCntsSize(); j++)
        {
            cout << "country " << m.getContinent(i)->getCountry(j).getName() << " owned by " << m.getContinent(i)->getCountry(j).getPlayerName()
            << " contains " << m.getContinent(i)->getCountry(j).getArmyNum() << " armies." << endl;
        }
    }

    cout << endl;

    p1.attackPhase(&m);

    cout << "Map state:" << endl;

    for(int i = 0; i < m.getContiSize(); i++)
    {
        cout << "continent " << m.getContinent(i)->getName() << " control value: " << m.getContinent(i)->getControl() << endl;
        for (int j = 0; j < m.getContinent(i)->getCntsSize(); j++)
        {
            cout << "country " << m.getContinent(i)->getCountry(j).getName() << " owned by " << m.getContinent(i)->getCountry(j).getPlayerName()
            << " contains " << m.getContinent(i)->getCountry(j).getArmyNum() << " armies." << endl;
        }
    }
}
