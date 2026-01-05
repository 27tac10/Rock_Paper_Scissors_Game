#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(int level)
{
    difficulty_level = level;
}

Enemy::~Enemy()
{
}

char Enemy::select_move(char player_move)
{
    char option;

    if(difficulty_level == 0)
    {
        switch(player_move)
        {
            case 'R':
                option = 'S';
                break;
            case 'P':
                option = 'R';
                break;
            case 'S':
                option = 'P';
                break;
            default:
                option = 'N';
                break;
        }
    }
    else if(difficulty_level == 1)
    {
        int temp = rand() % 3;
        switch(temp)
        {
            case 0:
                option = 'R';
                break;
            case 1:
                option = 'P';
                break;
            case 2:
                option = 'S';
                break;
            default:
                option = 'N';
                break;
        }
    }
    else if(difficulty_level == 2)
    {
        if(player_move == 'R')
        {
            option = 'P';
        }
        else if(player_move == 'P')
        {
            option = 'S';
        }
        else if(player_move == 'S')
        {
            option = 'R';
        }
        else
        {
            option = 'N';
        }
    }

    return option;
}
