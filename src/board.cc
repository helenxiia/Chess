#include "board.h"

#include "cell.h"
#include "move.h"
#include "player.h"
#include "piece.h"
#include "textdisplay.h"

using namespace std;

// static map
map<int, float> Board::score = map<int, float>();

// constructor
Board::Board() : the_board{vector<vector<unique_ptr<Cell>>>()}, previous_moves{vector<unique_ptr<Move>>()}, 
                    pieces{vector<unique_ptr<Piece>>()}, players{vector<unique_ptr<Player>>()}, turn{0}, currently_playing{true},
                    td{unique_ptr<TextDisplay>{new TextDisplay(this)}} {}

// destructor
Board::~Board() {} 

// set board
void Board::set_board(int row, int col) {
    for (int i = 0; i < row; ++i) {
        vector<unique_ptr<Cell>> line;
        for (int j = 0; j < col; ++j) {
            // create new cells
            line.emplace_back(unique_ptr<Cell>{new Cell(i, j)});
        }
        the_board.emplace_back(move(line));
    }
}

// get text display
TextDisplay *Board::get_td() {
    return td.get();
}

// get number of players
int Board::get_players_size() {
    return (int) players.size();
}

// set piece on board
void Board::set_piece(int row, int col, Piece *piece) {
    Cell *cell = the_board[row][col].get();
    cell->set_piece(piece);
    piece->set_cell(cell);
}

// get reference to board
vector<vector<Cell*>> Board::get_ref_board() {
    vector<vector<Cell*>> ref_board;
    for (int i = 0; i < (int) the_board.size(); ++i) {
            vector<Cell*> ref_row;
        for (int j = 0; j < (int) the_board.at(i).size(); ++j) {
            Cell *c = the_board[i][j].get();
            ref_row.emplace_back(c);
        }
        ref_board.emplace_back(ref_row);
    }
    return ref_board;
}

// modify scoreboard
void Board::modify_score(int player, float point) {
    if (!score.count(player)) { // player is not in map yet
        score.insert({player, point});
    } else {
        auto it = score.find(player); // find the current score
        it->second = it->second + point; // add new score to cumulative score
    }
}

// run the game
void Board::run() {
    while(currently_playing) { // while game is playing
        Player *cur_player = players.at(turn).get(); // get which player is playing, based on the turn
        try {
            // ---- NEED CLASSES TO BE DEFINED ---- //
            // WE MAY NEED A COPY CONSTRUCTOR HERE
            // SINCE I DON'T WANT TO DO THAT, LETS HAVE PLAYER RETURN A VECTOR WITH THE INFORMATION NEEDED FOR MOVE
            // IE. LAST_PIECE, CURRENT_PIECE, INITIAL_CELL, FINAL_CELL
            // THIS INCREASES COUPLING THO
            // Move move = cur_player->make_move(); 
            // previous_moves.emplace_back(move);

            // increment turn
            if (turn == (int) players.size() - 1) { // it is last player's turn
                turn = 0;
            } else {
                ++turn;
            }
            // increment count
            ++count;

            // create move
            // Move *move  = new Move();
            // previous_moves.emplace_back(move);
        } catch (...) { // probably should define some error here
            // throw invalid move
        }
    }
}
