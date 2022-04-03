#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
  public:
    Knight(int color);
    ~Knight();
    void print();
};

#endif
