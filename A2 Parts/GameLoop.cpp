#include "GameLoop.h"
#include "player.h"
#include "Map.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

GameLoop::GameLoop(Map* m, vector<Player> p, int n)
{
    gameMap = m;
    players = p;
    numOfPlayers = n;
    winner = NULL;
};

void GameLoop::start() {
    while(winner == NULL){
        for(int i = 0; i < numOfPlayers; i++){
            reinforcementsPhase(&players[i]);
            attackPhase(&players[i]);
            fortificationPhase(&players[i]);
            winner = getWinner();
            if (winner == &players[i])
                break;
            cout << endl;
        }
    }
    cout << endl << "Player " << winner->getName() << " has won!" << endl;
};

void GameLoop::reinforcementsPhase(Player* player){
    cout << "Reinforcements Phase: Player " << player->getName() << endl;
};

void GameLoop::attackPhase(Player* player) {
    cout << "Attack Phase: Player " << player->getName() << endl;
};

void GameLoop::fortificationPhase(Player* player) {
    cout << "Fortification Phase: Player " << player->getName() << endl;
};

Player* GameLoop::getWinner(){
    for(int k = 0; k < players.size(); k++){
        bool valid = true;
        int numOfConti = gameMap->getContiSize();
        for(int i = 0; i < numOfConti; i++){
            Continent* conti = gameMap->getContinent(i);
            int numOfCountries = conti->getCntsSize();
            for(int j = 0; j < numOfCountries; j++){
                Country* country = conti->getCountry(j);
                if (country->getPlayerName() != players[k].getName()){
                    valid = false;
                };
            }
        }
        if (valid){
            return &players[k];
        }
    }

    return NULL;
};

GameLoop::~GameLoop()
{
    delete gameMap;
    delete winner;
    delete getWinner();
};
