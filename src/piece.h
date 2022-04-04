#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Cell;

class Piece {
    Cell *cell;
    int color; // 0 is black 1 is white
    int id;
    int value;
    bool is_taken;
    // int status;
    // std::vector<std::unique_ptr<Cell>> valid_moves;
    bool has_not_moved;
  public:
    // Piece(Cell *cell, int color, int value, std::vector<std::unique_ptr<Cell>> valid_moves, std::string name);
    Piece(int color, int value);
    virtual ~Piece();
    Cell *get_cell();
    void set_cell(Cell *cell);
    int get_color();
    int get_value();
    void set_is_taken();
    // bool valid_move(Cell* cell);
    int get_status();
    int get_id();
    void set_id(int i);
    // virtual void create_valid_moves() = 0;
    // print out piece
    virtual void print() = 0;
};

#endif
