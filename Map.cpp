/*
 *  * Author: Earl Steven Aromin 40004997
 */


#include <vector>
#include <iostream>
#include <iterator>
#include "Map.h"
using std::string;
using std::vector;
using std::pair;

Map::Map() {
    conti = {};
    edges = {};
}

Map::Map(string n) {
    name = n;
    conti = {};
    edges = {};

}
//number of countries. Iterates through continents and gets country nums

int Map::getMapSize() {
    int mapSize = 0;

    for (int continent = 0; continent < conti.size(); continent++) {
        mapSize += conti.at(continent)->getCntsSize();
    }

    return mapSize;
}
//flags reachable countries from root. Uses a recursive depth-first search

void Map::flagConnections(Country* root) {

    root->setVisited(true);

    for (int i = 0; i < conti.size(); i++) {
        for (int j = 0; j < conti[i]->cnts.size(); j++) {
             if (areAdjacent(*root, *conti[i]->cnts[j])
                    &&(conti[i]->cnts[j]->getVisited() == false)) {
                flagConnections(conti[i]->cnts[j]);
            }
        }
    }
}

/**
 * 
 * @param m first country
 * @param n second country
 * @return if the two are a pair in the edges vector, regardless of first, it returns true
 */
bool Map::areAdjacent(Country m, Country n) {
    for (int i = 0; i < edges.size(); i++) {
        if ((edges[i].first.getName() == m.getName() && edges[i].second.getName() == n.getName())
                || (edges[i].first.getName() == n.getName() && edges[i].second.getName() == m.getName())) {
            return true;
        }
    }
    return false;

}
//checks if all maps are reachable

bool Map::validate() {

    flagConnections(conti[0]->cnts[0]); //flags reachable ones

    for (int i = 0; i < conti.size(); i++) {
        for (int j = 0; j < conti[i]->cnts.size(); j++) {
            if (conti[i]->cnts[j]->getVisited() == false) {
                cout << conti[i]->cnts[j]->getName() << " cannot be reached" << endl; //that's a 0
                return false;
            }
        }
    }
    cout << "Map is connected" << endl; //this is a 1

    return true;
}
//creates a pair of countries that will be used for validation

void Map::link(Country m, Country n) {
    pair < Country, Country> k;
    k = std::make_pair(m, n);
    edges.push_back(k);
}

void Map::addContinent(Continent* c) {
    conti.push_back(c);
}

string Map::getName() {
    return name;
}

string Map::toString() {
    return "Name: " + name + "\n";
}

pair<Country, Country> Map::getEdge(int index) {
    return edges[index];
}
//just prints all continent 

string Map::printContinents() {
    string temp;
    if (conti.empty()) {
        return (name + " is an empty Map");
    } else {
        for (int i = 0; i < conti.size(); i++) {
            temp += conti[i]->getName() + "\n";
        }
        return temp;
    }
}
//returns continent from index

Continent* Map::getContinent(int index) {
    return conti[index];
}

//returns continent from  name

Continent* Map::getContinent(string contname) {

    for (int i = 0; i < conti.size(); i++) {
        if (conti[i]->getName() == (contname))

            return conti[i];
    }
}

//shows all connections

string Map::printEdges() {
    string temp = "";
    for (int i = 0; i < edges.size(); i++) {
        temp += "[" + edges[i].first.getName() + ", " + edges[i].second.getName() + "]\n";
    }

    return temp;
}

/*=============================================================
 CONTINENT
 ==============================================================
 */

Continent::Continent() {
    name = "";
    cnts = {};

}

Continent::Continent(string nem) {
    name = nem;
    cnts = {};

}

void Continent::setName(string n) {
    name = n;
}

string Continent::getName() {
    return name;
}

string Continent::toString() {
    return "Name: " + name + "\n";
}
//takes a pointer of a country

void Continent::addCountry(Country* c) {
    cnts.push_back(c);
}

int Continent::getCntsSize() {
    return cnts.size();
}

//just returns a string of the names of countries within the continent

string Continent::nameCountries() {
    string temp;
    if (cnts.empty()) {
        return (name + " is an empty continent");
    } else {
        for (int i = 0; i < cnts.size(); i++) {
            temp += getCountry(i).getName() + "\n";
        }
        return temp;
    }
}
//returns country to be searched by name

Country Continent::getCountry(string name) {

    for (int i = 0; i < cnts.size(); i++) {
        if (cnts[i]->getName() == (name))

            return *cnts[i];
    }
}
//returns country from index

Country& Continent::getCountry(int index) {
    return *cnts[index];
}


/*================================================
 * COUNTRY
 * ==============================================
 */

/**
 * this is just a container for the information per country
 */
Country::Country() {
    name = "";
    playername = "";
    armynum = 0;
    visited = false;

}

Country::Country(string nam) {
    name = nam;
    armynum = 0;
    playername = "";

    visited = false;
}

Country::Country(string nam, string pname) {
    playername = pname;
    name = nam;
    armynum = 0;

    visited = false;
}

Country::Country(string nam, string pname, int army) {
    playername = pname;
    name = nam;
    armynum = army;

    visited = false;
}

string Country::toString() {

    return "Country name: " + name + "\nRuler: " + playername + "\nArmy Size: "
            + std::to_string(armynum);
}

string Country::getName() {
    return name;
}

int Country::getArmyNum() {
    return armynum;
}

void Country::setArmyNum(int a) {
    armynum = a;
}

void Country::setName(string a) {
    name = a;
}

void Country::setPlayerName(string a) {
    playername = a;
}

void Country::setVisited(bool a) {
    visited = a;
}

bool Country::getVisited() {
    return visited;
}