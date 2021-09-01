#include "computer.hpp"

class ComputerPlayer: public Player {
    private:
        int random_move() {
            int n = 0;
            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> dis(1, 9);
            n = dis(gen);
            return n;
        }

    public:
        int get_move() {
            return random_move();
        }
};