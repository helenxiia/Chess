#ifndef BOARD_H_
#define BOARD_H_

#include <vector>

// forward declare
class Cell;
class Move;
class Piece;
class Player;

class Board {
    // board that the game is being played on
    std::vector<std::vector<Cell*>> the_board; 
    // vector of previous moves made during the game
    std::vector<Move*> previous_moves; 
    // vector of pieces that are in the game
    std::vector<Piece*> pieces; 
    // participants of the game, 0 is white, 1 is black
    std::vector<Player*> players; 
    // numerical value representing which player's turn it is
    int turn; 
    // returns whether or not the game is in play
    bool currently_playing; 
    // maps player to their current score
    static std::map<int, int> score; 
  public:
    // constructor and destructor
    Board();
    ~Board();
    // initialize the board as needed
    virtual void init() = 0; 
    virtual void create_players() = 0; // create the players
    // returns whether or not the game is over
    virtual bool game_over() = 0; 
    // run the game
    void run(); 
};

#endif
