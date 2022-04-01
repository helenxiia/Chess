#ifndef CHESS_H_
#define CHESS_H_

#include <memory>

#include "board.h"
#include "textdisplay.h"

class Chess : public Board {
    int checkmate; // -1 if no checkmate, 0 if white is in checkmate, 1 if black is in checkmate etc.
    int check; // -1 if no check, 0 if white is in check, 1 if black is in check etc
    bool stalemate; // returns whether or not game is in stalemate
  public:
    // constructor and destructor
    Chess(); 
    ~Chess();
    // initialize chess board
    void init();
    void create_players(std::vector<std::string> player_names);
    // game is over when checkmate or stalemate is true
    bool game_over();
    // setup the chess board
    void setup();
    // Chess must observe its Pieces for check, checkmate, stalemate
    void notify();
};

#endif
