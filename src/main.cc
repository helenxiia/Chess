#include <iostream>
#include <sstream>
#include <string>

#include "board.h"
#include "chess.h"

using namespace std;

int main() {
    Chess *chess_game = new Chess();
    // get input 
    // should only get "game white-player black-player"
    // other input should all be handled in other classes
    string s;
    while (getline(cin, s)) { 
        istringstream ss{s};
        string cmd;
        ss >> cmd;
        if (cmd == "game") {
            // create game
            vector<string> player_names;
            string player;
            while (ss >> player) {
                player_names.emplace_back(player);
            }
            chess_game->init(); // initalize
            chess_game->create_players(player_names); // create players
            chess_game->run(); // run game
        }
    }
}
