#include "king.h"
#include "cell.h"
#include "board.h"

using namespace std;

// constructor
King::King(int color) : Piece{color, 10}, castle{false} {}

// destructor
King::~King() {}

// print
void King::print() {
    if (get_color()) {
        cout << "k";
    } else {
        cout << "K";
    }
}

// create valid moves
void King::generate_moves(std::vector<std::vector<Cell*>> board, Cell *cell, int row, int col) {
    // check all spots around king
    vector<Cell*> possible_moves;
    if (row + 1 < 8) {
        if (col + 1 < 8) possible_moves.emplace_back(board[row + 1][col + 1]);
        if (col - 1 >= 0) possible_moves.emplace_back(board[row + 1][col - 1]);
        possible_moves.emplace_back(board[row + 1][col]);
    }
    if (row - 1 >= 0) {
        if (col + 1 < 8) possible_moves.emplace_back(board[row - 1][col + 1]);
        if (col - 1 >= 0) possible_moves.emplace_back(board[row - 1][col - 1]);
        possible_moves.emplace_back(board[row - 1][col]);
    }
    if (col + 1 < 8) possible_moves.emplace_back(board[row][col + 1]);
    if (col - 1 >= 0) possible_moves.emplace_back(board[row][col - 1]);

    for (auto move : possible_moves) {
        Piece *cell_piece = move->get_piece();
        if (cell_piece) { // there is a piece on the cell
            if (cell_piece->get_color() != get_color()) { // if piece is not the same color, not blocked
                int c = get_color();
                if (c == 0) {
                    if (move->get_threats(1) == 0) { // does not move into a check
                        modify_valid_moves(move, 2); // add as a valid move
                    }
                } else if (c == 1) {
                    if (move->get_threats(0) == 0) { // does not move into a check
                        modify_valid_moves(move, 2); // add as a valid move
                    }
                }
            } else {
                int c = get_color();
                if (c == 0) {
                    if (move->get_threats(1) == 0) { // does not move into a check
                        modify_valid_moves(move, 3); // add as a valid move
                    }
                } else if (c == 1) {
                    if (move->get_threats(0) == 0) { // does not move into a check
                        modify_valid_moves(move, 3); // add as a valid move
                    }
                }
            }
        } else {
            int c = get_color();
            if (c == 0) {
                if (move->get_threats(1) == 0) { // does not move into a check
                    modify_valid_moves(move, 1); // add as a valid move
                }
            } else if (c == 1) {
                if (move->get_threats(0) == 0) { // does not move into a check
                    modify_valid_moves(move, 1); // add as a valid move
                }
            }
        }
    }
}

