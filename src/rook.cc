#include "rook.h"

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

}
