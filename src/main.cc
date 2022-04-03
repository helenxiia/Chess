#include <iostream>
#include <sstream>
#include <string>

#include "board.h"
#include "chess.h"

using namespace std;

int main() {
    Chess *chess_game = new Chess();
    // get input 
    // should only get "game white-player black-player" and setup
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
            chess_game->run(player_names); // run game
        } else if (cmd == "setup") {
            // setup mode
            chess_game->setup(); // call setup
        } else if (cmd == "exit") {
            break;
        }
    }
    chess_game->print_score();
    delete chess_game;
}
