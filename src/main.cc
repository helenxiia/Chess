#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include "board.h"
#include "chess.h"

using namespace std;
bool setup = false;
int main() {
    Chess *cg = new Chess();
    auto chess_game = unique_ptr<Chess>{cg};
    // get input 
    // should only get "game white-player black-player" and setup
    // other input should all be handled in other classes
    string s;
    while (getline(cin, s)) { 
        istringstream ss{s};
        string cmd;
        ss >> cmd;
        if (cmd == "game") {
            bool undo_mode = false;
            // create game
            vector<string> player_names;
            string player;
            while (ss >> player) {
                if (player == "-undo") {
                    undo_mode = true;
                } else {
                    player_names.emplace_back(player);
                }
            }
            if (player_names.size() != 2 && player_names.size() == 0 && !setup) {
                cerr << "Playing Chess - Please Enter Two Players" << endl;
            } else {
                chess_game->run(player_names, undo_mode); // run game
            }
        } else if (cmd == "setup") {
            // setup mode
            setup = true;
            chess_game->setup(); // call setup
        } else if (cmd == "exit") {
            break;
        }
    }
    chess_game->print_score();
}
