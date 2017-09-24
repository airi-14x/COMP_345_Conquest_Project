/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.h
 * Author: User
 *
 * Created on September 19, 2017, 8:27 PM
 */

#ifndef MAP_H
#define MAP_H

#include <utility>
#include <vector>
#include "Continent.h"
#include "Country.h"
using std::string;
//using namespace std; //because i cant use std vector
using std::vector;
using std::pair;

class Map {
private:

    string name;

    vector<Continent> conti; //vector of continents, each continent will have
    //a vector of countries named cnts
    bool areAdjacent(Country m, Country n); //checks pairing vector for relationship
    //std::find(vector.begin(), vector.end(), item) != vector.end()
    vector<pair<Country, Country >> edges; //vector of country pairs for adjacency?

public:
    bool validate();

    void flagConnections(Country root);
    pair<Country, Country> getEdge(int index);

    void link(Country m, Country n); //two args are stored into the pair vector

    Map();
    Map(string n);
    void addContinent(Continent c);
    Continent getContinent(string contname);

    string getName();
    string toString();
    string printContinents();
    string printEdges();

};


#endif /* MAP_H */

