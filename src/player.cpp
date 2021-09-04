#include "player.hpp"

class Player {
    // This is an abstract class for human and computer players 
    protected:
        std::string shape;

    private:
        virtual int get_move() = 0;

    public:
        Player(std::string marker) : shape(marker) { };

        virtual ~Player() {};

        std::string get_shape() { return shape; };

        void make_move(Board& board) {
            // Now for the enter validation and draw for each choice
            int choice = get_move();
            if (0 < choice && choice < 10) {
                if (board.is_free_square(choice-1)) {
                    board.set_marker(choice-1, shape);
                } else {
                    make_move(board);
                } 
                board.draw_board();
            } else {
                std::cout << "ERROR: Not on the board, try again!\n";
                make_move(board);
            }
        };
};