#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Deck.h"
#include "Player.h"
class Game
{
    public:
        Game();
        Game(Map* m, vector<Player> p);
        virtual ~Game();
        void start();

    protected:

    private:
        int turn;
        vector<Player> players;
        Deck* deck;
        Map* gameMap;
};

#endif // GAME_H
