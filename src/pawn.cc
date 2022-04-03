#include "pawn.h"

using namespace std;

// constructor
Pawn::Pawn(int color) : Piece{color} {}

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
