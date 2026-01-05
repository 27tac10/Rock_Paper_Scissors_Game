#include "gameV2.h"
#include <iostream>

using namespace std;

GameV2::GameV2()
{
    game_level = 0;
}

GameV2::~GameV2()
{
    delete enemy;
}

void GameV2::play()
{
    cout << endl;
    cout << "Welcome to Rock Paper Scissors Game V2!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Select Game Level (0: Easy, 1: Medium, 2: Hard): ";
    cin >> game_level;
    cin.ignore();

    enemy = new Enemy(game_level);

    while(!finish)
    {
        char player_option;
        char enemy_option;
        int round_result;
        char game_condition;
        game_round++;
        cout << endl;
        cout << "Round " << game_round << "!" << endl;
        cout << "Rock, Paper, Scissors, " << endl;
        cout << "Enter your option: " << endl;
        cout << "   R: Rock" << endl;
        cout << "   P: Paper" << endl;
        cout << "   S: Scissors" << endl;
        cout << endl << "Option: ";
        cin >> player_option;
        player_option = (char)toupper(player_option);

        enemy_option = enemy->select_move(player_option);
        selection(player_option, enemy_option);

        round_result = judgement(player_option, enemy_option);

        switch(round_result)
        {
            case -1:
                cout << name << " lost" << endl;
                result[1]++;
                break;
            case 0:
                cout << "draw" << endl;
                result[2]++;
                break;
            case 1:
                cout << name << " won" << endl;
                result[0]++;
                break;
            default:
                cout << "Invalid option selected!" << endl;
                game_round--;
                break;
        }

        cout << endl << "Do you want to continue? (Y/N): ";
        cin >> game_condition;
        game_condition = (char)toupper(game_condition);
        if(game_condition == 'N')
        {
            finish = true;
            print_result();
        }
    }
    

}

