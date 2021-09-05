#include "naughts_and_crosses.hpp"

class Game {
    Board& board;
    HumanPlayer& human;
    ComputerPlayer& computer;

    private:
        bool is_row_win(int first_square) {
            return board.board_squares[first_square][0] == board.board_squares[first_square][1] && 
                board.board_squares[first_square][1] == board.board_squares[first_square][2]; 
        }

        bool is_col_win(int first_square) {
            return board.board_squares[0][first_square] == board.board_squares[1][first_square] &&
                board.board_squares[1][first_square] == board.board_squares[2][first_square];
        }

        bool is_diag_win(int first_square) {
            int max_idx = board.board_squares[0].size() - 1;
            return board.board_squares[0][first_square] == board.board_squares[max_idx/2][max_idx / 2] && 
                board.board_squares[max_idx / 2][max_idx / 2] == board.board_squares[max_idx][max_idx - first_square];
        }

        bool is_win() { // Possible winning moves listed here.
            bool is_rows = is_row_win(0) || is_row_win(1) || is_row_win(2);
            bool is_cols = is_col_win(0) || is_col_win(1) || is_col_win(2);
            bool is_diag = is_diag_win(0) || is_diag_win(2);
            return is_rows || is_cols || is_diag;
        }

        bool is_draw() {
            int max_idx = board.board_squares[0].size();
            int count = 0;
            for (int i=0; i < max_idx; i++) {
                for (int j=0; j < max_idx; j++) {
                    if (((board.board_squares[j][i] == "XX") || (board.board_squares[j][i] == "OO"))) {
                        count++;
                    }
                }
            }
            return count == (max_idx*max_idx) && !is_win();
        }

        bool player_move(Player& player) {
            player.make_move(board);
            if (is_win()) { // check for winning move
                std::cout << "\n" << player.get_shape() << " Wins!\n";
                return true;
            } else if (is_draw()) {
                std::cout << "\nDraw!\n";
                return true;
            }
            return 0;
        }

    public:
        Game(Board& game_board, HumanPlayer& human_player, ComputerPlayer& computer_player) : board(game_board), human(human_player), computer(computer_player) {};

        void play_game() {
            bool game_over = false;
            while (!game_over) { // while not a winning move
                game_over = player_move(computer);
                if (game_over) {break;}
                game_over = player_move(human);
            }
        }
};


int main() {
    Board board = Board(3);
    HumanPlayer human = HumanPlayer("OO");
    ComputerPlayer computer = ComputerPlayer("XX");
    {
        std::cout << "\n      NAUGHTS AND CROSSES\n\n";
        Game game = Game(board, human, computer);
        game.play_game();
    }
    // std::vector<std::vector<std::string> > qsquares = {squares, squares, squares, squares, squares, squares, squares, squares, squares};
    // draw_quantum_board(qsquares);
    return 0;
};
