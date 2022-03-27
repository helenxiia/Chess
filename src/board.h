#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <string>

#include "observer.h" // Board observes its Pieces

// forward declare
class Cell;
class Move;
class Piece;
class Player;

class Board {
  protected:
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
    // numerical value counting the number of rounds that have been played
    int count;
    // returns whether or not the game is in play
    bool currently_playing; 
    // maps player to their current score
    static std::map<int, float> score; 
  public:
    // constructor and destructor
    Board();
    ~Board();
    // initialize the board as needed
    virtual void init() = 0; 
    virtual void create_players(std::vector<std::string> player_names) = 0; // create the players
    // returns whether or not the game is over
    virtual bool game_over() = 0; 
    // Board observes Piece
    virtual void notify() = 0;
    // edit the score board
    static void modify_score(int player, float point);
    // setup mode
    virtual void setup() = 0;
    // run the game
    void run(); 
};

#endif
