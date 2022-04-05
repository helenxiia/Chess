#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <unordered_map>

#include "subject.h"

class Cell;
class Board;

class Piece : public Subject { // pieces are observed by cells 
    Cell *cell;
    int color; // 0 is black 1 is white
    int id;
    int value;
    bool is_taken;
    int threats;
    std::unordered_map<Cell*, int> valid_moves;
    bool has_not_moved;
    // board that piece is on
    Board *board;
    // get all valid moves for a piece
    virtual void generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col) = 0;
    // print out piece
    virtual void print() = 0;
  public:
    // constructor and destructor
    Piece(int color, int value);
    virtual ~Piece();
    // get and set cell
    Cell *get_cell();
    void set_cell(Cell *cell);
    // get and set values of piece
    int get_color();
    int get_value();
    int get_threats();
    void update_threats();
    int get_id();
    void set_id(int i);
    void set_has_not_moved();
    bool get_has_not_moved();
    // move is valid
    bool valid_move(Cell* cell);
    // print piece
    void print_piece();
    // create valid moves
    void create_valid_moves();
    // modify valid moves
    void modify_valid_moves(Cell *cell, int i);
    // get the board
    Board *get_board();
    // set the board
    void set_board(Board *b);
    // get random valid move
    Cell *get_random_valid_move();
    // get number of valid moves
    int get_num_valid_moves();
    // notify observers
    void notifyObservers();
};

#endif
