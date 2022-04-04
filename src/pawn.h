#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
    bool prev_twostep; // just made a twostep
  public:
    Pawn(int color);
    ~Pawn();
    void print();
    void generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col);
};

#endif
