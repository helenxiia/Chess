#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
  public:
    King(int color);
    ~King();
    void print();
};

#endif
