#include "chess.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

#include "human.h"

using namespace std;

// constructor
Chess::Chess() : Board{}, checkmate{-1}, check{-1}, stalemate{false} {}

// destructor
Chess::~Chess() {}

// initialize a chess board
void Chess::init() {
    // set the_board to an 8x8
    set_board(8, 8);
    // set king
    set_piece(7, 4, new King(0)); // white
    set_piece(0, 4, new King(1)); // black
    // set pawns
    for (int i = 0; i < 8; ++i) { // white
        set_piece(6, i, new Pawn(0));
    }
    for (int i = 0; i < 8; ++i) { // black
        set_piece(1, i, new Pawn(1));
    }
    // set bishops
    set_piece(7, 2, new Bishop(0)); // white
    set_piece(7, 5, new Bishop(0)); // white
    set_piece(0, 2, new Bishop(1)); // black
    set_piece(0, 5, new Bishop(1)); // black
    // set knights
    set_piece(7, 1, new Knight(0)); // white
    set_piece(7, 6, new Knight(0)); // white
    set_piece(0, 1, new Knight(1)); // black
    set_piece(0, 6, new Knight(1)); // black
    // set rooks
    set_piece(7, 0, new Rook(0)); // white
    set_piece(7, 7, new Rook(0)); // white
    set_piece(0, 0, new Rook(1)); // black
    set_piece(0, 7, new Rook(1)); // black
    // set queens
    set_piece(7, 3, new Queen(0)); // white
    set_piece(0, 3, new Queen(1)); // black
    TextDisplay *text_display = get_td();
    text_display->print_board("chess");
}

// create players
void Chess::create_players(vector<string> player_names) {
    int side = 0;
    for (auto player : player_names) {
        if (player == "human") { // Humane
            Human *new_player = new Human(side);
            add_player(new_player);
        } else { // Computer

        }
    }
}

// check if game is over
bool Chess::game_over() {
    if (checkmate != -1) { // checkmate
        // NOT SURE IF THIS IS HOW MULTIPLAYER CHESS POINTS WORK
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

// notify Chess when piece moves
void Chess::notify() {

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

// setup chess board mode
// setup mode
void Chess::setup() {
    string s;
    while (getline(cin, s)) { 
        istringstream ss{s};
        string cmd;
        ss >> cmd;
        if (cmd == "+") { // places piece

        } else if (cmd == "-") { // removes piece
            
        } else if (cmd == "=") { // sets turn

        } else if (cmd == "done") {
            // check if setup is valid
            break;
        }
    }
}

// print scoreboard
void Chess::print_score() {
    cout << "Final Score:" << endl;
    cout << "White: " << get_score(0) << endl;
    cout << "Black: " << get_score(1) << endl;
}
