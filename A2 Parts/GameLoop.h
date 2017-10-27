#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "player.h"
#include "Map.h"
#include <vector>
using namespace std;

class GameLoop
{
    public:
        GameLoop();
        GameLoop(Map* m, vector<Player> p, int n);
        virtual ~GameLoop();
        void start();
    private:
        void reinforcementsPhase(Player* player);
        void attackPhase(Player* player);
        void fortificationPhase(Player* player);
        int numOfPlayers;
        vector<Player> players;
        Map* gameMap;
        Player* winner;
        Player* getWinner();
};

#endif // GAMELOOP_H
