#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

// abstract subclass of player
class Computer : public Player {
    // inherts all of the fields from player
    public:
    Computer(int side);
    ~Computer();
    std::vector<int> make_move() = 0; 
    //Piece *get_existing_piece();
    bool valid_computer_move(Piece *init, Piece *final);


};
#endif