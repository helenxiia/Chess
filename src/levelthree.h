#ifndef LEVELTHREE_H
#define LEVELTHREE_H

// level one class inherits from the abstract class computer, we implement this level with the following:
// prefers avoiding capture, capturing moves, and checks.
class LevelThree : public Computer {
    // inherts all fields from computer and player
    public:
    void make_move() override;
}
#endif