#include <iostream>
#include "game.h"
#include <ctime>

using namespace std;

Game::Game()
{
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;
    name = "unknown";
    finish = false;
    game_round = 0;
}

Game::~Game()
{
    // future update
}

void Game::play()
{
    cout << endl;
    cout << "Welcome to Rock Papper Scissors Game!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);


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

        enemy_option = enemy_selection();
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
                cout << name << " WIN!" << endl;
                result[0]++;
                break;
            default:
                cout << "invalid" << endl;
                break;
        }

        cout << endl;
        cout << "Would you like to play again?" << endl;
        cout << "   y: Yes, continue" << endl;
        cout << "   n: No, close game" << endl;

        do
        {
            cout << "Option: ";
            cin >> game_condition;
        } while (game_condition != 'y' && game_condition != 'n');

        if(game_condition == 'y')
        {
            finish = false;
        }
        else
        {
            finish = true;
        }
    }

    print_result();
}

int Game::judgement(char player, char enemy)
{
    int result;
    if(player == 'R')
    {
        if(enemy == 'R')
        {
            result = 0;
        }
        else if(enemy == 'P')
        {
            result = -1;
        }
        else // Scissors
        {
            result = 1;
        }
    }
    else if(player == 'P')
    {
        if(enemy == 'R')
        {
            result = 1;
        }
        else if(enemy == 'P')
        {
            result = 0;
        }
        else // Scissors
        {
            result = -1;
        }
    }
    else if(player == 'S')
    {
        if(enemy == 'R')
        {
            result = -1;
        }
        else if(enemy == 'P')
        {
            result = 1;
        }
        else // Scissors
        {
            result = 0;
        }
    }
    else
    {
        result = -999;
    }
    
    return result;
}

void Game::print_result()
{
    cout << endl;
    cout << "Total Games: " << game_round << endl;
    cout << "Result:" << endl;
    cout << "   " << name << ": " << result[0] << endl;
    cout << "   Enemy: " << result[1] << endl;
    cout << "   Draw: " << result[2] << endl;
    cout << endl;
    cout << "Good bye" << endl;
}

char Game::enemy_selection()
{
    char option;
    int temp;
    srand(time(0));
    temp = rand() % 3;
    if(temp == 0)
    {
        option = 'R';
    }
    else if(temp == 1)
    {
        option = 'P';
    }
    else
    {
        option = 'S';
    }

    return option;
}

void Game::selection(char player, char enemy)
{
    string player_option;
    string enemy_option;

    if(player == 'R')
    {
        player_option = "Rock";
    }
    else if(player == 'P')
    {
        player_option = "Paper";
    }
    else if(player == 'S')
    {
        player_option = "Scissors";
    }

    if(enemy == 'R')
    {
        enemy_option = "Rock";
    }
    else if(enemy == 'P')
    {
        enemy_option = "Paper";
    }
    else if(enemy == 'S')
    {
        enemy_option = "Scissors";
    }

    cout << "Shoot" << endl;
    cout << endl;
    cout << name << ": " << player_option << endl;
    cout << "Enemy: " << enemy_option << endl;
}