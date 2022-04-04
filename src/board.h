#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include "observer.h" // Board observes its Pieces

// forward declare
class Cell;
class Move;
class Piece;
class Player;
class TextDisplay;

class Board : public Observer {
    // board that the game is being played on
    std::vector<std::vector<std::unique_ptr<Cell>>> the_board; 
    // vector of previous moves made during the game
    std::vector<std::unique_ptr<Move>> previous_moves; 
    // vector of pieces that are in the game
    std::vector<std::unique_ptr<Piece>> pieces; 
    // participants of the game, 0 is white, 1 is black
    std::vector<std::unique_ptr<Player>> players; 
    // numerical value representing which player's turn it is
    int turn; 
    // numerical value counting the number of rounds that have been played
    int count;
    // returns whether or not the game is in play
    bool currently_playing; 
    // maps player to their current score
    static std::map<int, float> score; 
    // points to a text display object
    std::unique_ptr<TextDisplay> td;
    // rest the board
    void reset();
    // private virtual members
    // initialize the board as needed
    virtual void init() = 0; 
    // create the players
    virtual void create_players(std::vector<std::string> player_names) = 0;
    // returns whether or not the game is over
    virtual bool game_over() = 0; 
  protected:
    // set the board to a specific length and width
    void set_board(int row, int col);
    // get the text display object
    TextDisplay *get_td();
    // get number of players
    int get_players_size();
    // add a player to the game
    void add_player(Player *player);
    // set a piece at a cell
    void set_piece(int row, int col, Piece *piece);
    // get piece using id
    Piece *get_piece(int id);
    // remove piece
    void remove_piece(int row, int col);
    // get reference to all pieces
    std::vector<Piece*> get_ref_pieces();
    // edit the score board
    static void modify_score(int player, float point);
    // get a score
    static int get_score(int player);
    // get size of score board
    static int score_size();
    // set turn
    void set_turn(int color);
  public:
    // constructor and destructor
    Board();
    virtual ~Board() = 0;
    // get reference to the board
    std::vector<std::vector<Cell*>> get_ref_board();
    // return if a player resigned
    int resign();
    // setup mode
    virtual void setup() = 0;
    // run the game
    void run(std::vector<std::string> player_names); 
    // notify
    virtual void notify() = 0;
};

#endif
