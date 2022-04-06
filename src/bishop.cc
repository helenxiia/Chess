#include "bishop.h"
#include "cell.h"

using namespace std;

// constructor
Bishop::Bishop(int color) : Piece{color, 4} {}

// destructor
Bishop::~Bishop() {}

// print
void Bishop::print() {
    if (get_color()) {
        cout << "b";
    } else {
        cout << "B";
    }
}

// create valid moves
void Bishop::generate_moves(vector<vector<Cell*>> board, Cell *cell, int row, int col) {
    // bishops move diagonally 
    // SE
    int i = row + 1;
    int j = col + 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[i][j], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 2);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 1); // add to valid moves
            ++i;
            ++j;
        }
    }
    // SW
    i =  row + 1;
    j =  col - 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[i][j], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 2);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 1); // add to valid moves
            ++i;
            --j;
        }
    }
    // NE
    i =  row - 1;
    j =  col + 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[i][j], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 2);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 1); // add to valid moves
            --i;
            ++j;
        }
    }
    // NW
    i =  row - 1;
    j =  col - 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                modify_valid_moves(board[i][j], 3);
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 2);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 1); // add to valid moves
            --i;
            --j;
        }
    }
}

void Bishop::unique_status() {}

bool Bishop::get_unique_status() { return false; }