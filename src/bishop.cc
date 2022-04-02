#include "bishop.h"

using namespace std;

// constructor
Bishop::Bishop(int color) : Piece{color} {}

// destructor
Bishop::~Bishop() {}

// print
void Bishop::print() {
    if (get_color()) {
        cout << "B";
    } else {
        cout << "b";
    }
}