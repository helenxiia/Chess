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
    vector<vector<Cell*>> b = get_board()->get_ref_board();
    // check for castling
    if (get_has_not_moved()) {
        if (get_color() == 0) { // white
            // kings side
            if (b[7][5]->get_piece() == nullptr && b[7][5]->get_threats(1) == 0 &&
                b[7][6]->get_piece() == nullptr && b[7][6]->get_threats(1) == 0 &&
                b[7][7]->get_piece()->get_has_not_moved()) {
                    modify_valid_moves(b[7][6], 4);
                }
            // queens side
            if (b[7][1]->get_piece() == nullptr && b[7][1]->get_threats(1) == 0 &&
                b[7][2]->get_piece() == nullptr && b[7][2]->get_threats(1) == 0 &&
                b[7][3]->get_piece() == nullptr && b[7][3]->get_threats(1) == 0 &&
                b[7][0]->get_piece()->get_has_not_moved()) {
                    modify_valid_moves(b[7][2], 4);
                }
        } else if (get_color() == 1) { // black
            // kings side
            if (b[0][5]->get_piece() == nullptr && b[0][5]->get_threats(0) == 0 &&
                b[0][6]->get_piece() == nullptr && b[0][6]->get_threats(0) == 0 &&
                b[0][7]->get_piece()->get_has_not_moved()) {
                    modify_valid_moves(b[0][6], 4);
                }
            // queens side
            if (b[0][1]->get_piece() == nullptr && b[0][1]->get_threats(0) == 0 &&
                b[0][2]->get_piece() == nullptr && b[0][2]->get_threats(0) == 0 &&
                b[0][3]->get_piece() == nullptr && b[0][3]->get_threats(0) == 0 &&
                b[0][0]->get_piece()->get_has_not_moved()) {
                    modify_valid_moves(b[0][2], 4);
                }
        }
    }
}

void King::unique_status() {
    castle = !castle;
}

bool King::get_unique_status() {
    return castle;
}
