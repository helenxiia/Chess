#include "move.h"

using namespace std;

// constructor
Move::Move(Piece *last_piece, Piece *current_piece, Cell *initial_cell, Cell *final_cell, int turn) :
            last_piece{last_piece}, current_piece{current_piece}, initial_cell{initial_cell}, final_cell{final_cell}, turn{turn} {}

// destructor
Move::~Move() {
    delete last_piece;
    delete current_piece;
    delete initial_cell;
    delete final_cell;
}