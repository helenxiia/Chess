#include "human.h"
#include "player.h"
#include "board.h"
#include "cell.h"
#include "piece.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdexcept>
#include <memory>
using namespace std;

const int letter_off_set = 96;

// constructor
Human::Human(int side) : Player{side} {}

// destructor
Human::~Human() {}

vector<int> Human::make_move() {
    // gets the input from user to move pieces in the cells
    string input;
    vector<vector<Cell*>> cur_board = get_board()->get_ref_board();
    
    while (getline(cin, input)) {
        istringstream iss(input);
        string command;
        iss >> command;
        if (command == "move") {
            string pos1;
            string pos2;
            // E7 
            // gets the two positions (inital, final)
            iss >> pos1;
            iss >> pos2;
            int coli = pos1[0] - letter_off_set - 1;
            int rowi = 8 - stoi(pos1.substr(1));

            int colf = pos2[0] - letter_off_set - 1;
            int rowf = 8 - stoi(pos2.substr(1));

            try {
                if (coli == colf && rowi == rowf) throw out_of_range("Cannot Move To Same Cell");

                // we also need to know what piece is moving 
                Piece *p = cur_board.at(rowi).at(coli)->get_piece();
                if (p == nullptr) throw out_of_range("Cell Has No Piece");
                if (!own(p)) throw out_of_range("You Do Not Own That Piece");

                // removes the piece from the board in the specific cell
                cur_board.at(rowi).at(coli)->remove_piece();

                // sets the piece in the board at col,row
                cur_board.at(rowf).at(colf)->set_piece(p);
                // return vector
                return vector<int>{rowi, coli, rowf, colf, p->get_id(), -1};
                break;
            } catch (const out_of_range &r) {
                cerr << "Invalid Move: " << r.what() << endl;
            }
        } else if (command == "resign") {
            set_resign();
            return vector<int>{-1};
        } else {
            cerr << "Invalid Move: Please Enter Instruction 'move (row1, col1) (row2,col2)'" << endl;
        }
    }
    return vector<int>();
}