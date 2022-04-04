#include "queen.h"

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
void Queen::generate_moves() {

}
