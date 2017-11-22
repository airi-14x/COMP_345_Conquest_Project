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
    Player p2("Bob", new BenevolentStrategy());
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
    cout << "Percentage of countries owned by each player" << endl;
    m->Notify();

    Game g(m, p);
    g.start();
}
