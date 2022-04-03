#include "board.h"
#include "piece.h"
#include "player.h"
#include <memory>
#include <stdio.h>
#include <vector>

using namespace std;

// constructor
Player::Player(int side) : side{side}, owned_pieces{vector<Piece*>()}, board{nullptr} {}

// destructor
Player::~Player() {}

// set board
void Player::set_board(Board *b) {
    board = b;
}

// get board
Board *Player::get_board() {
    return board;
}
