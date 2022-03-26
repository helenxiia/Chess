#ifndef CHESS_H_
#define CHESS_H_

#include <map>

#include "board.h"

class Chess : public Board {
    int checkmate; // -1 if no checkmate, 0 if white is in checkmate, 1 if black is in checkmate etc.
    int check; // -1 if no check, 0 if white is in check, 1 if black is in check etc
    bool stalemate; // returns whether or not game is in stalemate
  public:
    // constructor and destructor
    Chess(); 
    ~Chess();
    // 
};

#endif
