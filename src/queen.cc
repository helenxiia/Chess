#include "queen.h"
#include "cell.h"

using namespace std;

// constructor
Queen::Queen(int color) : Piece{color, 9} {}

// destructor
Queen::~Queen() {}

// print
void Queen::print() {
    if (get_color()) {
        cout << "q";
    } else {
        cout << "Q";
    }
}

// create valid moves
void Queen::generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col) {
    // queens move diagonally 
    // SE
    int i = row + 1;
    int j = col + 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 0);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 0); // add to valid moves
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
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 0);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 0); // add to valid moves
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
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 0);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 0); // add to valid moves
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
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][j], 0);
                break;
            }
        } else {
            modify_valid_moves(board[i][j], 0); // add to valid moves
            --i;
            --j;
        }
    }
    // queens move linearly 
    // Up
    i = row + 1;
    while (i < 8) {
        Piece *cell_piece = board[i][col]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][col], 0);
                break;
            }
        } else {
            modify_valid_moves(board[i][col], 0); // add to valid moves
            ++i;
        }
    }
    // Down
    i = row - 1;
    while (i >= 0) {
        Piece *cell_piece = board[i][col]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[i][col], 0);
                break;
            }
        } else {
            modify_valid_moves(board[i][col], 0); // add to valid moves
            --i;
        }
    }
    // Left
    j = col - 1;
    while (j >= 0) {
        Piece *cell_piece = board[row][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[row][j], 0);
                break;
            }
        } else {
            modify_valid_moves(board[row][j], 0); // add to valid moves
            --j;
        }
    }
    // Right
    j = col + 1;
    while (j < 8) {
        Piece *cell_piece = board[row][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(board[row][j], 0);
                break;
            }
        } else {
            modify_valid_moves(board[row][j], 0); // add to valid moves
            ++j;
        }
    }
}
