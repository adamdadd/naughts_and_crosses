#include <vector> 

#include "board.cpp"
#include "human_player.cpp"
#include "computer_player.cpp"

Board board;
HumanPlayer human;
ComputerPlayer computer;

void play_game(std::vector<std::string> &board_square, int counter);
bool isloss(std::vector<std::string> &board_squares);
bool isdraw(int count, std::vector<std::string> board_squares);


