#include "rook.h"
#include "cell.h"

using namespace std;

// constructor
Rook::Rook(int color) : Piece{color, 5} {}

// destructor
Rook::~Rook() {}

// print
void Rook::print() {
    if (get_color()) {
        cout << "r";
    } else {
        cout << "R";
    }
}

// create valid moves
void Rook::generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col) {
    // rooks move linearly 
    // Up
    int i = row + 1;
    while (i < 8) {
        Piece *cell_piece = board[i][col]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[i][col], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][col], 2);
                break;
            }
        } else {
            modify_valid_moves(board[i][col], 1); // add to valid moves
            ++i;
        }
    }
    // Down
    i = row - 1;
    while (i >= 0) {
        Piece *cell_piece = board[i][col]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[i][col], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][col], 2);
                break;
            }
        } else {
            modify_valid_moves(board[i][col], 1); // add to valid moves
            --i;
        }
    }
    // Left
    int j = col - 1;
    while (j >= 0) {
        Piece *cell_piece = board[row][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[row][j], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[row][j], 2);
                break;
            }
        } else {
            modify_valid_moves(board[row][j], 1); // add to valid moves
            --j;
        }
    }
    // Right
    j = col + 1;
    while (j < 8) {
        Piece *cell_piece = board[row][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[row][j], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[row][j], 2);
                break;
            }
        } else {
            modify_valid_moves(board[row][j], 1); // add to valid moves
            ++j;
        }
    }
}

void Rook::unique_status() {}

bool Rook::get_unique_status() { return false; }
