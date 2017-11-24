/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Map.h
 * Author: Earl Steven Aromin 40004997
 *
 * Created on September 19, 2017, 8:27 PM
 */

#ifndef MAP_H
#define MAP_H

#include <utility>
#include <map>
#include <string>
#include <vector>
#include "Subject.h"
#include "Observer.h"
using namespace std;

class Player;
class Continent;
class Country;

class ViewState
{
    public:
        ViewState(vector<string> o, bool oc, map<string, int> p , int n);
        virtual ~ViewState();
        map<string, int> players;
        int numOfCountries;
        vector<string> owners;
        bool ownershipChange;
};


class Map  : public Subject {
private:

    string name;

    vector<Continent*> conti; //vector of continents, each continent will have
    //a vector of countries named cnts
    vector<pair<Country*, Country* > > edges; //vector of country pairs for adjacency?

    void resetFlags();
    void flagConnections(Country* root);
    void flagAlliedConnections(Country* root);
    void flagContinent(Country* root, Continent* cont);
    bool checkDuplicateCnts();


public:
    //checks if two continents have the same country
    bool validate(Country* root);

    bool valiCont(Continent* cont);
    bool areAdjacent(Country m, Country n); //checks pairing vector for relationship
    bool areAdjacent(Country* m, Country* n); //checks pairing vector for relationship

    int getContiSize();
    pair<Country*, Country*> getEdge(int index);

    void link(Country* m, Country* n); //two args are stored into the pair vector

    Map();
    Map(string n);
    void addContinent(Continent* c);
    Continent* getContinent(string contname);
    Continent* getContinent(int index);
    int getMapSize();

    string getName();
    string toString();
    string printContinents();
    string printEdges();

    bool checkAlliedReach(Country* origin, Country* target);
    Country* findCountry(string countryName); // Finds the parametized country in a Map object, going through every continent.

    ViewState* getState();
    void exchangeCountry(Country* country, string playerName);
};

class Continent {
private:
    string name;
    int control; // The continent's control value, used by Player.
public:
    string owner;
    vector<Country*> cnts;

    int getCntsSize();
    Continent();
    Continent(string nem, int ctrl);

    string toString();
    string getName();

    int getNumOfContients();
    int getControl(); // Returns the continent's control value, used by Player.

    void addCountry(Country* c);
    Country* getCountry(string name);
    Country* getCountry(int index);
    string nameCountries();
    void setName(string n);
};

class Country {
private:
    bool visited;
    bool hasBeenAssigned; // Has the country beeen Assigned to someone? //
    string playername;
    string name;
    bool human;

    int armynum;

public:
    void setVisited(bool a);
    bool getVisited();
    bool getHasBeenAssigned();
    void setHasBeenAssigned();
    Country();
    Country(string nam);
    Country(string nam, string pname);
    Country(string nam, string pname, int army);

    string toString();
    string getName();
    int getArmyNum();

    void setArmyNum(int a);
    void setName(string a);
    void setPlayerName(string a);
    string getPlayerName();

    void setHuman(bool h);
    bool isHuman();

};


#endif /* MAP_H */
