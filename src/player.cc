#include "board.h"
#include "piece.h"
#include "player.h"
#include <memory>
#include <stdio.h>
#include <algorithm>

using namespace std;

// constructor
Player::Player(int side) : side{side}, owned_pieces{vector<Piece*>()}, board{nullptr}, resign{false} {}

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

// move
void Player::move() {
    make_move();
}

// set resign to true
void Player::set_resign() {
    resign = true;
}

// get resign value
bool Player::get_resign() {
    return resign;
}

// add piece
void Player::add_piece(Piece *piece) {
    owned_pieces.emplace_back(piece);
}

// get pieces
vector<Piece*> Player::get_pieces() {
    return owned_pieces;
}

// check if player owns a piece
bool Player::own(Piece *piece) {
    if (count(owned_pieces.begin(), owned_pieces.end(), piece)) {
        return true;
    }
    return false;
}
