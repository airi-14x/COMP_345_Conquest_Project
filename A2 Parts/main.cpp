#include <iostream>
#include <limits>
#include "GameLoop.h"
#include "player.h"
#include "MapParser.h"
#include "Map.h"
using namespace std;

void initializePlayers(Map* gamemap, Player p);

int main()
{
    MapParser mp;
    mp.readFile("maps/World.map");

    vector<Player> p;
    Player p1("Fred");
    Player p2("Bob");
    Player p3("Joe");
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);

    Map* gamemap = mp.getMap();

    cout << "Starting 3 player game. Player 1 (" << p1.getName() << ") will win:" << endl << endl;
    initializePlayers(gamemap, p1);
    GameLoop g1(gamemap, p, p.size());
    g1.start();

    cout << endl << "Starting 3 player game. Player 2 (" << p2.getName() << ") will win:" << endl << endl;
    initializePlayers(gamemap, p2);
    GameLoop g2(gamemap, p, p.size());
    g2.start();

    cout << endl << "Starting 3 player game. Player 3 (" << p3.getName() << ") will win:" << endl << endl;
    initializePlayers(gamemap, p3);
    GameLoop g3(gamemap, p, p.size());
    g3.start();

    cout << "complete";

    return 0;
}

void initializePlayers(Map* gamemap, Player p){
    int numOfConti = gamemap->getContiSize();

    for(int i = 0; i < numOfConti; i++){
        Continent* conti = gamemap->getContinent(i);
        int numOfCountries = conti->getCntsSize();
        for(int j = 0; j < numOfCountries; j++){
            Country* country = conti->getCountry(j);
            country->setPlayerName(p.getName());
        }
    }
}
