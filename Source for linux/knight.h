
#ifndef KNIGHT_H
#define KNIGHT_H
#include "square.h"

class Knight : public Figure
{
public:
    Knight();
    Knight(Square* sq, int color): Figure(color, sq, "knight"){}
    vector<Square *> findMoves();
};

#endif // KNIGHT_H

