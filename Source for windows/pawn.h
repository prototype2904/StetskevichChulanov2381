#ifndef PAWN_H
#define PAWN_H
#include "square.h"

//class of pawn.
class Pawn : public Figure
{
private:
    Square* nextMove;//next Move directly
    bool firstMove;  //is it first move?
    void setNextMove();
    void evolution();
    void specialAttackFunction(Square *newSquare);
public:
    Pawn();
    vector<Square *> findAttackForMark();
    vector<Square *> findAttack();
    Pawn(Square *sq, Square* nextMove, int color);
    vector<Square *> findMoves();
    void setPNext(Square *pNext);
    void moveFigure(Square *newSquare);
    void setPFirst(bool first);
};

#endif // PAWN_H

