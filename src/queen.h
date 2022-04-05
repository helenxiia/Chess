#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
  public:
    Queen(int color);
    ~Queen();
    void print();
    void generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col);
    void unique_status();
    bool get_unique_status();
};

#endif
