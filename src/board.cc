#include "board.h"

using namespace std;

// static map
map<int, float> Board::score = map<int, float>();

// constructor
Board::Board() {}

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

// run the game
void Board::run() {
    while(currently_playing) { // while game is playing
        Player *cur_player = players.at(turn); // get which player is playing, based on the turn
        try {
            // ---- NEED CLASSES TO BE DEFINED ---- //
            // Move move = cur_player->make_move();
            // previous_moves.emplace_back(move);

            // increment turn
            if (turn == (int) players.size() - 1) { // it is last player's turn
                turn = 0;
            } else {
                ++turn;
            }
        } catch (...) { // probably should define some error here
            // throw invalid move
        }
    }
}
