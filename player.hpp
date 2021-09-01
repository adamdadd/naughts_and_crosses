#include <vector> 

#include "computer.cpp"

Computer computer;

bool check_schoice(int choice, std::vector<std::string> board_squares, std::string shape);
std::vector<std::string> draw_shape(std::string shape, std::vector<std::string> &board_squares, int &run_number);