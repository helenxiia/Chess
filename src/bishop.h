#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
  public:
    Bishop(int color);
    ~Bishop();
    void print();
};

#endif
