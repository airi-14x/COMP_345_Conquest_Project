/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Country.h"
using std::string;

Country::Country() {
    name = "";
    playername = "";
    continentname = "";
    armynum = 0;

}

Country::Country(string nam, string conname) {
    continentname = conname;
    name = nam;
    armynum = 0;
    playername = "";
}

Country::Country(string nam, string conname, string pname) {
    playername = pname;
    continentname = conname;
    name = nam;
    armynum = 0;
}

Country::Country(string nam, string conname, string pname, int army) {
    playername = pname;
    continentname = conname;
    name = nam;
    armynum = army;
}

string Country::toString() {

    return "Country name: " + name + "\nContinent: "
            + continentname + "\nRuler: " + playername + "\nArmy Size: "
            + std::to_string(armynum);
}

 string Country::getContinentName() {
    return continentname;
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

 void Country::setContinentName(string a) {
    continentname = a;
}

 void Country::setPlayerName(string a) {
    playername = a;
}