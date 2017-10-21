/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <string>
#include "player.h"
#include "GameInit.h"
using std::cin;
using std::cout;
using std::endl;
Map* GameInit::playMap;
Deck* GameInit::playDeck;
GameInit::GameInit() {
    mapFiles = {"World.map", "Alabama.map", "Aden.map", "AdvantageComputer.map", "Africa.map",
        "invalid1.map", "invalid2.map", "invalid3.map", "invalid4.map"};
    mp;

}

GameInit::GameInit(vector<string> param) {
    mapFiles = param;
    mp;
}

void GameInit::pickMap() {
    bool invalidMap = 1;
    string menu;
    int indexHolder;
    for (int i = 0; i < mapFiles.size(); i++) {
        menu += "\t" + std::to_string(i + 1) + ". " + mapFiles[i] + "\n";
    }
    while (invalidMap) {
        cout << "Please select a Map to play on. \n" + menu << endl;
        cin >> indexHolder;

        try {
            mp.readFile("map/" + mapFiles[indexHolder - 1]);
            invalidMap = 0;

        } catch (InvalidMapException e){
            cout << "Try again, invalid map." << endl;
            invalidMap = 1;
        }
       playMap = mp.getMap();

    }
}

void GameInit::createPlayers() {
    int playerNum;
    cout << "How many players to create? 2-6" << endl;
    cin >> playerNum;
    while (playerNum < 2 || playerNum > 6) {
        cout << "Invalid input, please select a number between 2 to 6:" << endl;
        cin >> playerNum;
    }

    string nameholder;

    for (int i = 1; i <= playerNum; i++) {
        nameholder = "Player " + std::to_string(i);
        new Player(nameholder);
    }

    


}

void GameInit::enlargeDeck(){
    
        
        playDeck = new Deck(playMap);
    
}