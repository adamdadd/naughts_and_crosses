#include "player.hpp"

class Player {
    // This is an abstract class for human and computer players 
    protected:
        std::string shape;

        struct XYChoice { int row; int col; };

    private:
        virtual XYChoice get_move() = 0;

    public:
        Player(std::string marker) : shape(marker) {}

        virtual ~Player() {}

        std::string get_shape() { return shape; }

        void make_move(Board& board) {
            // Now for the enter validation and draw for each choice
            XYChoice choice = get_move();
            if (0 <= choice.row && 0 <= choice.col && choice.row < board.board_squares.size() && choice.col < board.board_squares.size()) {
                if (board.is_free_square(choice.col, choice.row)) {
                    board.set_marker(choice.col, choice.row, shape);
                } else {
                    std::cout << "\nAlready Occupied!\n";
                    make_move(board);
                } 
                board.draw_board();
            } else {
                std::cout << "ERROR: Not on the board, try again!\n";
                make_move(board);
            }
        }
};