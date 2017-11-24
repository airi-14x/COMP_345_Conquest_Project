#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

Game::Game(Map* m, vector<Player> p, view* v, deckView* d)
{
    gameMap = m;
    players = p;
    deck = new Deck(m);
    turn = 0;
    consoleView = v;
    cout << "game created" << endl;
}

void Game::start(){
    cout << "game started" << cout;
    string addDec = "";
    bool promptForDec = true;
    Player* winner = nullptr;

    while(winner == nullptr){
        turn++;
        cout << "========================================" << endl << "turn: " << turn << endl << "========================================" << endl;

        while(promptForDec && addDec.compare("3") != 0){
            cout << endl << "Decorator Manager" << endl;
            cout << "1: add decorator" << endl;
            cout << "2: remove decorator" << endl;
            cout << "3: finish turn without adding additional decorator" << endl;
            cout << "4: finish game with current decorators" << endl;
            cin >> addDec;

            if(addDec.compare("1") == 0) {
                string type = "";
                cout << "Add Decorator" << endl;
                while (type.compare("1") != 0 && type.compare("2") != 0 && type.compare("3") != 0){
                    cout << "1: to add player domination observer" << endl;
                    cout << "2: to add continent control observer" << endl;
                    cout << "3: to a cancel" << endl;
                    cin >> type;
                }
                if(type.compare("1") == 0) {
                    consoleView->setDisplayPerc(true);
                } else if(type.compare("2") == 0) {
                    consoleView->setDisplayConti(true);
                }
            } else if (addDec.compare("2") == 0){
                string type = "";
                cout << "Remove Decorator" << endl;
                while (type.compare("1") != 0 && type.compare("2") != 0 && type.compare("3") != 0){
                    cout << "1: to remove player domination observer" << endl;
                    cout << "2: to remove continent control observer" << endl;
                    cout << "3: to a cancel" << endl;
                    cin >> type;
                }
                if(type.compare("1") == 0) {
                    consoleView->setDisplayPerc(false);
                } else if(type.compare("2") == 0) {
                    consoleView->setDisplayConti(false);
                }
            } else if (addDec.compare("4") == 0){
                promptForDec = false;
            }
        }
        addDec = "";


        for(int i = 0; i < players.size(); i++){
            players[i].takeTurn(gameMap, deck);
        }

        winner = getWinner();
    }
}

Player* Game::getWinner(){
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


Game::~Game()
{
}
