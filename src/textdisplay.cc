#include "textdisplay.h"
#include "cell.h"

using namespace std;

// constructor
TextDisplay::TextDisplay(Board *board) : board{board} {}

// print out the board
void TextDisplay::print_board() {
    vector<vector<Cell*>> gameboard = board->get_board();
    // print out the column names
    cout << "   "; // padding
    for (int i = 0; i < (int) gameboard.at(0).size(); ++i) {
        cout << "  " << char(i + 97) << "  ";
    }
    cout << endl;
    // print out the grid
    for (int i = 0; i < (int) gameboard.size(); ++i) {
        cout << "   "; // padding
        for (auto cell : gameboard.at(i)) {
            cout << "-----";
        }
        cout << endl;
        // print out row name
        cout << " " << i << " ";
        for (int j = 0; j < (int) gameboard.at(i).size(); ++j) {
            auto cell = gameboard[i][j];
            cout << "|";
            if (cell->get_piece() == nullptr) {
                if ((i + j) % 2 == 0) {
                    cout << " " << "\u25A0" << " ";
                } else {
                    cout << " " << "\u25A1" << " ";
                }
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "   "; // padding
    for (auto cell : gameboard.at(gameboard.size() - 1)) {
        cout << "-----";
    }
    cout << endl;
}