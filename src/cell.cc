#include "cell.h"
#include "piece.h"

using namespace std;

// constructor
Cell::Cell(int row, int col) : piece{nullptr}, row{row}, col{col}, status{-1}, threats{map<int, int>()} {}

// destructor
Cell::~Cell() { /* delete piece; */ } // creates a warning for some reason

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

}
