#ifndef LEVELONE_H
#define LEVELONE_H

// level one class inherits from the abstract class computer, we implement this level with the following:
// random legal moves
class LevelOne : public Computer {
    // inherts all fields from computer and player
    public:
    LevelOne( int side);
    std::vector<int> make_move() override;
    ~LevelOne();
};
#endif