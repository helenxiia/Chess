#include "chess.h"
#include "bishop.h"

#include "human.h"

using namespace std;

// constructor
Chess::Chess() : Board{}, check{-1}, stalemate{false} {}

// destructor
Chess::~Chess() {}

// initialize a chess board
void Chess::init() {
    // set the_board to an 8x8
    set_board(8, 8);
    set_piece(0, 0, new Bishop(0));
    TextDisplay *text_display = get_td();
    text_display->print_board("chess");
}

// create players
void Chess::create_players(vector<string> player_names) {
    int side = 0;
    for (auto player : player_names) {
        if (player == "human") {
            Human *new_player = new Human(side);
            add_player(new_player);
        }
    }
}

// check if game is over
bool Chess::game_over() {
    if (checkmate != -1) { // checkmate
        // NOT SURE IF THIS IS HOW MULTIPLAYER CHESS POINTS WORK
        for (int i = 0; i < get_players_size(); ++i) {
            if (i != checkmate) { // not the player that got checkmated
                modify_score(i, 1); // add 1 to score
            }
        }
        return true;
    } else if (stalemate) { // stalemate
        // NOT SURE IF THIS IS HOW MULTIPLAYER CHESS POINTS WORK
        for (int i = 0; i < get_players_size(); ++i) {
            modify_score(i, 0.5); // everyone gets half a point
        }
        return true;
    } else {
        return false;
    }
}

// notify Chess when piece moves
void Chess::notify() {

}

// setup chess board mode
// setup mode
void Chess::setup() {
    string s;
    while (getline(cin, s)) { 
        istringstream ss{s};
        string cmd;
        ss >> cmd;
        if (cmd == "+") { // places piece

        } else if (cmd == "-") { // removes piece
            
        } else if (cmd == "=") { // sets turn

        } else if (cmd == "done") {
            // check if setup is valid
            break;
        }
    }
}
