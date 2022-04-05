#ifndef MOVE_H_
#define MOVE_H_

// forward declares
class Piece;
class Cell;

class Move {
    // change in Pieces
    // occurs during Pawn promotion and capturing
    Piece *last_piece;
    Piece *current_piece;
    // change in Cells
    Cell *initial_cell;
    Cell *final_cell;
    // the turn number
    int turn;
  public:
    // constructor and destructor
    Move(Piece *last_piece, Piece *current_piece, Cell *initial_cell, Cell *final_cell, int turn);
    ~Move();
    // get initial row and column
    int get_init_row();
    int get_init_col();
    // get final row and column
    int get_fin_row();
    int get_fin_col();
    // get current and last piece
    Piece *get_cur_piece();
    Piece *get_last_piece();
    void print();
};

#endif
