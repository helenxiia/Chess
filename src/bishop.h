#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
  public:
    Bishop(int color);
    ~Bishop();
    void print();
    void generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col);
};

#endif
