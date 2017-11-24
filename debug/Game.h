#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "deckView.h"
#include "view.h"
#include "Deck.h"
#include "Player.h"
class Game
{
    public:
        Game();
        Game(Map*, vector<Player>, view*, deckView*);
        virtual ~Game();
        void start();

    protected:

    private:
        int turn;
        vector<Player> players;
        Deck* deck;
        Map* gameMap;
        view* consoleView;
        Player* getWinner();
};

#endif // GAME_H
