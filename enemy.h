#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    public:
        Enemy(int level);
        ~Enemy();
        char select_move(char player_move);
    private:
        int difficulty_level;
};

#endif //ENEMY_H