#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {
    // inherts all of the fields from player
    public:
    Human(int side);
    ~Human();
    void make_move(); 

};
#endif