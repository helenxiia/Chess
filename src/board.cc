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
    // add to pieces
    auto p = unique_ptr<Piece>{piece};
    pieces.emplace_back(move(p));
    // add to player
    players.at(piece->get_color())->add_piece(piece);
}

// add player
void Board::add_player(Player *player) {
    player->set_board(this);
    players.emplace_back(unique_ptr<Player>{player});
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

// get a score
int Board::get_score(int player) {
    return score.at(player);
}

// player resigned
int Board::resign() {
    for (int i = 0; i < (int) players.size(); ++i) {
        if (players.at(i)->get_resign()) return i; 
    }
    return -1;
}

// reset the game
void Board::reset() {
    the_board.clear();
    previous_moves.clear();
    pieces.clear();
    players.clear();
    currently_playing = false;
    turn = 0;
    count = 0;
}

// run the game
void Board::run(vector<string> player_names) {
    currently_playing = true;
    // make players
    create_players(player_names);
    // initialize board
    init();
    // initialize score
    for (int i = 0; i < get_players_size(); ++i) {
        if (score.count(i) == 0) {
            modify_score(i, 0);
        }
    }
    // run
    while(currently_playing) { // while game is playing
        if (players.size() == 0) break; // no players so no game is being played
        Player *cur_player = players.at(turn).get(); // get which player is playing, based on the turn
        try {
            cur_player->move();

            // check if game over
            if (game_over()) {
                reset();
                break;
            }

            // increment turn
            if (turn == (int) players.size() - 1) { // it is last player's turn
                turn = 0;
            } else {
                ++turn;
            }
            // increment count
            ++count;
            // display
            td->print_board("chess");
            // create move
            // Move *move  = new Move();
            // previous_moves.emplace_back(move);
        } catch (...) { // probably should define some error here
            // throw invalid move
        }
    }
}
