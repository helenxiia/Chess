#include "bishop.h"

using namespace std;

// constructor
Bishop::Bishop(int color) : Piece{color, 4} {}

// destructor
Bishop::~Bishop() {}

// print
void Bishop::print() {
    if (get_color()) {
        cout << "b";
    } else {
        cout << "B";
    }
}