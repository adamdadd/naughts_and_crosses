#include "player.hpp"

class Player {
    private:
        bool is_free_square(int choice, std::vector<std::string> board_squares) {
           if ((board_squares[choice] == "[X]") || (board_squares[choice] == "[O]")) {
               std::cout << "\nAlready Occupied!\n";
               std::cin.clear();
               // empty buffer
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
               return false;
           } else {
               return true;
           }
        };

    public:
        virtual int get_move() = 0;

        std::vector<std::string> make_move(int choice, std::vector<std::string> &board_squares, std::string shape) {
            // Now for the enter validation and draw for each choice
            if (0 < choice && choice < 10) {
                if (is_free_square(choice-1, board_squares)) {
                    board_squares[choice-1] = shape;
                } else {
                    int choice = get_move();
                    make_move(choice, board_squares, shape);
                    return board_squares;
                } 
                return board_squares;
            } else {
                std::cout << "ERROR: Not on the board, try again!\n";
                int choice = get_move();
                make_move(choice, board_squares, shape);
                return board_squares;
            }
        };
};