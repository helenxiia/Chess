#include "bishop.h"
#include "cell.h"
#include "board.h"

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
void Bishop::generate_moves() {
    vector<vector<Cell*>> cur_board = get_board()->get_ref_board();
    Cell *cur_cell = get_cell();
    int cur_row = cur_cell->get_row();
    int cur_col = cur_cell->get_col();
    // bishops move diagonally 
    // SE
    int i = cur_row + 1;
    int j = cur_col + 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = cur_board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(cur_board[i][j], 0);
                break;
            }
        }
        modify_valid_moves(cur_board[i][j], 0); // add to valid moves
        ++i;
        ++j;
    }
    // SW
    i = cur_row + 1;
    j = cur_col - 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = cur_board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(cur_board[i][j], 0);
                break;
            }
        }
        modify_valid_moves(cur_board[i][j], 0); // add to valid moves
        ++i;
        --j;
    }
    // NE
    i = cur_row - 1;
    j = cur_col + 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = cur_board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(cur_board[i][j], 0);
                break;
            }
        }
        modify_valid_moves(cur_board[i][j], 0); // add to valid moves
        --i;
        ++j;
    }
    // NW
    i = cur_row - 1;
    j = cur_col - 1;
    while (i < 8 && j < 8 && i >=0 && j >=0) {
        Piece *cell_piece = cur_board[i][j]->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() == get_color()) { // if piece is same color, blocked
                break;
            } else { // piece is different color, can capture
                modify_valid_moves(cur_board[i][j], 0);
                break;
            }
        }
        modify_valid_moves(cur_board[i][j], 0); // add to valid moves
        --i;
        --j;
    }
}