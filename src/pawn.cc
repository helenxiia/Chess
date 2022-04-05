#include "pawn.h"
#include "cell.h"

using namespace std;

// constructor
Pawn::Pawn(int color) : Piece{color, 1}, promotable{false}, prev_twostep{false} {}

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
    if (row - 1 >= 0 && row + 1 < 8) {
        Piece *cell_piece = board[new_row][col]->get_piece();
        if (!cell_piece) { // there is not a piece on the cell
            modify_valid_moves(board[new_row][col], 1); // add to valid moves
        }
        int new_col_l = col - 1;
        int new_col_r = col + 1;

        if (new_col_l >= 0) {
            Piece *cell_piece2 = board[new_row][new_col_l]->get_piece();
            if (cell_piece2 != nullptr) {
                modify_valid_moves(board[new_row][new_col_l], 1); // add to valid moves, captures
            }
        }
        if (new_col_r < 8) {
            Piece *cell_piece3 = board[new_row][new_col_r]->get_piece();
            if (cell_piece3 != nullptr) {
                modify_valid_moves(board[new_row][new_col_r], 1); // add to valid moves, captures
            }
        }
    }
}

void Pawn::unique_status() {
    promotable = true;
}

bool Pawn::get_unique_status() {
    return promotable;
}
