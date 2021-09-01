#include <vector> 

std::vector<std::string> board_squares;
std::string shape;

int get_move();
bool check_schoice(int choice, std::vector<std::string> board_squares, std::string shape);