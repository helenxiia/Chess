#include "computer.h"
#include "leveltwo.h"
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

LevelTwo::LevelTwo (int side): Computer{side} {};

vector<int> LevelTwo::make_move() { 
    // get the board 
    vector<vector<Cell*>> cur_board = get_board()->get_ref_board();
    Piece *start_piece;
    Cell *move;

    vector<Piece*> current_pieces;

    // iterate over the board to get current pieces (gets rid of ate up pieces)
    for ( int i = 0; i < 8; i ++) {
        for ( int j = 0; j < 8; j ++) {
            Piece *my_piece = cur_board.at(i).at(j)->get_piece();
        if ( my_piece != nullptr && my_piece->get_color() == side){
            current_pieces.emplace_back(my_piece);
            //my_piece->print_piece();
            }
        }
    }

    bool found = false;
    // get piece already owned by side
    for (auto piece : current_pieces ) {
        if (piece->get_capture() != nullptr) { // checks capture
            start_piece = piece;
            move = piece->get_capture();
             found = true;
            break;
        } else if (piece->get_check() != nullptr) { // checks check
            start_piece = piece;
            move = piece->get_check();
             found = true;
            break;
        } 
    }
    if (!found) {
     // if no capture or check, it just gets a random valid move
        int random = rand() % current_pieces.size();
        start_piece = current_pieces.at(random);

        // get piece already owned by side
        while (start_piece->num_valid_moves() == 0) {
            random = rand() % current_pieces.size();
            start_piece = current_pieces.at(random);
        }
        move = start_piece->get_random_valid_move();
        while(start_piece->get_move_value(move) == 3) {
            move = start_piece->get_random_valid_move();
        }
    }

    Cell *start_cell = start_piece->get_cell();
    int randrowi = start_cell->get_row();
    int randcoli = start_cell->get_col();
    
    int randrowf = move->get_row();
    int randcolf = move->get_col();
    
    try {
        // removes the piece from the board in the specific cell
        start_cell->remove_piece();

        // sets the piece in the board at col, row
        move->set_piece(start_piece);
        start_piece->set_cell(move);
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

LevelTwo::~LevelTwo(){};