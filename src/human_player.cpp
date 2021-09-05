#include "human_player.hpp"

class HumanPlayer: public Player {
    public:
        HumanPlayer(std::string marker) : Player(marker) { };

        int input_move(std::string message) { 
            int square_choice;
            bool valid;
            do {
                std::cout << message;
                std::cin >> square_choice;
                if (std::cin.good()) {
                    // If square_choice is a number
                    //everything went well, we'll get out of the loop and return the value
                    valid = true;
                } else {
                    // reset the buffer's state to good
                    std::cin.clear();
                    // empty buffer
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "ERROR: That's not a number!";
                }
            } while (!valid);
            return square_choice;
        }

        XYChoice get_move() {
            XYChoice player_result;
                player_result.row = input_move("Pick a row: ");
                player_result.col = input_move("Pick a col: ");
                return player_result;
        }
};
