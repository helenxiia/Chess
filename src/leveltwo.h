#ifndef LEVELTWO_H
#define LEVELTWO_H

// level one class inherits from the abstract class computer, we implement this level with the following:
// prefers capturing moves and checks over other moves.
class LevelTwo : public Computer {
    // inherts all fields from computer and player
    public:
    LevelTwo(int side);
    std::vector<int> make_move() override;
    ~LevelTwo();
};
#endif