#include <iostream>
#include <stdlib.h>
#include "view.h"
#include "MapParser.h"
#include "player.h"
#include "Map.h"
using namespace std;

void giveCountryToPlayer(vector<Player>* p, Map* m) {
    int country = (rand() % m->getMapSize());
    Player player = p->at(rand() % p->size());

    int counter = 0;
    int numOfConti = m->getContiSize();
    for(int i = 0; i < numOfConti; i++){
        Continent* conti = m->getContinent(i);
        int numOfCountries = conti->getCntsSize();
        for(int j = 0; j < numOfCountries; j++){
            counter++;
            if (counter == country) {
                Country* country = conti->getCountry(j);
                if (player.getName() == country->getPlayerName()) // if the player already owns the country
                    return giveCountryToPlayer(p, m); // try again
                cout << endl;
                cout << "Giving " << country->getName() << " from " << country->getPlayerName() << " to " << player.getName() << endl;
                cout << "-----------------------------------------------------------------" << endl;
                m->exchangeCountry(country, player.getName());
            }
        }
    }
}

int main()
{
    MapParser mp;
    mp.readFile("World.map");

    vector<Player> p;
    Player p1("Fred");
    Player p2("Bob");
    Player p3("Joe");
    Player p4("John");
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
            if(counter <= 10) {
                conti->getCountry(j)->setPlayerName(p1.getName());
            } else if (counter <= 20) {
                conti->getCountry(j)->setPlayerName(p2.getName());
            } else if (counter <= 30) {
                conti->getCountry(j)->setPlayerName(p3.getName());
            } else {
                conti->getCountry(j)->setPlayerName(p4.getName());
            }
        }
    }

    view v(m);
    cout << "Initial Setup" << endl;
    m->Notify();

    for(int i = 0; i < 10; i++){
        giveCountryToPlayer(&p, m);
    }
    return 0;
}
