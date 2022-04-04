#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
  public:
    Pawn(int color);
    ~Pawn();
    void print();
    void generate_moves();
};

#endif
