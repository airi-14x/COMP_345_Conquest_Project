/* 
 * File:   Tournament.h
 * Author: Airi Chow (#40003396), Earl Aromin (#40004997)
 *
 * Created on November 16, 2017, 3:27 PM
 */

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "player.h"
#include "Map.h"
#include "MapParser.h"
#include "StartRandomiser.h"

class Tournament {
private:
    int mapNumber;
    int gameNumber;
    int maxTurns;
    vector<Map*> maps;
    vector <string> mapFiles;

    string M;
    
    

public:

    
    //Constructors
    Tournament();
        
    //Setters
   // void setMapNumber();
    void createPlayers();
    void createMaps();
    void setGameNumber();
    void setMaxTurns();
    
    //Plays game for you
    void play();
    //Gets winner for a specified map
    Player* getWinner(Map* m);
    
    //General Getters
    //int getMapNumber(){return mapNumber;};
    int getGameNumber(){return gameNumber;};
    int getMaxTurns(){return maxTurns;};
};

#endif /* TOURNAMENT_H */

