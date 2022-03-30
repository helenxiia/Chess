#ifndef PLAYER_H
#define PLAYER_H

class Player : public Board{
    // 0 or 1, black or white, can be a string if we want
    // correlates to Board::turn variable
    int side;

    // pieces owned by a player
    vector<std::unique_ptr<Piece>> owned_pieces;

    public:
    Player(int side);
    virtual void make_move() = 0;
    void notify();
    ~Player();
};

#endif