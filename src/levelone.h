#ifndef LEVELONE_H
#define LEVELONE_H

// level one class inherits from the abstract class computer, we implement this level with the following:
// random legal moves
class LevelOne : public Computer {
    // inherts all fields from computer and player
    public:
    void make_move() override;
}
#endif