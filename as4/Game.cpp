#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(Map* m, vector<Player> p)
{
    gameMap = m;
    players = p;
    deck = new Deck(m);
    turn = 0;
}

void Game::start(){
    while(turn < 5){
        turn++;
        cout << "========================================" << endl << "turn: " << turn << endl << "========================================" << endl;
        for(int i = 0; i < players.size(); i++){
            players[i].takeTurn(gameMap, deck);
        }
    }
}

Game::~Game()
{
}
