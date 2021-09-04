#include "naughts_and_crosses.hpp"

class Game {
    Board& board;
    HumanPlayer& human;
    ComputerPlayer& computer;

    private:
        bool isloss() { // Possible winning moves listed here.
            if (board.board_squares[0] == board.board_squares[1] && board.board_squares[1] == board.board_squares[2]) {
                return false;
            } else if (board.board_squares[3] == board.board_squares[4] && board.board_squares[4] == board.board_squares[5]) {
                return false;
            } else if (board.board_squares[6] == board.board_squares[7] && board.board_squares[7] == board.board_squares[8]) {
                return false;
            } else if (board.board_squares[0] == board.board_squares[4] && board.board_squares[4] == board.board_squares[8]) {
                return false;
            } else if (board.board_squares[2] == board.board_squares[4] && board.board_squares[4] == board.board_squares[6]) {
                return false;
            } else if (board.board_squares[0] == board.board_squares[3] && board.board_squares[3] == board.board_squares[6]) {
                return false;
            } else if (board.board_squares[1] == board.board_squares[4] && board.board_squares[4] == board.board_squares[7]) {
                return false;
            } else if (board.board_squares[2] == board.board_squares[5] && board.board_squares[5] == board.board_squares[8]) {
                return false;
            } else {
                return true;
            }
        };

        bool isdraw(int count) {
                for (int i=0; i<9; i += 1) {
                    if (((board.board_squares[i] == "X") || (board.board_squares[i] == "O"))) {
                        count += 1;
                    }
                }
                if ((count == 9) && (isloss())) {
                    return true;
                } else {
                    return false;
                }
        };

        int player_move(int count, Player& player) {
                player.make_move(board);
                if (!isloss()) { // check for winning move
                    std::cout << "\n" << player.get_shape() << " Wins!\n";
                    return 0;
                } else if (isdraw(count)) {
                    std::cout << "\nDraw!\n";
                    return 0;
                }
            return 1;
        };

    public:
        Game(Board& game_board, HumanPlayer& human_player, ComputerPlayer& computer_player) : board(game_board), human(human_player), computer(computer_player) {};

        void play_game(int move_counter) {
            while (isloss()) { // while not a winning move
                player_move(move_counter, computer);
                player_move(move_counter, human);
            }
        }
};

    
int main() {
    Board board;
    HumanPlayer human = HumanPlayer("O");
    ComputerPlayer computer = ComputerPlayer("X");
    {
        std::cout << "\n      NAUGHTS AND CROSSES\n\n";
        int counter = 0;
        Game game = Game(board, human, computer);
        game.play_game(counter);
    }
    // std::vector<std::vector<std::string> > qsquares = {squares, squares, squares, squares, squares, squares, squares, squares, squares};
    // draw_quantum_board(qsquares);
    return 0;
};
