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
    // whether or not they resigned
    bool resign;
    // move piece
    virtual void make_move() = 0;
  public:
    void set_board(Board *b);
    Board *get_board();
    Player(int side);
    virtual ~Player();
    void move();
    // get and set resign
    void set_resign();
    bool get_resign();
    // void notify();
    // add piece
    void add_piece(Piece *piece);
    // get pieces
    std::vector<Piece*> get_pieces();
    // check if piece is owned
    bool own(Piece *piece);
};

#endif
