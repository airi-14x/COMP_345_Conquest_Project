#include <iostream>
#include <ctime>
#include "player.h"
#include "Game.h"
#include "Map.h"
#include "MapParser.h"
#include "view.h"
using namespace std;

int main()
{

    MapParser mp;
    mp.readFile("World.map");

    vector<Player> p;
    Player p1("Fred", new CheaterStrategy());
    Player p2("Bob", new AggressiveStrategy());
    Player p3("Joe", new BenevolentStrategy());
    Player p4("John", new BenevolentStrategy());
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);

    Map* m = mp.getMap();

    int counter = 0;
    int numOfConti = m->getContiSize();
    for(int i = 0; i < numOfConti; i++){
        Continent* conti = m->getContinent(i);
        int numOfCountries = conti->getCntsSize();
        for(int j = 0; j < numOfCountries; j++){
            counter++;
                Country* country = conti->getCountry(j);
            if(counter <= 10) {
                p1.addCountry(country);
                country->setArmyNum(1);
            } else if (counter <= 20) {
                p2.addCountry(country);
                country->setArmyNum(1);
            } else if (counter <= 30) {
                p3.addCountry(country);
                country->setArmyNum(1);
            } else {
                p4.addCountry(country);
                country->setArmyNum(1);
            }
        }
    }

    view v(m);
    cout << "Percentage of countries owned by each player" << endl;
    m->Notify();

    Game g(m, p);
    g.start();
}
