#include "knight.h"

using namespace std;

// constructor
Knight::Knight(int color) : Piece{color} {}

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
