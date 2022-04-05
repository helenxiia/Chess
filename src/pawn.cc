#include "pawn.h"
#include "cell.h"

using namespace std;

// constructor
Pawn::Pawn(int color) : Piece{color, 1} {}

// destructor
Pawn::~Pawn() {}

// print
void Pawn::print() {
    if (get_color()) {
        cout << "p";
    } else {
        cout << "P";
    }
}

// create valid moves
void Pawn::generate_moves(vector<vector<Cell*>> board, Cell *cell, int row, int col) {
    if (get_has_not_moved()) { // can perform a twostep
        int new_row = row - 2;
        if (get_color()) new_row = row + 2; // if black move other way
        Piece *cell_piece = board[new_row][col]->get_piece();
        if (!cell_piece) { // there is not a piece on the cell
            modify_valid_moves(board[new_row][col], 1); // add to valid moves
            prev_twostep = true;
        }
    } 
    
    // single step
    int new_row = row - 1;
    if (get_color()) new_row = row + 1;
    Piece *cell_piece = board[new_row][col]->get_piece();
    if (!cell_piece) { // there is not a piece on the cell
        modify_valid_moves(board[new_row][col], 1); // add to valid moves
    }
}
