#include "chess.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

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
    // set pawns
    for (int i = 0; i < 8; ++i) { // white
        set_piece(6, i, new Pawn(0));
    }
    for (int i = 0; i < 8; ++i) { // black
        set_piece(1, i, new Pawn(1));
    }
    // set bishops
    set_piece(7, 2, new Bishop(0)); // white
    set_piece(7, 5, new Bishop(0)); // white
    set_piece(0, 2, new Bishop(1)); // black
    set_piece(0, 5, new Bishop(1)); // black
    // set knights
    set_piece(7, 1, new Knight(0)); // white
    set_piece(7, 6, new Knight(0)); // white
    set_piece(0, 1, new Knight(1)); // black
    set_piece(0, 6, new Knight(1)); // black
    // set rooks
    set_piece(7, 0, new Rook(0)); // white
    set_piece(7, 7, new Rook(0)); // white
    set_piece(0, 0, new Rook(1)); // black
    set_piece(0, 7, new Rook(1)); // black
    // set queens
    set_piece(7, 3, new Queen(0)); // white
    set_piece(0, 3, new Queen(1)); // black
    // set king
    set_piece(7, 4, new King(0)); // white
    set_piece(0, 4, new King(1)); // black
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
