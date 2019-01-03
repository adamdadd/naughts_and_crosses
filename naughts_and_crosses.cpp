#include <iostream>
#include <limits>
#include <vector> // C++ array behaviour shocking without this.


void draw_board(std::vector<std::string> board_squares);
std::vector<std::string> draw_shape(std::string shape, std::vector<std::string> &board_squares);
bool isloss(std::vector<std::string> &board_squares);
bool check_schoice(int choice, std::vector<std::string> board_squares, std::string shape);


int main() {
    std::vector<std::string> squares = {"[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]"};
    const std::string cross = "[X]";
    const std::string naught = "[O]";

    std::cout << "Let's play some naughts and crosses shall we?\n";
    draw_board(squares);

    while (isloss(squares)) {
        std::cout << "Turn: CROSSES\n";
        draw_shape(cross, squares);
        draw_board(squares);
        if (!isloss(squares)) { // equivalent to if isloss == false
            std::cout << "Crosses Wins!\n";
            break;
        }
        std::cout << "Turn: NAUGHTS\n";
        draw_shape(naught,squares);
        draw_board(squares);
        if (!isloss(squares)) { // if not isloss
            std::cout << "Naughts Wins!\n";
            break;
        }
    }
    return 0;
}


void draw_board(std::vector<std::string> board_squares) {
    std::string draw_board;

    std::cout << board_squares[0] + board_squares[1] + board_squares[2] << "\n";   // OUTPUT:      [1][2][3]
    std::cout << board_squares[3] + board_squares[4] + board_squares[5] << "\n";   //              [4][5][6]
    std::cout << board_squares[6] + board_squares[7] + board_squares[8] << "\n";   //              [7][8][9]
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


std::vector<std::string> draw_shape(std::string shape, std::vector<std::string> &board_squares) {
    int square_choice;
    bool valid;


    do
    {
        std::cout << "Pick a square: ";
        std::cin >> square_choice;
        if (std::cin.good()) // If square_choice is a number
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            // reset the buffer's state to good
            std::cin.clear();
            // empty buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "ERROR: That's not a number!";
        }
    } while (!valid);


    switch(square_choice) {
        case 1:
            if (check_schoice(0, board_squares, shape)) {
                board_squares[0] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 2:
            if (check_schoice(1, board_squares, shape)) {
                board_squares[1] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 3:
            if (check_schoice(2, board_squares, shape)) {
                board_squares[2] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 4:
            if (check_schoice(3, board_squares, shape)) {
                board_squares[3] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 5:
            if (check_schoice(4, board_squares, shape)) {
                board_squares[4] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 6:
            if (check_schoice(5, board_squares, shape)) {
                board_squares[5] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 7:
            if (check_schoice(6, board_squares, shape)) {
                board_squares[6] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 8:
            if (check_schoice(7, board_squares, shape)) {
                board_squares[7] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        case 9:
            if (check_schoice(8, board_squares, shape)) {
                board_squares[8] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares);
                return board_squares;
            }
            break;
        default: // If anything other than a number from 1 to 9 is entered.
            std::cout << "ERROR: Not on the board, try again!\n";
            draw_shape(shape,board_squares);
            return board_squares;
            break;
    }
}


bool isloss(std::vector<std::string> &board_squares) { // Possible winning moves listed here.
    if (board_squares[0] == board_squares[1] && board_squares[1] == board_squares[2]) {
        return false;
    } else if (board_squares[3] == board_squares[4] && board_squares[4] == board_squares[5]) {
        return false;
    } else if (board_squares[6] == board_squares[7] && board_squares[7] == board_squares[8]) {
        return false;
    } else if (board_squares[0] == board_squares[4] && board_squares[4] == board_squares[8]) {
        return false;
    } else if (board_squares[2] == board_squares[4] && board_squares[4] == board_squares[6]) {
        return false;
    } else if (board_squares[0] == board_squares[3] && board_squares[3] == board_squares[6]) {
        return false;
    } else if (board_squares[1] == board_squares[4] && board_squares[4] == board_squares[7]) {
        return false;
    } else if (board_squares[2] == board_squares[5] && board_squares[5] == board_squares[8]) {
        return false;
    } else {
        return true;
    }
}


