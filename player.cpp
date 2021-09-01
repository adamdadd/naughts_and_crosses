#include "player.hpp"

class Player {
    public:
        std::vector<std::string> draw_shape(std::string shape, std::vector<std::string> &board_squares, int &run_number) {
            int square_choice;
            bool valid;
            do {
                std::cout << "Pick a square: ";
                if (run_number == 1) {
                    std::cout << "\n";
                    square_choice = computer.random_move();
                    run_number = run_number + 1;
                } else {
                    std::cin >> square_choice;
                }
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

        // Now for the enter validation and draw for each choice
            switch(square_choice) {
                case 1:
                    if (check_schoice(0, board_squares, shape)) {
                        board_squares[0] = shape;
                    } else {
                        draw_shape(shape, board_squares,run_number);
                    }
                    return board_squares;
                    break;
                case 2:
                    if (check_schoice(1, board_squares, shape)) {
                        board_squares[1] = shape;
                    } else {
                        draw_shape(shape, board_squares,run_number);
                    }
                    return board_squares;
                    break;
                case 3:
                    if (check_schoice(2, board_squares, shape)) {
                        board_squares[2] = shape;
                    } else {
                        draw_shape(shape, board_squares, run_number);
                    }
                    return board_squares;
                    break;
                case 4:
                    if (check_schoice(3, board_squares, shape)) {
                        board_squares[3] = shape;
                    } else {
                        draw_shape(shape, board_squares, run_number);
                    }
                    return board_squares;
                    break;
                case 5:
                    if (check_schoice(4, board_squares, shape)) {
                        board_squares[4] = shape;
                    } else {
                        draw_shape(shape, board_squares, run_number);
                    }
                    return board_squares;
                    break;
                case 6:
                    if (check_schoice(5, board_squares, shape)) {
                        board_squares[5] = shape;
                    } else {
                        draw_shape(shape, board_squares, run_number);
                    }
                    return board_squares;
                    break;
                case 7:
                    if (check_schoice(6, board_squares, shape)) {
                        board_squares[6] = shape;
                    } else {
                        draw_shape(shape, board_squares, run_number);
                    }
                    return board_squares;
                    break;
                case 8:
                    if (check_schoice(7, board_squares, shape)) {
                        board_squares[7] = shape;
                    } else {
                        draw_shape(shape, board_squares, run_number);
                    }
                    return board_squares;
                    break;
                case 9:
                    if (check_schoice(8, board_squares, shape)) {
                        board_squares[8] = shape;
                    } else {
                        draw_shape(shape, board_squares, run_number);
                    }
                    return board_squares;
                    break;
                default: // If anything other than a number from 1 to 9 is entered.
                    std::cout << "ERROR: Not on the board, try again!\n";
                    draw_shape(shape,board_squares, run_number);
                    return board_squares;
                    break;
            }

        }

        bool check_schoice(int choice, std::vector<std::string> board_squares, std::string shape) {
           if ((board_squares[choice] == "[X]") || (board_squares[choice] == "[O]")) {
               std::cout << "\nAlready Occupied!\n";
               std::cin.clear();
               // empty buffer
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
               return false;
           } else {
               return true;
           }
        }
};