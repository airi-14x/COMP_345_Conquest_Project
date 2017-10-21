/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sandbox.cpp
 * Author: Earl
 *
 * Created on October 9, 2017, 3:15 PM
 */
#include "GameInit.h"
#include "Map.h"
#include "cards.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {

    GameInit ye;
    ye.pickMap();
    ye.createPlayers();
    
    //Testing dice rolling facilities and hands
    for (int i = 0; i < Player::players.size(); i++) {
        cout << Player::players[i]->getName() << " hand size: " << Player::players[i]->getHand().getSize();
        cout << "\t";
        Player::players[i]->getDice().randomiser(); //test roll
        cout << endl;
        cout << endl;

    }
    ye.enlargeDeck();
    cout << "Number of countries: " << GameInit::playMap->getMapSize() << endl;
    cout << "Number of cards in deck: " << GameInit::playDeck->getSize() << endl;


    return 0;
}

