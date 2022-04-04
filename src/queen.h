#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
  public:
    Queen(int color);
    ~Queen();
    void print();
    void generate_moves();
};

#endif
