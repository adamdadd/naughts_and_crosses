#include <iostream>
#include <limits>
#include <random>
#include <vector> // C++ array behaviour shocking without this.


// Function Declarations
void play_game(std::vector<std::string> &board_square, int counter, int run);
void draw_quantum_board(std::vector<std::vector<std::string>> qboard);
void draw_board(std::vector<std::string> board_squares);
bool check_schoice(int choice, std::vector<std::string> board_squares, std::string shape);
std::vector<std::string> draw_shape(std::string shape, std::vector<std::string> &board_squares, int &run_number);
bool isloss(std::vector<std::string> &board_squares);
bool isdraw(int count, std::vector<std::string> board_squares);
int random_move();


int main() {
    std::vector<std::string> squares = {"[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]"};
    std::vector<std::vector<std::string>> qsquares = {squares, squares, squares, squares, squares, squares, squares, squares, squares};
    int counter = 0;
    int run = 1;

    draw_quantum_board(qsquares);
    std::cout << "\n      NAUGHTS AND CROSSES\n\n";
    draw_board(squares);
    play_game(squares, counter, run);

    return 0;
}


void play_game(std::vector<std::string> &board_squares, int counter, int run) {
    const std::string cross = "[X]";
    const std::string naught = "[O]";

    while (isloss(board_squares)) { // while not a winning move
        std::cout << "Turn: CROSSES\n";
        draw_shape(cross, board_squares, run);
        draw_board(board_squares);
        if (!isloss(board_squares)) { // check for winning move
            std::cout << "\nCrosses Wins!\n";
            break;
        } else if (isdraw(counter, board_squares)) {
                break;
        }
        std::cout << "Turn: NAUGHTS\n";
        draw_shape(naught,board_squares, run);
        draw_board(board_squares);
        if (!isloss(board_squares)) { // if not isloss
            std::cout << "\nNaughts Wins!\n";
            break;
        } else if (isdraw(counter, board_squares)) {
                break;
            }
        }
}


void draw_quantum_board(std::vector<std::vector<std::string>> qboard) {// FOLLOWING BLOCK IS DISPLAY FUNCTION FOR QUANTUM BOARD
// Block 1
    for (int i= 0; i <3; i = i+1) { // Rows
        for (int j = 0; j < 3; j = j+1) { // Columns
            std::cout << qboard[i][j];
        }
        std::cout << "  ";
    }
    std::cout << "\n";
    for ( int k = 0; k < 3; k = k+1) {
        for (int l = 3; l < 6; l = l+1){
            std::cout << qboard[k][l];
        }
        std::cout << "  ";
    }
    std::cout << "\n";
    for ( int m = 0; m < 3; m = m+1) {
        for (int n = 6; n < 9; n = n+1){
            std::cout << qboard[m][n];
        }
        std::cout << "  ";
    }
        std::cout << "\n\n";
// Block 2
    for (int i= 3; i < 6; i = i+1) { // Rows
        for (int j = 0; j < 3; j = j+1) { // Columns
            std::cout << qboard[i][j];
        }
        std::cout << "  ";
    }
    std::cout << "\n";
    for ( int k = 3; k < 6; k = k+1) {
        for (int l = 3; l < 6; l = l+1){
            std::cout << qboard[k][l];
        }
        std::cout << "  ";
    }
    std::cout << "\n";
    for ( int m = 3; m < 6; m = m+1) {
        for (int n = 6; n < 9; n = n+1){
            std::cout << qboard[m][n];
        }
        std::cout << "  ";
    }
        std::cout << "\n\n";
// Block 3
    for (int i= 6; i < 9; i = i+1) { // Rows
        for (int j = 0; j < 3; j = j+1) { // Columns
            std::cout << qboard[i][j];
        }
        std::cout << "  ";
    }
    std::cout << "\n";
    for ( int k = 6; k < 9; k = k+1) {
        for (int l = 3; l < 6; l = l+1){
            std::cout << qboard[k][l];
        }
        std::cout << "  ";
    }
    std::cout << "\n";
    for ( int m = 6; m < 9; m = m+1) {
        for (int n = 6; n < 9; n = n+1){
            std::cout << qboard[m][n];
        }
        std::cout << "  ";
    }
// END OF QUANTUM BOARD DISPLAY
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


std::vector<std::string> draw_shape(std::string shape, std::vector<std::string> &board_squares, int &run_number) {
    int square_choice;
    bool valid;

    do
    {
        std::cout << "Pick a square: ";
        if (run_number == 1) {
            std::cout << "\n";
            square_choice = random_move();
            run_number = run_number + 1;
        } else {
            std::cin >> square_choice;
        }
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

// Now for the enter validation and draw for each choice
    switch(square_choice) {
        case 1:
            if (check_schoice(0, board_squares, shape)) {
                board_squares[0] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        case 2:
            if (check_schoice(1, board_squares, shape)) {
                board_squares[1] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares,run_number);
                return board_squares;
            }
            break;
        case 3:
            if (check_schoice(2, board_squares, shape)) {
                board_squares[2] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        case 4:
            if (check_schoice(3, board_squares, shape)) {
                board_squares[3] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        case 5:
            if (check_schoice(4, board_squares, shape)) {
                board_squares[4] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        case 6:
            if (check_schoice(5, board_squares, shape)) {
                board_squares[5] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        case 7:
            if (check_schoice(6, board_squares, shape)) {
                board_squares[6] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        case 8:
            if (check_schoice(7, board_squares, shape)) {
                board_squares[7] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        case 9:
            if (check_schoice(8, board_squares, shape)) {
                board_squares[8] = shape;
                return board_squares;
            } else {
                draw_shape(shape, board_squares, run_number);
                return board_squares;
            }
            break;
        default: // If anything other than a number from 1 to 9 is entered.
            std::cout << "ERROR: Not on the board, try again!\n";
            draw_shape(shape,board_squares, run_number);
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


bool isdraw(int count, std::vector<std::string> board_squares) {
        for (int i=0; i<9; i = i+1) {
            if (((board_squares[i] == "[X]") || (board_squares[i] == "[O]"))) {
                count = count + 1;
            }
        }
        if ((count == 9) && (isloss(board_squares))) {
            std::cout << "\nDraw!\n";
            return true;
        } else {
            return false;
        }
}

//TODO: Use this to add a random starting move.
int random_move() {
    int n = 0;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 9);
    n = dis(gen);
    return n;
}
