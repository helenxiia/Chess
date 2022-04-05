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
    // get initial cell
    Cell* get_init_cell();
    // get final cell
    Cell* get_final_cell();
    // get current and last piece
    Piece *get_cur_piece();
    Piece *get_last_piece();
    // get turn
    int get_turn();
    void print();
};

#endif
