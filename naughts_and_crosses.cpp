#include <iostream>
#include <vector> // C++ array behaviour shocking without this.
#include <string>

using namespace std;

void draw_board();
void draw_cross();
void draw_naught();
bool isloss();

vector<string> squares = {"[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]"};


int main() {
    cout << "Let's play some naughts and crosses shall we?\n";
    draw_board();
    while (isloss()) {
        draw_cross();
        if (isloss() == false) {
            break;
        }
        draw_naught();
    }
    cout << "Winner!\n";
    return 0;
}


void draw_board() {
    string draw_board;

    cout << squares[0] + squares[1] + squares[2] << "\n";   // OUTPUT:      [1][2][3]
    cout << squares[3] + squares[4] + squares[5] << "\n";   //              [4][5][6]
    cout << squares[6] + squares[7] + squares[8] << "\n";   //              [7][8][9]
}


void draw_cross() {
    string cross = "[X]";
    int square_choice;
    cout << "Pick a square, crosses\n";
    cin >> square_choice;

    switch(square_choice) {
        case 1:
            squares[0] = cross;
            draw_board();
            break;
        case 2:
            squares[1] = cross;
            draw_board();
            break;
        case 3:
            squares[2] = cross;
            draw_board();
            break;
        case 4:
            squares[3] = cross;
            draw_board();
            break;
        case 5:
            squares[4] = cross;
            draw_board();
            break;
        case 6:
            squares[5] = cross;
            draw_board();
            break;
        case 7:
            squares[6] = cross;
            draw_board();
            break;
        case 8:
            squares[7] = cross;
            draw_board();
            break;
        case 9:
            squares[8] = cross;
            draw_board();
            break;
        default:
            draw_board();
            break;
    }
}


void draw_naught() {
    string naught = "[O]";
    int square_choice;
    cout << "Pick a square, naughts\n";
    cin >> square_choice;

    switch(square_choice) {
        case 1:
            squares[0] = naught;
            draw_board();
            break;
        case 2:
            squares[1] = naught;
            draw_board();
            break;
        case 3:
            squares[2] = naught;
            draw_board();
            break;
        case 4:
            squares[3] = naught;
            draw_board();
            break;
        case 5:
            squares[4] = naught;
            draw_board();
            break;
        case 6:
            squares[5] = naught;
            draw_board();
            break;
        case 7:
            squares[6] = naught;
            draw_board();
            break;
        case 8:
            squares[7] = naught;
            draw_board();
            break;
        case 9:
            squares[8] = naught;
            draw_board();
            break;
        default:
            draw_board();
            break;
    }
}


bool isloss() {
    if (squares[0] == squares[1] && squares[1] == squares[2]) {
        return false;
    } else if (squares[3] == squares[4] && squares[4] == squares[5]) {
        return false;
    } else if (squares[6] == squares[7] && squares[7] == squares[8]) {
        return false;
    } else if (squares[0] == squares[4] && squares[4] == squares[7]) {
        return false;
    } else if (squares[2] == squares[4] && squares[4] == squares[6]) {
        return false;
    } else if (squares[0] == squares[3] && squares[3] == squares[6]) {
        return false;
    } else if (squares[1] == squares[4] && squares[4] == squares[7]) {
        return false;
    } else if (squares[2] == squares[5] && squares[5] == squares[8]) {
        return false;
    } else {
        return true;
    }
}


