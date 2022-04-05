#include <memory>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <map>
#include "piece.h"
#include "board.h"
#include "cell.h"

using namespace std;

Piece::Piece(int color, int value) : cell{nullptr}, color{color}, id{-1}, value{value}, 
                                    valid_moves{unordered_map<Cell*, int>()}, has_not_moved{true}, board{nullptr} {}

Piece::~Piece() {
    // detach all cells in board
    if (board) {
        vector<vector<Cell*>> all_cells = board->get_ref_board();
        for (auto row : all_cells) {
            for (auto cell : row) {
                this->detach(cell);
            }
        }
    }
    // detach from board
    this->detach(board);
}

void Piece::set_cell(Cell *c) {
    cell = c;
    // this->cell->notify();
}

Cell* Piece::get_cell() {
    return cell;
}

int Piece::get_color() { return color; }

int Piece::get_value() { return value; }

int Piece::get_id() { return id; }

void Piece::set_id(int i) { id = i; }

void Piece::set_has_not_moved() {
    has_not_moved = false;
}

bool Piece::get_has_not_moved() {
    return has_not_moved;
}

int Piece::valid_move(Cell *cell) {
    if (valid_moves.count(cell)) {
        return valid_moves.at(cell);
    }
    return 0;
}

std::unordered_map<Cell*, int> Piece::get_valid_moves() {
    return valid_moves;
}

void Piece::print_piece() {
    print();
}

void Piece::create_valid_moves() {
    valid_moves.clear();
    vector<vector<Cell*>> cur_board = get_board()->get_ref_board();
    Cell *cur_cell = get_cell();
    int cur_row = cur_cell->get_row();
    int cur_col = cur_cell->get_col();
    generate_moves(cur_board, cur_cell, cur_row, cur_col);
}

// modify valid moves
void Piece::modify_valid_moves(Cell *cell, int i) {
    valid_moves[cell] = i;
}

// number of valid moves
int Piece::num_valid_moves() {
    int count = 0;
    for (auto move: valid_moves) {
        if(move.second != 3) {
            ++count;
        }
    }
    return count;
}

// get the board
Board *Piece::get_board() {
    return board;
}

// set the board
void Piece::set_board(Board *b) {
    board = b;
    // attach to all cells in board
    vector<vector<Cell*>> all_cells = board->get_ref_board();
    for (auto row : all_cells) {
        for (auto cell : row) {
            this->attach(cell);
        }
    }
    // attach to board
    this->attach(board);
} 

// get random valid move

Cell *Piece::get_random_valid_move(){
    auto it = valid_moves.begin();
    print_piece();
    cout<<endl;
    cout << valid_moves.size() << endl;
    cout <<rand() % valid_moves.size()<< endl;
    std::advance(it, rand() % valid_moves.size());
    Cell *random_move = it->first;
    while(it->second == 3) {
        it = valid_moves.begin();
    std::advance(it, rand() % valid_moves.size());
    }
    random_move = it->first;
    return random_move;
}


// check if a move can capture
Cell *Piece::get_capture() {
    for (auto move: valid_moves) {
        if (move.second == 2) { // 2 = will capture
        return move.first;
        }
    }
    return nullptr;
}

// check if it check
Cell *Piece::get_check() {
    for ( auto move: valid_moves) {
        if (move.second == -1) { // -1 = will check
        return move.first;
        }
    }
    return nullptr;
}


// notify observers
void Piece::notifyObservers() {
    // notify all cells
    vector<vector<Cell*>> all_cells = board->get_ref_board();
    for (auto row : all_cells) {
        for (auto cell : row) {
            cell->notify();
        }
    }
    board->notify();
}

void Piece::create_unique_status() {
    unique_status();
}

bool Piece::receive_unique_status() {
    return get_unique_status();
}
