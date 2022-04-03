#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Piece;
class Board;

class Player {
    // 0 or 1, black or white, can be a string if we want
    // correlates to Board::turn variable
    int side;

    // pieces owned by a player
    std::vector<Piece*> owned_pieces;

    // board that player has
    Board *board;

    public:
    void set_board(Board *b);
    Board *get_board();
    Player(int side);
    virtual ~Player();
    virtual void make_move() = 0;
    // void notify();
};

#endif
