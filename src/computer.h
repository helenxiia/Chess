#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
    // inherts all of the fields from player
    public:
    Computer(int side);
    ~Computer();
    void make_move(); 

};
#endif