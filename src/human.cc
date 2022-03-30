#include "human.h"
#include "player.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include "board.h"
#include <memory>
using namespace std;

const int off_set = 48;

void Human::make_move() {
    // gets the input from user to move pieces in the cells
    string input;
    while (cin >> input) {
        string command;
        if (input == "move"){
            getline(cin, command);
            istringstream iss(command);
            string pos1;
            string pos2;
            // E7 
            // gets the two positions (inital, final)
            iss>>pos1;
            iss>>pos2;
            char coli = pos1[0] - off_set;
            char rowi = pos1[1];

            char colf = pos2[0] - off_set;
            char rowf = pos2[1];

            try {
            // we also need to know what piece is moving 
            unique_ptr<Piece> p = the_board[coli,rowi].get_piece();

            // removes the piece from the board in the specific cell
            the_board[coli,rowi].remove_piece();

            // sets the piece in the board at col,row
            the_board[colf,rowf].set_piece(p);
            }
            catch ( out_of_range r) {
                cerr << "Range error" << r.what() << endl;
            }
        }
    }
}