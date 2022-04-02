#ifndef PIECE_H
#define PIECE_H

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"
#include "cell.h"

class Cell;

class Piece {
    // std::unique_ptr<Cell> cell;
    // int color; // 0 is black 1 is white
    // bool is_taken;
    // int value;
    // int status;
    // std::string name;
    // std::vector<std::unique_ptr<Cell>> valid_moves;
    // bool has_not_moved;
  public:
    // Piece(std::unique_ptr<Cell> cell, int color, int value, std::vector<std::unique_ptr<Cell>> valid_moves, std::string name);
    // std::unique_ptr<Cell> get_cell();
    // void set_cell(std::unique_ptr<Cell> cell);
    // int get_color();
    // int get_value();
    // void set_is_taken();
    // bool valid_move(std::unique_ptr<Cell>);
    // int get_status();
    // virtual void create_valid_moves();
};

#endif
