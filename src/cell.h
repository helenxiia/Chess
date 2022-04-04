#ifndef CELL_H_
#define CELL_H_

#include <map>
#include <vector>
#include "observer.h"

// forward declare for now
class Piece; // there is a circular declaration going on with Piece and Cell, not sure what will happen rn

class Cell : public Observer { // cells observe all pieces
    Piece *piece;
    int row;
    int col;
    int status;
    std::map<int, int> threats;
    std::vector<Piece*> all_pieces;
  public:
    // constructor and destructor
    Cell(int row, int col);
    ~Cell();
    Piece* get_piece(); // gets piece
    void set_piece(Piece *p); // sets piece
    void remove_piece(); // removes piece, only used in setup mode
    void set_all_pieces(std::vector<Piece*> ap);
    int get_row(); // gets row
    int get_col(); // gets col
    int get_status(); // gets status
    int get_threats(int player); // gets number of threats based on player
    // notified by pieces
    void notify();
};

#endif
