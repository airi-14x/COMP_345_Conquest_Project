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
using std::endl;
using std::cout;

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

int Map::getContiSize() {
    return conti.size();
}

//flags reachable countries from root. Uses a recursive depth-first search

void Map::flagConnections(Country* root) {

    root->setVisited(true);

    for (int i = 0; i < conti.size(); i++) {
        for (int j = 0; j < conti[i]->cnts.size(); j++) {//continent iteration
            if (areAdjacent(*root, *conti[i]->cnts[j])//country iteration within continent
                    &&(conti[i]->cnts[j]->getVisited() == false)) {
                cout << root->getName() << " to " << conti[i]->cnts[j]->getName() << endl;
                flagConnections(conti[i]->cnts[j]);
            }
        }
    }
}
//flags reachable allied countries from root. Uses a recursive depth-first search

void Map::flagAlliedConnections(Country* root) {

    root->setVisited(true);

    for (int i = 0; i < conti.size(); i++) {
        for (int j = 0; j < conti[i]->cnts.size(); j++) {
            if (areAdjacent(*root, *conti[i]->cnts[j])
                    && root->getPlayerName() == conti[i]->cnts[j]->getPlayerName()
                    &&(conti[i]->cnts[j]->getVisited() == false)) {
                flagAlliedConnections(conti[i]->cnts[j]);
            }
        }
    }
}

//flag connection for continent

void Map::flagContinent(Country* root, Continent* cont) {
    root->setVisited(true);
    for (int i = 0; i < cont->cnts.size(); i++) {
        if (areAdjacent(*root, *cont->cnts[i]) //countries
                && cont->cnts[i]->getVisited() == false) {
            cout << root->getName() << " to " << cont->cnts[i]->getName() << endl;

            flagContinent(cont->cnts[i], cont);
        }
    }
}

bool Map::valiCont(Continent* cont) {
    flagContinent(cont->cnts[0], cont);

    for (int i = 0; i < cont->cnts.size(); i++) {
        if (cont->cnts[i]->getVisited() == false) {
            cout << cont->cnts[i]->getName() << " in " << cont->getName() << " cannot be reached\n" << endl; //that's a 0
            resetFlags();

            return false;
        }
    }

    cout << cont->getName() << " is connected\n" << endl; //this is a 1
    resetFlags();
    return true;
}

//sets everything to not visited

void Map::resetFlags() {
    for (int i = 0; i < conti.size(); i++) {
        for (int j = 0; j < conti[i]->cnts.size(); j++) {
            conti[i]->cnts[j]->setVisited(false);
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
        if ((edges[i].first->getName() == m.getName() && edges[i].second->getName() == n.getName())
                || (edges[i].first->getName() == n.getName() && edges[i].second->getName() == m.getName())) {
            return true;
        }
    }
    return false;

}
//checks if all countries are reachable from root

bool Map::validate(Country* root) {
    if (edges.empty()) {
        cout << "Nothing connected" << endl;
        return false;
    }
    if (!checkDuplicateCnts()) {
        return false;
    }
    flagConnections(root); //flags reachable ones


    for (int i = 0; i < conti.size(); i++) {
        for (int j = 0; j < conti[i]->cnts.size(); j++) {
            if (conti[i]->cnts[j]->getVisited() == false) {
                cout << conti[i]->cnts[j]->getName() << " cannot be reached" << endl; //prints out an unreachable one
                resetFlags();

                return false;
            }
        }
    }

    cout << "Map is connected\n" << endl; //this is a 1
    resetFlags();



    return true;
}
//creates a pair of countries that will be used for validation

void Map::link(Country* m, Country* n) {
    pair < Country*, Country*> k;
    k = std::make_pair(m, n);
    edges.push_back(k);
}

void Map::addContinent(Continent* c) {
    for (int i = 0; i < conti.size(); i++) {
        if (c->getName() == conti[i]->getName()) {
            cout << "Continent of same name(" << c->getName() << ") exists in this map, please rename." << endl;
            return;
        }
    }
    conti.push_back(c);
}

string Map::getName() {
    return name;
}

string Map::toString() {
    return "Name: " + name + "\n";
}

pair<Country*, Country*> Map::getEdge(int index) {
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
//... checks if same country name is in different continents

bool Map::checkDuplicateCnts() {
    if (conti.size() != 1) {
        for (int i = 0; i < (conti.size()); i++) { //compare(x,y) , this loop defines the continent for x
            for (int j = (i + 1); j < conti.size(); j++) { //continent for y
                for (int l = 0; l < conti[i]->cnts.size(); l++) {//country iteration of x
                    for (int k = 0; k < conti[j]->cnts.size(); k++) {//country iteration of y
                        if ((conti[i]->cnts[l]->getName() == conti[j]->cnts[k]->getName())) {
                            cout << "Duplicate of " << conti[i]->cnts[l]->getName()
                                    << " found in " << conti[i]->getName()
                                    << " and " << conti[j]->getName() << "\n" << endl;
                            return false;

                        }
                    }
                }

            }
        }
    }

    cout << "No country dupes!\n" << endl;
    return true;
}
//shows all connections

string Map::printEdges() {
    string temp = "";
    for (int i = 0; i < edges.size(); i++) {
        temp += "[" + edges[i].first->getName() + ", " + edges[i].second->getName() + "]\n";
    }

    return temp;
}

// Checks if a target country is connected to an origin country via allied countries.

bool Map::checkAlliedReach(Country* origin, Country* target) {
    // Reset flags to avoid conflicting output.
    resetFlags();

    // Flag all connected countries owned by origin's owner.
    flagAlliedConnections(origin);

    // Determine if the target country is flagged.
    bool targetReachable = target->getVisited();

    // Wipe flags to avoid conflict in other functions.
    resetFlags();

    return targetReachable;
}

// Finds the parametized country in a Map object, going through every continent.
Country* Map::findCountry(string countryName)
{
    // Go through the map looking for the parametized country.
    for (int i = 0; i < conti.size(); i++)
    {
        for (int j = 0; j < conti[i]->getCntsSize(); j++)
        {
            // Compare names of countries to find a match.
            if (countryName == conti[i]->getCountry(j)->getName())
            {
                return conti[i]->getCountry(j);
            }
        }
    }

    return nullptr;
}

/*=============================================================
 CONTINENT
 ==============================================================
 */

Continent::Continent() {
    name = "";
    cnts = {};

}

Continent::Continent(string nem, int ctrl) {
    name = nem;
    control = ctrl;
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
    for (int i = 0; i < cnts.size(); i++) {
        if (c->getName() == cnts[i]->getName()) {
            cout << "Country of same name(" << c->getName() << ") exists in this continent, please rename." << endl;
            return;
        }
    }
    cnts.push_back(c);
}

int Continent::getControl()
{
    return control;
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
            temp += getCountry(i)->getName() + "\n";
        }
        return temp;
    }
}
//returns country to be searched by name

Country* Continent::getCountry(string name) {

    for (int i = 0; i < cnts.size(); i++) {
        if (cnts[i]->getName() == (name))
            return cnts[i];
    }
}
//returns country from index

Country* Continent::getCountry(int index) {
    return cnts[index];
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
    hasBeenAssigned = false;

}

Country::Country(string nam) {
    name = nam;
    armynum = 0;
    playername = "";
    hasBeenAssigned = false;
    visited = false;
}

Country::Country(string nam, string pname) {
    playername = pname;
    name = nam;
    armynum = 0;
    hasBeenAssigned = false;
    visited = false;
}

Country::Country(string nam, string pname, int army) {
    playername = pname;
    name = nam;
    armynum = army;
    hasBeenAssigned = false;
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
    setHasBeenAssigned();
}

string Country::getPlayerName() {
    return playername;
}

void Country::setVisited(bool a) {
    visited = a;
}

void Country::setHasBeenAssigned()
{
    hasBeenAssigned = true;
}

bool Country::getHasBeenAssigned()
{
   return hasBeenAssigned;
}

bool Country::getVisited() {
    return visited;
}
