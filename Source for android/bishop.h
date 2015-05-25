
#ifndef BISHOP_H
#define BISHOP_H
#include "square.h"

class Bishop : public Figure
{
public:
    Bishop();
    Bishop(Square* sq, int color): Figure(color, sq, "bishop"){}
    vector<Square *> findMoves();
};

#endif // BISHOP_H

