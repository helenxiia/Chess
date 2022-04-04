#include "knight.h"

using namespace std;

// constructor
Knight::Knight(int color) : Piece{color, 3} {}

// destructor
Knight::~Knight() {}

// print
void Knight::print() {
    if (get_color()) {
        cout << "n";
    } else {
        cout << "N";
    }
}

// create valid moves
void Knight::generate_moves() {

}