#include "cell.h"
#include "piece.h"

using namespace std;

// constructor
Cell::Cell(int row, int col) : piece{nullptr}, row{row}, col{col}, status{-1}, threats{map<int, int>()} {}

// destructor
Cell::~Cell() {} 

// get piece on Cell
Piece* Cell::get_piece() {
    return piece;
}

// set piece on Cell
void Cell::set_piece(Piece *p) {
    piece = p;
}

// removes Piece from Cell
void Cell::remove_piece() {
    // delete piece; // not sure if this is necessary 
    piece = nullptr;
}

// set all pieces
void Cell::set_all_pieces(std::vector<Piece*> ap) {
    all_pieces = ap;
}

// get row
int Cell::get_row() {
    return row;
}

// get col
int Cell::get_col() {
    return col;
}

// get status
int Cell::get_status() {
    return status;
}

// get threats of player
int Cell::get_threats(int player) {
    if (threats.count(player)) {
        return threats.at(player);
    }
    return 0; // no threats
}

// Cells observe all pieces
void Cell::notify() {
    // update status
    if (!piece) { // null
        status = 0;
    } else if (piece->get_color() == 0) { // white
        status = 1;
    } else if (piece->get_color() == 1) { // black
        status = 2;
    }
    // update threats
    threats.clear();
    for (auto piece : all_pieces) {
        if (piece->valid_move(this)) { // piece can move to this cell
            int col = piece->get_color();
            if (threats.count(col)) {
                ++threats[col];
            } else {
                threats[col] = 1;
            }
        }
    }
}
