#include "board.h"
#include "move.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// static map
map<int, float> Board::score = map<int, float>();

// constructor
Board::Board() : the_board{vector<vector<Cell*>>()}, previous_moves{vector<Move*>()}, 
                    pieces{vector<Piece*>()}, players{vector<Player*>()}, turn{0}, currently_playing{true} {}

// destructor
Board::~Board() { /* delete pointers probably */ } 

// modify scoreboard
void Board::modify_score(int player, float point) {
    if (!score.count(player)) { // player is not in map yet
        score.insert({player, point});
    } else {
        auto it = score.find(player); // find the current score
        it->second = it->second + point; // add new score to cumulative score
    }
}

// setup mode
void Board::setup() {
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

// run the game
void Board::run() {
    while(currently_playing) { // while game is playing
        Player *cur_player = players.at(turn); // get which player is playing, based on the turn
        try {
            // ---- NEED CLASSES TO BE DEFINED ---- //
            // WE MAY NEED A COPY CONSTRUCTOR HERE
            // SINCE I DON'T WANT TO DO THAT, LETS HAVE PLAYER RETURN A VECTOR WITH THE INFORMATION NEEDED FOR MOVE
            // IE. LAST_PIECE, CURRENT_PIECE, INITIAL_CELL, FINAL_CELL
            // THIS INCREASES COUPLING THO
            // Move move = cur_player->make_move(); 
            // previous_moves.emplace_back(move);

            // increment turn
            if (turn == (int) players.size() - 1) { // it is last player's turn
                turn = 0;
            } else {
                ++turn;
            }
            // increment count
            ++count;

            // create move
            // Move *move  = new Move();
            // previous_moves.emplace_back(move);
        } catch (...) { // probably should define some error here
            // throw invalid move
        }
    }
}
