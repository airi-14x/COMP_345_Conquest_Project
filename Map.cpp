/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//#include "Map.h"
#include <vector>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
using std::string;
//using namespace std; //because i cant use std vector
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

int Map::getContiSize()
{
    return conti.size();
}
//!!not done yet
void Map::flagConnections(Country root)
{
    root.setVisited(true);
    for(int i = 0; i< conti.size(); i++)
    {
        for(int j = 0 ; j < conti[i].cnts.size(); j++)
        {
            if(conti[i].cnts[j].getVisited()==false)
            {
                flagConnections(conti[i].cnts[j]);
            }
        }
    }
}
bool Map::areAdjacent(Country m, Country n)
{
    
}
bool Map::validate()
{
    for(int i = 0; i< conti.size(); i++)
    {
        for(int j = 0 ; j < conti[i].cnts.size(); j++)
        {
            if(conti[i].cnts[j].getVisited()==false)
            {
               return false;
            }
        }
    }
    return true;
}

void Map::link(Country m, Country n) {
    pair < Country, Country> k;
    k = std::make_pair(m, n);
    edges.push_back(k);
}

void Map::addContinent(Continent c) {
    conti.push_back(c);
}

string Map::getName() {
    return name;
}

string Map::toString() {
    return "Name: " + name + "\n";
}

pair<Country,Country> Map::getEdge(int index) {
    return edges[index];
}

string Map::printContinents() {
    string temp;
    if (conti.empty()) {
        return (name + " is an empty Map");
    } else {
        for (int i = 0; i < conti.size(); i++) {
            temp += conti[i].getName() + "\n";
        }
        return temp;
    }
}

Continent Map::getContinent(string contname) {

    for (int i = 0; i < conti.size(); i++) {
        if (conti[i].getName() == (contname))

            return conti[i];
    }
}

string Map::printEdges()
{
    string temp = "";
    for(int i = 0; i < edges.size(); i++)
    {
        temp+="[" + edges[i].first.getName() + ", " + edges[i].second.getName() + "]" ;
    }
        
    return temp;
}