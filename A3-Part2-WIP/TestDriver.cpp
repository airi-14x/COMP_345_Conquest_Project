/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestDriver.cpp
 * Author: User
 *
 * Created on November 5, 2017, 5:50 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "player.h"
#include "Map.h"
#include "PhaseView.h"
using namespace std;

int main() {
    cout<<"why";
    Player p1 =  Player("P1");
    Player p2 =  Player("P2");
    PhaseView Oi = PhaseView(&p1);
    Map m = Map();
    
    Continent c1 = Continent("c1", 10);
    Country c1c1 = Country("c1c1", "P1", 1);
    Country c1c2 = Country("c1c2", "P1", 8);
    Country c1c3 = Country("c1c3", "P1", 1);
    Continent c2 = Continent("c2", 5);
    Country c2c1 = Country("c2c1", "P2", 3);
    Country c2c2 = Country("c2c2", "P2", 5);
    Country c2c3 = Country("c2c3", "P1", 10);
    Country c2c4 = Country("c2c4", "P2", 5);
    m.link(&c1c1, &c1c2);
    m.link(&c1c2, &c1c3);
    m.link(&c1c2, &c2c1);
    m.link(&c1c2, &c2c2);
    m.link(&c2c1, &c2c2);
    m.link(&c2c2, &c2c3);
    m.link(&c2c3, &c2c4);

    c1.addCountry(&c1c1);
    c1.addCountry(&c1c2);
    c1.addCountry(&c1c3);
    c2.addCountry(&c2c1);
    c2.addCountry(&c2c2);
    c2.addCountry(&c2c3);
    c2.addCountry(&c2c4);

    m.addContinent(&c1);
    m.addContinent(&c2);

    p1.addCountry(&c1c1);
    p1.addCountry(&c1c2);
    p1.addCountry(&c1c3);
    p1.addCountry(&c2c3);
    p2.addCountry(&c2c1);
    p2.addCountry(&c2c2);
    p2.addCountry(&c2c4);


    
    Deck d1 = Deck(&m);
    Deck d2 = Deck(&m);

    p1.getHand().addCard(d1.draw());
    p1.getHand().addCard(d1.draw());
    p1.getHand().addCard(d1.draw());
    p1.getHand().addCard(d1.draw());
    p1.getHand().addCard(d1.draw());
    p1.getHand().addCard(d1.draw());

    p2.getHand().addCard(d2.draw());
    p2.getHand().addCard(d2.draw());
    p2.getHand().addCard(d2.draw());

    cout << "Please enter desired phase to view:" << endl
            << "\t1. Reinforcement Phase" << endl
            << "\t2. Attack Phase" << endl
            << "\t3. Fortification Phase" << endl;
    int choice;
   cin >> choice;
    switch (choice) {
        case 1:
            p1.reinforcementPhase(&m);
            p2.reinforcementPhase(&m);

            break;
        case 2:
            p1.attackPhase(&m);
            break;
        case 3:
            p1.fortifyPhase(&m);
            break;
    }
    cout << endl;

    return 0;
}
