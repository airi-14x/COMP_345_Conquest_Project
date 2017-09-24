/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Continent.h"
#include <vector>
#include <string>
using std::string;
//using namespace std; //because i cant use std vector
using std::vector;

Continent::Continent()
{
    name = "";
    cnts= {};
    
}
Continent::Continent(string nem)
{
    name = nem;
}

void Continent::setName(string n)
{  name = n; 
}
string Continent::getName()
{
    return name;
}
string Continent::toString()
{
    return "Name: " + name + "\n";
}

void Continent::addCountry(Country c)
{
    cnts.push_back(c);
}

string Continent::nameCountries()
{
    string temp;
    if(cnts.empty())
    {
        return (name + " is an empty continent");
    }
    else
    {
        for(int i = 0; i < cnts.size();i++)
        {
            temp += cnts[i].getName() + "\n";
        }
        return temp;
    }
}

Country Continent::getCountry(string name)
{
    
    for(int i = 0; i< cnts.size();i++)
    {
        if(cnts[i].getName() == (name))
            
            return cnts[i];
    }
}