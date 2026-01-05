#ifndef GAME_H
#define GAME_H

using namespace std;
#include <string>

class Game
{
    public:
        Game();
        ~Game();
        virtual void play();
        int judgement(char, char);
        void print_result();
        virtual char enemy_selection();
        void selection(char, char);

    protected:
        int result[3];
        int game_round;
        string name;
        bool finish;
        
};

#endif // GAME_H