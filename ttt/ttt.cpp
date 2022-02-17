#include <iostream>
#include <string>
#include <vector>
#include "ttt_functions.hpp"


int main() {

    // Create the board
    std::vector<char> board_zero(9, ' ');

    // Mark select
    std::vector<char> mark_selection = mark_select();

    char player = mark_selection[0];
    char cpu = mark_selection[1];

    // Start game
    int total_moves = 0;

    while (total_moves < 9) {

        paint_board(board_zero, player, cpu);

        place_mark(board_zero, player);
        total_moves++;
        if (is_win(board_zero)) {
            paint_board(board_zero, player, cpu);
            std::cout << "\nYOU WIN.\n";
            break;
        }

        cpu_place_mark(board_zero, cpu);
        total_moves++;
        if (is_win(board_zero)) {
            paint_board(board_zero, player, cpu);
            std::cout << "\nYOU LOSE.\n";
            break;
        }

    }

    return 0;

}
