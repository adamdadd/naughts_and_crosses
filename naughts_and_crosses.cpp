#include <iostream>
#include <limits>
#include <string>
#include <vector> // C++ array behaviour shocking without this.

using namespace std;

void draw_board(vector<string> board_squares);
vector<string> draw_shape(string shape, vector<string> &board_squares);
bool isloss(vector<string> &board_squares);



int main() {
    vector<string> squares = {"[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]"};
    string cross = "[X]";
    string naught = "[O]";

    cout << "Let's play some naughts and crosses shall we?\n";
    draw_board(squares);

    while (isloss(squares)) {
        cout << "Turn: CROSSES\n";
        draw_shape(cross, squares);
        if (!isloss(squares)) { // equivalent to if isloss == false
            cout << "Crosses Wins!\n";
            break;
        }
        cout << "Turn: NAUGHTS\n";
        draw_shape(naught,squares);
        if (!isloss(squares)) { // if not isloss
            cout << "Naughts Wins!\n";
            break;
        }
    }
    return 0;
}


void draw_board(vector<string> board_squares) {
    string draw_board;

    cout << board_squares[0] + board_squares[1] + board_squares[2] << "\n";   // OUTPUT:      [1][2][3]
    cout << board_squares[3] + board_squares[4] + board_squares[5] << "\n";   //              [4][5][6]
    cout << board_squares[6] + board_squares[7] + board_squares[8] << "\n";   //              [7][8][9]
}


vector<string> draw_shape(string shape, vector<string> &board_squares) {
    int square_choice;
    bool valid;

    do
    {
        cout << "Pick a square: ";
        cin >> square_choice;
        if (cin.good())
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            // reset the buffer's state to good
            cin.clear();
            // empty buffer
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: That's not a number!" << endl;
        }
    } while (!valid);

    switch(square_choice) {
        case 1:
            board_squares[0] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 2:
            board_squares[1] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 3:
            board_squares[2] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 4:
            board_squares[3] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 5:
            board_squares[4] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 6:
            board_squares[5] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 7:
            board_squares[6] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 8:
            board_squares[7] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        case 9:
            board_squares[8] = shape;
            draw_board(board_squares);
            return board_squares;
            break;
        default:
            cout << "ERROR: Not on the board, try again!\n";
            draw_shape(shape,board_squares);
            return board_squares;
            break;
    }
}


bool isloss(vector<string> &board_squares) { // Possible winning moves listed here.
    if (board_squares[0] == board_squares[1] && board_squares[1] == board_squares[2]) {
        return false;
    } else if (board_squares[3] == board_squares[4] && board_squares[4] == board_squares[5]) {
        return false;
    } else if (board_squares[6] == board_squares[7] && board_squares[7] == board_squares[8]) {
        return false;
    } else if (board_squares[0] == board_squares[4] && board_squares[4] == board_squares[7]) {
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


