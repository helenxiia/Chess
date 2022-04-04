#include <memory>
#include <vector>
#include "piece.h"
#include "board.h"
#include "cell.h"

using namespace std;

// Piece::Piece(Cell *cell, int color 
//             // int value, vector<unique_ptr<Cell>> valid_moves, string name
//             ) : 
//             cell{cell}, color{color}, 
//             // value{value}, valid_moves{valid_moves}, name{name} 
//             is_taken{false}, has_not_moved{true} {}

Piece::Piece(int color, int value) : cell{nullptr}, color{color}, id{-1}, value{value}, is_taken{false}, has_not_moved{true} {}

Piece::~Piece() {}

void Piece::set_cell(Cell *c) {
    cell = c;
    // this->cell->notify();
}

Cell* Piece::get_cell() {
    return cell;
}

int Piece::get_color() { return color; }

int Piece::get_value() { return value; }

int Piece::get_id() { return id; }

void Piece::set_id(int i) { id = i; }

void Piece::set_is_taken() {
    is_taken = true;
}

void Piece::set_has_not_moved() {
    has_not_moved = false;
}

bool Piece::get_has_not_moved() {
    return has_not_moved;
}

// int Piece::get_status() { return status; }

bool Piece::valid_move(Cell *cell) {
    if (valid_moves.count(cell)) {
        return true;
    }
    return false;
}

void Piece::print_piece() {
    print();
}

void Piece::create_valid_moves() {
    vector<vector<Cell*>> cur_board = get_board()->get_ref_board();
    Cell *cur_cell = get_cell();
    int cur_row = cur_cell->get_row();
    int cur_col = cur_cell->get_col();
    generate_moves(cur_board, cur_cell, cur_row, cur_col);
}

// modify valid moves
void Piece::modify_valid_moves(Cell *cell, int i) {
    valid_moves[cell] = i;
}

// get the board
Board *Piece::get_board() {
    return board;
}

// set the board
void Piece::set_board(Board *b) {
    board = b;
} 
