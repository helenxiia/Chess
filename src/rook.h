#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
  public:
    Rook(int color);
    ~Rook();
    void print();
    void generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col);
};

#endif
