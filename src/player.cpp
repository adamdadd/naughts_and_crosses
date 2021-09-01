#include "player.hpp"

class Player {
    // This is an abstract class for human and computer players 
    protected:
        std::string shape;

    private:
        virtual int get_move() = 0;

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
        Player(std::string marker) : shape(shape) {
            shape = marker;
        };

        virtual ~Player() {};

        std::vector<std::string> make_move(std::vector<std::string> &board_squares) {
            // Now for the enter validation and draw for each choice
            int choice = get_move();
            if (0 < choice && choice < 10) {
                if (is_free_square(choice-1, board_squares)) {
                    board_squares[choice-1] = shape;
                } else {
                    make_move(board_squares);
                    return board_squares;
                } 
                return board_squares;
            } else {
                std::cout << "ERROR: Not on the board, try again!\n";
                make_move(board_squares);
                return board_squares;
            }
        };
};