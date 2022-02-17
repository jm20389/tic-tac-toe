#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include "ttt_functions.hpp"


// function
std::vector<char> mark_select() {

    int selection = 0;
    std::vector<char> output;

    do {
        std::cout << "\nSelect a mark: \n";
        std::cout << "1) X\n";
        std::cout << "2) O\n";
        std::cin >> selection;
    } while (selection > 2 || selection < 1);

    if (selection == 1) {
        //return std::vector<char> output = {'X', 'O'};
        return { 'X', 'O' };
    }
    else {
        //return std::vector<char> output = {'X', 'O'};
        return { 'O', 'X' };
    }

}



// function
void paint_board(std::vector<char> board, char player, char cpu) {

    std::cout << "\nYou: " << player << " CPU: " << cpu;
    std::cout << "\n\n\n" << "Board status: \n";

    std::cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |   (1 - 2 - 3)\n";

    //std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯\n";

    std::cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |   (4 - 5 - 6)\n";

    std::cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |   (7 - 8 - 9)\n";

}


// function
void place_mark(std::vector<char>& board, char player) {

    int position;
    bool valid_position;
    bool valid_move;

    do {

        do {
            std::cout << "\nSelect a board position: \n";
            std::cin >> position;

            if (position > 9 || position < 1) {
                std::cout << "\nInvalid board position. Select 1 to 9: \n";
                valid_position = false;
            }
            else {
                valid_position = true;
            }

        } while (!valid_position);



        if (board[position - 1] == ' ') {
            board[position - 1] = player;
            valid_move = true;

        }
        else {
            std::cout << "\nPosition already taken. Select a different slot: \n";
            valid_move = false;
        }

    }

    while (!valid_move);

}


// function
void cpu_place_mark(std::vector<char> &board, char cpu) {

    int position;
    bool valid_move;

    do {

        srand((unsigned)time(0));
        position = (rand() % 9) + 1;


        if (board[position - 1] == ' ') {
            board[position - 1] = cpu;
            valid_move = true;
        }

        else {
            valid_move = false;
        }

    } while (!valid_move);

}



// function
bool is_win(std::vector<char> board) {

    // Check horizontals
    if (board[0] == board[1] && board[1] == board[2]) {
        if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ') { return true; } 
        else return false;
    }
    else if (board[3] == board[4] && board[4] == board[5]) {
        if (board[0] != ' ' && board[4] != ' ' && board[5] != ' ') { return true; }
        else return false;
    }
    else if (board[6] == board[7] && board[7] == board[8]) {
        if (board[6] != ' ' && board[7] != ' ' && board[8] != ' ') { return true; }
        else return false;
    }

    // Check verticals
    else if (board[0] == board[3] && board[3] == board[6]) {
        if (board[0] != ' ' && board[3] != ' ' && board[6] != ' ') { return true; }
        else return false;
    }
    else if (board[1] == board[4] && board[4] == board[7]) {
        if (board[1] != ' ' && board[4] != ' ' && board[7] != ' ') { return true; }
        else return false;
    }
    else if (board[2] == board[5] && board[5] == board[8]) {
        if (board[2] != ' ' && board[5] != ' ' && board[8] != ' ') { return true; }
        else return false;
    }

    // Check diagonals
    else if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] != ' ') { return true; }
        else return false;
    }
    else if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] != ' ') { return true; }
        else return false;
    }
    else {
        return false;
    }

}