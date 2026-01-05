#include <iostream>
#include "game.h"
#include "gameV2.h"

using namespace std;

int main()
{
    //Game game;
    //game.play();

    Game* gameV2 = new GameV2();
    gameV2->play();

    delete gameV2;
    return 0;
}