
#ifndef QUEEN_H
#define QUEEN_H
#include "square.h"

class Queen : public Figure
{
public:
    Queen();
    Queen(Square* sq, int color): Figure(color, sq, "queen"){}
    vector<Square *> findMoves();
};

#endif // QUEEN_H

