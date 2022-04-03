#include <memory>
#include <vector>
#include "piece.h"

using namespace std;

// Piece::Piece(Cell *cell, int color 
//             // int value, vector<unique_ptr<Cell>> valid_moves, string name
//             ) : 
//             cell{cell}, color{color}, 
//             // value{value}, valid_moves{valid_moves}, name{name} 
//             is_taken{false}, has_not_moved{true} {}

Piece::Piece(int color) : cell{nullptr}, color{color}, is_taken{false}, has_not_moved{true} {}

Piece::~Piece() {}

void Piece::set_cell(Cell *c) {
    cell = c;
    // this->cell->notify();
}

Cell* Piece::get_cell() {
    return cell;
}

int Piece::get_color() { return color; }

// int Piece::get_value() { return value; }

// string Piece::get_name() { return name; }

void Piece::set_is_taken() {
    is_taken = true;
    
}

// int Piece::get_status() { return status; }

// bool Piece::valid_move(unique_ptr<Cell> c) {
//     for (int i = 0; i < valid_moves.size(); i++) {
//         if (valid_moves[i] == c) {
//             return true;
//         }
//     } return false;
// }





