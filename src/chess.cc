#include "chess.h"
#include "cell.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

#include "human.h"
#include "computer.h"
#include "levelone.h"
#include "leveltwo.h"


#include <stdexcept>
#include <unordered_map>

using namespace std;

// constructor
Chess::Chess() : Board{}, checkmate{-1}, check{-1}, stalemate{false}, 
                    num_of{vector<int>()} {}

// destructor
Chess::~Chess() {}

// initialize a chess board
void Chess::init() {
    while (num_of.size() < 12) num_of.emplace_back(0);
    // set the_board to an 8x8
    set_board(8, 8);
    // set king
    set_piece(7, 4, new King(0)); // white
    num_of.at(0) = 1; // 1 white king
    set_piece(0, 4, new King(1)); // black
    num_of.at(6) = 1; // 1 black king
    // set pawns
    for (int i = 0; i < 8; ++i) { // white
        set_piece(6, i, new Pawn(0));
    }
    num_of.at(5) = 8; // 8 white pawns 
    for (int i = 0; i < 8; ++i) { // black
        set_piece(1, i, new Pawn(1));
    }
    num_of.at(11) = 8; // 8 black pawns
    // set bishops
    set_piece(7, 2, new Bishop(0)); // white
    set_piece(7, 5, new Bishop(0)); // white
    num_of.at(4) = 2; // 2 white bishops
    set_piece(0, 2, new Bishop(1)); // black
    set_piece(0, 5, new Bishop(1)); // black
    num_of.at(10) = 2; // 2 black bishops
    // set knights
    set_piece(7, 1, new Knight(0)); // white
    set_piece(7, 6, new Knight(0)); // white
    num_of.at(3) = 2; // 2 white knights
    set_piece(0, 1, new Knight(1)); // black
    set_piece(0, 6, new Knight(1)); // black
    num_of.at(9) = 2; // 2 black knights
    // set rooks
    set_piece(7, 0, new Rook(0)); // white
    set_piece(7, 7, new Rook(0)); // white
    num_of.at(2) = 2; // 2 white rooks
    set_piece(0, 0, new Rook(1)); // black
    set_piece(0, 7, new Rook(1)); // black
    num_of.at(8) = 2; // 2 black rooks
    // set queens
    set_piece(7, 3, new Queen(0)); // white
    num_of.at(1) = 1; // 1 white queen
    set_piece(0, 3, new Queen(1)); // black
    num_of.at(7) = 1; // 1 black queen;
    // set all pieces
    all_pieces  = get_ref_pieces();
    // text display
    TextDisplay *text_display = get_td();
    text_display->print_board("chess");
}

// create players
void Chess::create_players(vector<string> player_names) {
    int side = 0;
    for (auto player : player_names) {
        if (player == "human") { // Human
            Human *new_player = new Human(side);
            add_player(new_player);
        } else if (player == "computer1"){ // Computer 1
            LevelOne *new_player = new LevelOne(side);
            add_player(new_player);
        }else if (player == "computer2"){ // Computer 1
            LevelTwo *new_player = new LevelTwo(side);
            add_player(new_player);
        }/*else if (player == "computer3"){ // Computer 1
            LevelOne *new_player = new LevelOne(side);
            add_player(new_player);
        }else if (player == "computer4"){ // Computer 1
            LevelOne *new_player = new LevelOne(side);
            add_player(new_player);
        } */else {

        }
    }
}

// check if game is over
bool Chess::game_over() {
    if (checkmate != -1) { // checkmate
        // check for state
        if (checkmate == 0) {
            cout << "White is in checkmate!" << endl;
        } else if (checkmate == 1) {
            cout << "Black is in checkmate!" << endl;
        }
        for (int i = 0; i < get_players_size(); ++i) {
            if (i != checkmate) { // not the player that got checkmated
                modify_score(i, 1); // add 1 to score
            }
        }
        get_winner(checkmate);
        return true;
    } else if (stalemate) { // stalemate
        // NOT SURE IF THIS IS HOW MULTIPLAYER CHESS POINTS WORK
        for (int i = 0; i < get_players_size(); ++i) {
            modify_score(i, 0.5); // everyone gets half a point
        }
        cout << "Stalemate" << endl;
        return true;
    } else {
        int res = resign();
        if (res != -1) {
            for (int i = 0; i < get_players_size(); ++i) {
                if (i != res) { // not the player that got checkmated
                    modify_score(i, 1); // add 1 to score
                }
            }
            get_winner(res);
            return true;
        }
        return false;
    }
}

// check if game state is valid
int Chess::state_valid() {
    if (check != -1) {
        if (check == 0) {
            cout << "White is in Check!" << endl;
        } else if (check == 1) {
            cout << "Black is in Check!" << endl;
        }
    }
    return check;
}

// get winner
void Chess::get_winner(int lose) {
    switch(lose) {
        case 0:
            cout << "Black Won!" << endl;
            break;
        case 1:
            cout << "White Won!" << endl;
            break;
    }
}

//-- Helper --//
vector<int> num_pos(string pos) {
    int row = 8 - stoi(pos.substr(1));
    int col = pos[0] - 97;
    vector<int> num_pos = {row, col};
    return num_pos;
}

Piece *create_piece(char piece) {
    switch(piece) {
        case 'K':
            return new King(0);
        case 'k':
            return new King(1);
        case 'Q':
            return new Queen(0);
        case 'q':
            return new Queen(1);
        case 'R':
            return new Rook(0);
        case 'r':
            return new Rook(1);
        case 'N':
            return new Knight(0);
        case 'n':
            return new Knight(1);
        case 'B':
            return new Bishop(0);
        case 'b':
            return new Bishop(1);
        case 'P':
            return new Pawn(0);
        case 'p':
            return new Pawn(1);
    }
    return nullptr;
}

// check if there are pawns on first or last row
bool any_pawns(vector<vector<Cell*>> board) {
    for (int i = 0; i < 8; ++i) {
        if (board.at(0).at(i)->get_piece() != nullptr && board.at(0).at(i)->get_piece()->get_value() == 1) {
            return true;
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (board.at(7).at(i)->get_piece() != nullptr && board.at(7).at(i)->get_piece()->get_value() == 1) {
            return true;
        }
    }
    return false;
}

void Chess::modify_num_pos(char ch, int col, int val) {
    int piece;
    switch(val) {
        case 1:
            piece = 5;
            break;
        case 3:
            piece = 3;
            break;
        case 4:
            piece = 4;
            break;
        case 5:
            piece = 2;
            break;
        case 9:
            piece = 1;
            break;
        case 10:
            piece = 0;
            break;
    }
    if (col) piece += 6; // black piece
    if (ch == '+') {
        num_of[piece] += 1;
    } else if (ch == '-') {
        num_of[piece] -= 1;
    }
}

// setup chess board mode
void Chess::setup() {
    TextDisplay *text_display = get_td();
    if (get_players_size() == 0) { // no game was playing
        create_players({"human", "human"});
        init(); // initialize a chess board
    } else {
        text_display->print_board("chess");
    }
    string s;
    vector<vector<Cell*>> board = get_ref_board();
    while (getline(cin, s)) { 
        istringstream ss{s};
        string cmd;
        ss >> cmd;
        if (cmd == "+") { // places piece
            char piece;
            string pos;
            ss >> piece >> pos;
            Piece *p = create_piece(piece);
            try {
                if (p) {
                    // set on board
                    if (!board[num_pos(pos)[0]][num_pos(pos)[1]]) {
                        Piece *old_p = board[num_pos(pos)[0]][num_pos(pos)[1]]->get_piece();
                        modify_num_pos('-', old_p->get_color(), old_p->get_value());
                    }
                    set_piece(num_pos(pos)[0], num_pos(pos)[1], p);
                    modify_num_pos('+', p->get_color(), p->get_value());
                }
            } catch (...) {
                cerr << "Invalid Instruction" << endl;
            }
        } else if (cmd == "-") { // removes piece
            try {
                string pos;
                ss >> pos;
                Piece *p = board[num_pos(pos)[0]][num_pos(pos)[1]]->get_piece();
                if (p) {
                    board[num_pos(pos)[0]][num_pos(pos)[1]]->remove_piece();
                    modify_num_pos('-', p->get_color(), p->get_value());
                }
            } catch (...) {
                cerr << "Invalid Instruction" << endl;
            }
        } else if (cmd == "=") { // sets turn
            string color;
            ss >> color;
            if (color == "white") {
                set_turn(0);
            } else if (color == "black") {
                set_turn(1);
            } else {
                cerr << "Invalid Instruction" << endl;
            }
        } else if (cmd == "done") {
            // check if setup is valid
            if (num_of[0] != 1 || num_of[6] != 1) { // exactly one white and black king
                cerr << "Must Have Exactly One King of Each Color" << endl;
            } else if (any_pawns(board)) {
                cerr << "No Pawns Allowed On Back Rows" << endl;
            } else {
                break;
            }
        }
        text_display->print_board("chess");
    }
    cout << "Setup Complete!" << endl;
}

// print scoreboard
void Chess::print_score() {
    cout << "Final Score:" << endl;
    if (score_size() < 2) {
        cout << "No Scores, Try Playing A Game Next Time!" << endl; 
    } else {
        cout << "White: " << get_score(0) << endl;
        cout << "Black: " << get_score(1) << endl;
    }
}

// check if king has valid moves
bool no_moves(Piece *king) {
    for (auto pair : king->get_valid_moves()) {
        if (pair.second != 3) return false;
    }
    return true;
}

// notify
void Chess::notify() {
    // set all pieces
    all_pieces  = get_ref_pieces();
    for (auto piece : all_pieces) {
        if (piece->get_value() == 10) { // is king
            // check for check
            int c = piece->get_color();
            if (piece->get_cell()->get_threats(!c)) {
                check = c;
            } else {
                check = -1;
            }
            // check for checkmate
            if (check != -1) {
                if (no_moves(piece)) {
                    checkmate = c;
                } else {
                    checkmate = -1;
                }
            } else {
                checkmate = -1;
            }
        }
    }
}
