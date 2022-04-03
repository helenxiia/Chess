#include "textdisplay.h"
#include "cell.h"
#include "piece.h"

using namespace std;

// constructor
TextDisplay::TextDisplay(Board *board) : board{board} {}

// print out the board
void TextDisplay::print_board(const string &gametype) {
    vector<vector<Cell*>> gameboard = board->get_ref_board();
    if (gametype == "chess") { // if chess game
        // print out the column names
        cout << "   "; // padding
        for (int i = 0; i < 8; ++i) {
            cout << "  " << char(i + 97) << "  ";
        }
        cout << endl;
        // print out the grid
        for (int i = 0; i < 8; ++i) {
            cout << "   "; // padding
            for (int j = 0; j < 8; ++j) {
                cout << "-----";
            }
            cout << endl;
            // print out row name
            cout << " " << i + 1 << " ";
            for (int j = 0; j < 8; ++j) {
                auto cell = gameboard[i][j];
                cout << "| ";
                if (cell->get_piece() == nullptr) {
                    if ((i + j) % 2 == 0) {
                        cout << "\u25A0";
                    } else {
                        cout << "\u25A1";
                    }
                } else {
                    cell->get_piece()->print();
                }
                cout << " |";
            }
            cout << endl;
        }
        cout << "   "; // padding
        for (int i = 0; i < 8; ++i) {
            cout << "-----";
        }
        cout << endl;
    }
}