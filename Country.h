/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Country.h
 * Author: User
 *
 * Created on September 19, 2017, 8:05 PM
 */

#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
//using std::string;
using namespace std;

class Country {
private:
    string playername; // placeholder, use Player class if needed
    string continentname; //placeholder, use Continent class(?)
    string name;

    int armynum;

public:
    Country();
    Country(string nam, string conname);
    Country(string nam, string conname, string pname);
    Country(string nam, string conname, string pname, int army);

    string toString();
    string getContinentName();
    string getName();
    int getArmyNum();
    
    void setArmyNum(int a);
    void setName(string a);
    void setContinentName(string a);
    void setPlayerName(string a);


};


#endif /* COUNTRY_H */

