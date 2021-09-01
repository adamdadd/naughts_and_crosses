#include "board.hpp"

class Board {
    public:
        const void draw_board(std::vector<std::string> board_squares) {
            std::string draw_board;
            std::cout << board_squares[0] + board_squares[1] + board_squares[2] << "\n";   // OUTPUT:      [1][2][3]
            std::cout << board_squares[3] + board_squares[4] + board_squares[5] << "\n";   //              [4][5][6]
            std::cout << board_squares[6] + board_squares[7] + board_squares[8] << "\n";   //              [7][8][9]
        }
};