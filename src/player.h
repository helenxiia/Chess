
class Player {
    int side;
    vector<Piece *> owned_pieces;
    public:
    void make_move();
    void notify();
};