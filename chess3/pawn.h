#ifndef PAWN_H
#define PAWN_H
#include "square.h"

//class of pawn.
class Pawn : public Figure
{
private:
    Square* nextMove;//next Move directly
    bool firstMove;  //is it first move?
    vector<Square *> findAttack();
    void setNextMove();
public:
    Pawn();
    vector<Square *> findMoves();
};

#endif // PAWN_H

