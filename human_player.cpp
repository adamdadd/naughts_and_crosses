#include "human_player.hpp"

class HumanPlayer: public Player {
    public:
        int get_move() {
            int square_choice;
            bool valid;
            do {
                std::cout << "Pick a square: ";
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
                return (int) square_choice;
            } while (!valid);
        }
};
