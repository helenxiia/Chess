#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
  public:
    Bishop(Cell *cell, int color);
    void print();
};

#endif
