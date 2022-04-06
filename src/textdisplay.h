#ifndef TEXTDISPLAY_H_
#define TEXTDISPLAY_H_

#include <iostream>
#include <sstream>

#include "board.h"

class TextDisplay {
    // chess board to display
    Board *board; 
  public:
    TextDisplay(Board *board); // constructor
    void print_board(const std::string &gametype, int threats); // print out the board
};

#endif
