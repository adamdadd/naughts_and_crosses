#include "naughts_and_crosses.hpp"

class Game {
    Board& board;
    HumanPlayer& human;
    ComputerPlayer& computer;

    private:
        bool is_row_win(int first_square) {
            return board.board_squares[first_square] == board.board_squares[first_square+1] && 
                board.board_squares[first_square+1] == board.board_squares[first_square+2]; 
        };

        bool is_col_win(int first_square) {
            return board.board_squares[first_square] == board.board_squares[first_square+3] &&
                board.board_squares[first_square+3] == board.board_squares[first_square+6];
        }

        bool is_diag_win(int first_square) {
            return board.board_squares[first_square] == board.board_squares[sizeof(board.board_squares) / 2] && 
                board.board_squares[sizeof(board.board_squares) / 2] == board.board_squares[sizeof(board.board_squares) - first_square];
        }

        bool is_win() { // Possible winning moves listed here.
            bool is_rows = is_row_win(0) || is_row_win(3) || is_row_win(6);
            bool is_cols = is_col_win(0) || is_col_win(1) || is_col_win(2);
            bool is_diag = is_diag_win(0) || is_diag_win(2);
            return is_rows || is_cols || is_diag;
        };

        bool is_draw(int count) {
            for (int i=0; i<9; i += 1) {
                if (((board.board_squares[i] == "X") || (board.board_squares[i] == "O"))) {
                    count += 1;
                }
            }
            return count == 9 && !is_win();
        };

        int player_move(int count, Player& player) {
            player.make_move(board);
            if (is_win()) { // check for winning move
                std::cout << "\n" << player.get_shape() << " Wins!\n";
                return 0;
            } else if (is_draw(count)) {
                std::cout << "\nDraw!\n";
                return 0;
            }
            return 1;
        };

    public:
        Game(Board& game_board, HumanPlayer& human_player, ComputerPlayer& computer_player) : board(game_board), human(human_player), computer(computer_player) {};

        void play_game(int move_counter) {
            while (!is_win()) { // while not a winning move
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
