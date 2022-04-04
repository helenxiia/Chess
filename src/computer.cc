#include "computer.h"
#include "player.h"

using namespace std;

// constructor
Computer::Computer(int side) : Player{side} {}

// destructor
Computer::~Computer() {}

vector<int> Computer::make_move() {
    return vector<int>();
}