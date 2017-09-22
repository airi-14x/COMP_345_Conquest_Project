/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Continent.h
 * Author: User
 *
 * Created on September 19, 2017, 9:00 PM
 */

#ifndef CONTINENT_H
#define CONTINENT_H

//#include <vector>
//#include <string>
#include "Country.h"

//using std::string;
using namespace std;


//using std::vector;

class Continent {
private:
    string name; // placeholder, use Player class if needed
    vector<Country> cnts;

public:

    Continent();
    Continent(string nem);

    string toString();
    string getName();
    

    void addCountry(Country name);
    Country getCountry(string name);

    void printCountries();
    void set Name();
;



#endif /* CONTINENT_H */

