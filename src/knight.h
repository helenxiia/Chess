#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
  public:
    Knight(int color);
    ~Knight();
    void print();
    void generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col);
};

#endif
