#include "bishop.h"

using namespace std;

// constructor
Bishop::Bishop(Cell *cell, int color) : Piece{cell, color} {}

// print
void Bishop::print() {
    if (get_color()) {
        cout << "B";
    } else {
        cout << "b";
    }
}