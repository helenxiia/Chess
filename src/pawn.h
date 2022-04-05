#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
    bool promoted;
    bool prev_twostep; // just made a twostep
  public:
    Pawn(int color);
    ~Pawn();
    void print();
    void generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col);
    void unique_status();
    bool get_unique_status();
};

#endif
