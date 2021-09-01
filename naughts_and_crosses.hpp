#include <vector> 

#include "board.cpp"
#include "player.cpp"

Board board;
Player player;

void play_game(std::vector<std::string> &board_square, int counter, int run);
bool isloss(std::vector<std::string> &board_squares);
bool isdraw(int count, std::vector<std::string> board_squares);


