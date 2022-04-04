#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

// abstract subclass of player
class Computer : public Player {
    // inherts all of the fields from player
    public:
    // pure virtual class, cannot be called in this abstract class
    // we need this class to implement the different computer levels (1-4)
    virtual void make_move() =0;  
    

};
#endif