#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Cell;

class Piece {
    Cell *cell;
    int color; // 0 is black 1 is white
    bool is_taken;
    // int value;
    // int status;
    // std::string name;
    // std::vector<std::unique_ptr<Cell>> valid_moves;
    bool has_not_moved;
  public:
    // Piece(Cell *cell, int color, int value, std::vector<std::unique_ptr<Cell>> valid_moves, std::string name);
    Piece(Cell *cell, int color);
    virtual ~Piece() = 0;
    Cell *get_cell();
    void set_cell(Cell *cell);
    int get_color();
    int get_value();
    void set_is_taken();
    // bool valid_move(std::unique_ptr<Cell>);
    int get_status();
    virtual void create_valid_moves() = 0;
    // print out piece
    virtual void print() = 0;
};

#endif
