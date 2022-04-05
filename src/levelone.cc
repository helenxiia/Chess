
#include "computer.h"
#include "levelone.h"
#include "piece.h"
#include "cell.h"
#include "board.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

const int letter_off_set = 96;

LevelOne::LevelOne (int side): Computer{side} {};

vector<int> LevelOne::make_move() {
    //cout << "starting make_move in computer1";
    // get the board 
    vector<vector<Cell*>> cur_board = get_board()->get_ref_board();

    // get piece already owned by side
    Piece *start_piece = get_random_piece();
    while (start_piece->num_valid_moves() == 0) {
        start_piece = get_random_piece();
    }

    Cell *start_cell = start_piece->get_cell();
    int randrowi = start_cell->get_row();
    int randcoli = start_cell->get_col();

    // get a random valid move
    //cout << "getting random valid move" << endl;
    Cell *random_move = start_piece->get_random_valid_move();

    while(start_piece->get_move_value(random_move) == 3) {
        random_move = start_piece->get_random_valid_move();
    }

    int randrowf = random_move->get_row();
    int randcolf = random_move->get_col();

    cout << "i got all the stuff";
    start_piece->print_piece();
    cout << endl;
    cout << randrowi << randcoli;
    cout << randrowf <<randcolf;
    
    
    try {
        // removes the piece from the board in the specific cell
        start_cell->remove_piece();

        // sets the piece in the board at col, row
        random_move->set_piece(start_piece);
        start_piece->set_cell(random_move);
        start_piece->set_has_not_moved(); // piece has moved

        // return vector of integers
        // returns {inital row, inital column, final row, final column, id of piece, id of last piece} 
        return vector<int>{randrowi, randcoli, randrowf, randcolf, start_piece->get_id(), -1};
        
        } catch (const out_of_range &r) {
                cerr << "Invalid Move: " << r.what() << endl;
                make_move();
        }
        
    return vector<int>();
}

LevelOne::~LevelOne(){};