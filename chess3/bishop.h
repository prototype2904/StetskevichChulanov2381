
#ifndef BISHOP_H
#define BISHOP_H
#include "square.h"

class Bishop : public Figure
{
public:
    Bishop();
    vector<Square*> findMoves();
};

#endif // BISHOP_H

