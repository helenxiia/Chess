#include "knight.h"
#include "cell.h"

using namespace std;

// constructor
Knight::Knight(int color) : Piece{color, 3} {}

// destructor
Knight::~Knight() {}

// print
void Knight::print() {
    if (get_color()) {
        cout << "n";
    } else {
        cout << "N";
    }
}

// create valid moves
void Knight::generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col) {
    // check all spots around knight
    vector<Cell*> possible_moves;
    if (row + 1 < 8) {
        if (col + 2 < 8) possible_moves.emplace_back(board[row + 1][col + 2]);
        if (col - 2 >= 0) possible_moves.emplace_back(board[row + 1][col - 2]);

        if (row + 2 < 8) {
            if (col + 1 < 8) possible_moves.emplace_back(board[row + 2][col + 1]);
            if (col - 1 >= 0) possible_moves.emplace_back(board[row + 2][col - 1]);
        }
    }
    if (row - 1 >= 0) {
        if (col + 2 < 8) possible_moves.emplace_back(board[row - 1][col + 2]);
        if (col - 2 >= 0) possible_moves.emplace_back(board[row - 1][col - 2]);

        if (row - 2 >= 0) {
            if (col + 1 < 8) possible_moves.emplace_back(board[row - 2][col + 1]);
            if (col - 1 >= 0) possible_moves.emplace_back(board[row - 2][col - 1]);
        }
    }

    for (auto move : possible_moves) {
        Piece *cell_piece = move->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() != get_color()) { // if piece is not the same color, blocked
                modify_valid_moves(move, 2);
            } else {
                modify_valid_moves(move, 3);
            }
        } else {
            modify_valid_moves(move, 1); // add to valid moves
        }
    }
}

void Knight::unique_status() {}

bool Knight::get_unique_status() { return false; }
