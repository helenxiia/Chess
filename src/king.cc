#include "king.h"

using namespace std;

// constructor
King::King(int color) : Piece{color} {}

// destructor
King::~King() {}

// print
void King::print() {
    if (get_color()) {
        cout << "k";
    } else {
        cout << "K";
    }
}