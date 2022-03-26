#include "chess.h"
#include "cell.h"

using namespace std;

// constructor
Chess::Chess() : checkmate{-1}, check{-1}, stalemate{false} {}

// destructor
Chess::~Chess() {}

// initialize a chess board
void Chess::init() {
    // set the_board to an 8x8
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            the_board[i][j] = new Cell(i, j); // create new cells
        }
    }
}

// create players
void Chess::create_players(vector<string> player_names) {

}

// check if game is over
bool Chess::game_over() {
    if (checkmate != -1) { // checkmate
        // NOT SURE IF THIS IS HOW MULTIPLAYER CHESS POINTS WORK
        for (int i = 0; i < (int) players.size(); ++i) {
            if (i != checkmate) { // not the player that got checkmated
                modify_score(i, 1); // add 1 to score
            }
        }
        return true;
    } else if (stalemate) { // stalemate
        // NOT SURE IF THIS IS HOW MULTIPLAYER CHESS POINTS WORK
        for (int i = 0; i < (int) players.size(); ++i) {
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
