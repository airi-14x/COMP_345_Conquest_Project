/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   GameInit.h
 * Author: Earl
 *
 * Created on October 9, 2017, 2:35 PM
 */

#ifndef GAMEINIT_H
#define GAMEINIT_H
#include "player.h"
#include "card.h"
#include "MapParser.h"

using std::vector;
class GameInit{

private:
    vector <string> mapFiles;
    MapParser mp;
public:
    GameInit(); //uses default ones used in asg1
    GameInit(vector<string> param);
    static Map* playMap; //map
    static Deck* playDeck;// deck to be used.

    void pickMap();
    void createPlayers();
    void enlargeDeck();

};

#endif /* GAMEINIT_H */

