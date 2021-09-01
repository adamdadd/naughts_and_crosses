#include <iostream>
#include <limits>
#include <random>
#include <vector> 
#include "naughts_and_crosses.hpp"

class Game {
    private:
        bool isloss(std::vector<std::string> board_squares) { // Possible winning moves listed here.
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
        };

        bool isdraw(int count, std::vector<std::string> board_squares) {
                for (int i=0; i<9; i += 1) {
                    if (((board_squares[i] == "[X]") || (board_squares[i] == "[O]"))) {
                        count += 1;
                    }
                }
                if ((count == 9) && (isloss(board_squares))) {
                    return true;
                } else {
                    return false;
                }
        };

    public:
        void play_game(std::vector<std::string> &board_squares, int counter) {
            const std::string cross = "[X]";
            const std::string naught = "[O]";
            while (isloss(board_squares)) { // while not a winning move
                std::cout << "Turn: CROSSES\n";
                computer.make_move(computer.get_move(), board_squares, cross);
                board.draw_board(board_squares);
                if (!isloss(board_squares)) { // check for winning move
                    std::cout << "\nCrosses Wins!\n";
                    break;
                } else if (isdraw(counter, board_squares)) {
                    std::cout << "\nDraw!\n";
                    break;
                }
                std::cout << "Turn: NAUGHTS\n";
                human.make_move(human.get_move(), board_squares, naught);
                board.draw_board(board_squares);
                if (!isloss(board_squares)) { // check for winning move
                    std::cout << "\nNaughts Wins!\n";
                    break;
                } else if (isdraw(counter, board_squares)) {
                    std::cout << "\nDraw!\n";
                    break;
                }
            }
        }
};

    
int main() {
    Game game;
    std::vector<std::string> squares = {"[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]"};
    // std::vector<std::vector<std::string> > qsquares = {squares, squares, squares, squares, squares, squares, squares, squares, squares};
    int counter = 0;
    // draw_quantum_board(qsquares);
    std::cout << "\n      NAUGHTS AND CROSSES\n\n";
    board.draw_board(squares);
    game.play_game(squares, counter);
    return 0;
};
