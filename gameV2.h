#ifndef GAMEV2_H
#define GAMEV2_H

#include "game.h"
#include "enemy.h"
using namespace std;

class GameV2 : public Game
{
    public:
        GameV2();
        ~GameV2();
        void play();
    private:
        int game_level;
        Enemy* enemy;
};

#endif //GAMEV2_H