/*
 * File:   Tournament.cpp
 * Author: Airi Chow (#40003396), Earl Aromin (#40004997)
 *
 * Created on November 16, 2017, 3:27 PM
 */

#include "Tournament.h"
#include "player.h"
#include "Map.h"
#include "deck.h"
#include <iostream>
using std::cin;
using std::cout;

Tournament::Tournament() {
    mapNumber = 0;
    gameNumber = 0;
    maxTurns = 0;
    mapFiles = {"World.map", "Alabama.map", "Aden.map", "AdvantageComputer.map", "Africa.map"};

}

void Tournament::createPlayers() {
    int input = -1;

    while (input < 2 || input > 4) {
        cout << "Decide the number of computer players participating (2 to 4): ";
        cin>> input;
    }

    int pnumber = input;
    for (int i = 0; i < pnumber; i++) {
        cout << "Please designate the strategy for Player " << (i + 1) << ": " << endl
                << "1. Aggressive" << endl << "2. Benevolent" << endl << "3. Random"
                << endl << "4. Cheater" << endl;
        cin >> input;
        switch (input) {
            case 1: new Player(("Aggressive" + std::to_string(i)), new AggressiveStrategy);
                break;
            case 2: new Player(("Benevolent" + std::to_string(i)), new BenevolentStrategy);
                break;
            case 3: new Player(("Random" + std::to_string(i)), new RandomStrategy);
                break;
            case 4: new Player(("Cheater" + std::to_string(i)), new CheaterStrategy);
                break;
            default: cout << "Credit card number not found, please pay us." << endl;
        }
    }



}

void Tournament::setGameNumber() {
    int input = -1;

    while (input < 1 || input > 5) {
        cout << "Decide the number of games to be played per map  (1 to 5): ";
        cin>> input;
    }
    gameNumber = input;
}

void Tournament::setMaxTurns() {
    int input = -1;

    while (input < 10 || input > 50) {
        cout << "Decide the maximum number of turns per game (10 to 50): ";
        cin>> input;
    }
    maxTurns = input;
}

Player* Tournament::getWinner(Map* m) {
    for (int k = 0; k < Player::players.size(); k++) {
        bool valid = true;
        int numOfConti = m->getContiSize();
        for (int i = 0; i < numOfConti; i++) {
            Continent* conti = m->getContinent(i);
            int numOfCountries = conti->getCntsSize();
            for (int j = 0; j < numOfCountries; j++) {
                Country* country = conti->getCountry(j);
                if (country->getPlayerName() != Player::players[k]->getName()) {
                    valid = false;
                };
            }
        }
        if (valid) {
            return Player::players[k];
        }
    }

    return NULL;

}

void Tournament::play() {


    int resultSize = maps.size() + 1;
    string results [resultSize];
    for (int overused = 1; overused < maps.size() + 1; overused++) {
        results[overused] = ("Map " + std::to_string(overused) + "\t");
    }
    for (int game = 1; game <= gameNumber; game++) {
        results[0] += ("\tGame " + std::to_string(game));
    }

    for (int i = 1; i <= maps.size(); i++) {
        //create a deck for map[i-1]
        Map* tempMap;
        tempMap = maps[i - 1];
        Deck d = Deck(tempMap);

        Deck* tempDeck = &d;
        for (int game = 1; game <= gameNumber; game++) {
            StartRandomiser *sr = new StartRandomiser();

            sr->round_robin_randomiser(Player::players);
            //randomizes player turns
            vector<Player*> shufflePlayers(sr->getTurnPlayerVector());
            vector<Country*> tempCnts;
            //creates vector of countries
            for (int i = 0; i < tempMap->getContiSize(); i++) {
                for (int j = 0; j < tempMap->getContinent(i)->getCntsSize(); j++) {
                    tempCnts.push_back(tempMap->getContinent(i)->getCountry(j));
                    //cout << "NAME OF COUNTRY : " << tempMap->getContinent(i)->getCountry(j)->getName() << endl;
                }

            }
            for (int i = 0; i < tempMap->getContiSize(); i++) {
                for (int j = 0; j < tempMap->getContinent(i)->getCntsSize(); j++) {
                    tempMap->getContinent(i)->getCountry(j)->resetHasBeenAssigned();
                }
            }

            sr->assignCountries(tempCnts.size(), tempCnts);



            for (int i = 0; i < tempMap->getContiSize(); i++) {
                for (int j = 0; j < tempMap->getContinent(i)->getCntsSize(); j++) {
                    tempMap->getContinent(i)->getCountry(j)->resetHasBeenAssigned();
                }
            }

            tempCnts.clear();

            int k = maxTurns;
            while (getWinner(tempMap) == NULL && (k > 0)) {
                
                for (int j = 0; j < Player::players.size(); j++) {
                    cout << "Map#" << std::to_string(i) << "; Game #" << game << "; " << Player::players[j]->getName() << " turn#" << std::to_string(maxTurns - (k)) << endl;
                    Player::players[j]->takeTurn(tempMap, tempDeck);
                    k--;
                }


            }



            if (getWinner(tempMap) != NULL)
                results[i] += (getWinner(tempMap)->getName() + "\t");
            else
                results[i] += ("DRAW\t");

        }

    }

    cout << "==============MAPS===============" << endl;
    cout << M;
    cout << "==============Players=============" << endl;


    for (int i = 0; i < Player::players.size(); i++) {
        cout << "Player " << std::to_string(i + 1) << ": " << Player::players[i]->getName() << endl;
    }

    cout << "==================================" << endl;
    cout << "NUMBER OF GAMES: " << std::to_string(gameNumber) << endl;
    cout << "MAX NUMBER OF TURNS: " << std::to_string(maxTurns) << endl;
    cout << "==================================" << endl << endl;

    for (int m = 0; m < mapNumber + 1; m++) {

        cout << results[m] << endl;

    }
}

void Tournament::createMaps() {
    int input = -1;

    while (input < 1 || input > 5) {
        cout << "Decide the number of maps to play with (1 to 5) : ";
        cin>> input;
    }
    mapNumber = input;
    for (int i = 0; i < mapNumber; ++i) {

        cout << "Please pick map #" << (i + 1) << ":" << endl;
        //prints available maps
        for (int k = 0; k < mapFiles.size(); k++) {
            cout << "\t" << std::to_string(k + 1) << ". " << mapFiles[k] << "\n";
        }

        bool invalidMap = 1;
        while (invalidMap) {
            cin >> input;
            try {
                MapParser mp;

                mp.readFile("map/" + mapFiles[input - 1]);
                invalidMap = 0;
                maps.push_back(mp.getMap());

            } catch (InvalidMapException e) {
                cout << "Try again, invalid map." << endl;
                invalidMap = 1;
            }
            M += "Map " + std::to_string(input) + ": " + mapFiles[input - 1] + "\n";

        }




    }
}
