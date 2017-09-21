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

using std::string;
using std::pair<>;


class Map {
private:
    vector<Continent> conti;//vector of continents, each continent will have
                            //a vector of countries named cnts
    vector<pair<Country, Country>>;//vector of country pairs for adjacency?
    void link(Country m, Country n); //two args are stored into the pair vector
    bool areAdjacent(Country m, Country n); //checks pairing vector for relationship
                                            //std::find(vector.begin(), vector.end(), item) != vector.end()
    bool validate();
public:
    Map();
    void addContinent(Continent name);
    Continent getContinent(string contname);
    
    void printContinents();
    void printAdjacents();
};


#endif /* MAP_H */

