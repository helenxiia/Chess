#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
  public:
    Rook(int color);
    ~Rook();
    void print();
    void generate_moves();
};

#endif
