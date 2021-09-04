#include "board.hpp"

class Board {
    public:
        std::vector<std::string> board_squares = {"1","2","3","4","5","6","7","8","9"};

        const void draw_board() {
            std::cout << "\n" << board_squares[0] << " | " << board_squares[1] << " | " << board_squares[2] << "\n";   // OUTPUT:      [1][2][3]
            std::cout << "----------" << "\n";
            std::cout << board_squares[3] << " | " << board_squares[4] << " | " << board_squares[5] << "\n";   //              [4][5][6]
            std::cout << "----------" << "\n";
            std::cout << board_squares[6] << " | " << board_squares[7] << " | " << board_squares[8] << "\n\n";   //              [7][8][9]
        }

        void set_marker(int square_idx, std::string marker) {
            board_squares[square_idx] = marker;
        }

        bool is_free_square(int choice) {
           if ((board_squares[choice] == "X") || (board_squares[choice] == "O")) {
               std::cout << "\nAlready Occupied!\n";
               std::cin.clear();
               // empty buffer
            //    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
               return false;
           } else {
               return true;
           }
        };
};