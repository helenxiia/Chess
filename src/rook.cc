#include "rook.h"

using namespace std;

// constructor
Rook::Rook(int color) : Piece{color} {}

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