#include "board.hpp"

class Board {
    public:
        std::vector<std::vector<std::string>> board_squares;

        Board(int size) {
            for (int r = 0; r < size; r++) {
                std::vector<std::string> row;
                for (int c = 0; c < size; c++) {
                    row.push_back(std::to_string(r) + std::to_string(c));
                }
                board_squares.push_back(row);
            }
        }

        const void draw_board() {
            std::cout << "\n";
            for (int i = 0; i < board_squares.size(); i++) {
                for (int j = 0; j < board_squares[i].size(); j++) {
                    std::cout << "| " << board_squares[i][j] << " |";
                }
            std::cout << "\n\n";
            }
        }

        void set_marker(int choice_x, int choice_y, std::string marker) {
            board_squares[choice_y][choice_x] = marker;
        }

        bool is_free_square(int choice_x, int choice_y) {
           if ((board_squares[choice_y][choice_x] == "XX") || (board_squares[choice_y][choice_x] == "OO")) {
               std::cin.clear();
               // empty buffer
            //    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
               return false;
           } else {
               return true;
           }
        }
};