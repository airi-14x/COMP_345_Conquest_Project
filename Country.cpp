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
    armynum = 0;
    visited = false;

}

Country::Country(string nam) {
    name = nam;
    armynum = 0;
    playername = "";
    
    visited = false;
}

Country::Country(string nam,  string pname) {
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

    return "Country name: " + name  + "\nRuler: " + playername + "\nArmy Size: "
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
 void Country::setVisited(bool a)
 {
     visited = a;
 }
 bool Country::getVisited(){
     return visited;
 }