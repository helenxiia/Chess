#include "pawn.h"

using namespace std;

// constructor
Pawn::Pawn(int color) : Piece{color, 1} {}

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
void Pawn::generate_moves() {

}
