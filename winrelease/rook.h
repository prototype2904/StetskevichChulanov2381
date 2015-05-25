#ifndef ROOK_H
#define ROOK_H
#include "square.h"

class Rook : public Figure
{
private:
    bool moved;
public:
    Rook(Square* sq, int color);
    Rook();
    vector<Square *> findMoves();
};

#endif // ROOK_H

