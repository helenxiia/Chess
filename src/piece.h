#ifndef PIECE_H
#define PIECE_H

#include <memory>
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"
#include "cell.h"


class Piece {
    std::unique_ptr<Cell> cell;
    int color;
    bool is_taken;
    int value;
    int status;
    
    
};