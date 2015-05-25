#include "move.h"
#include "algoritm.h"



Square *Move::getPNew() const
{
    return pNew;
}

void Move::setPNew(Square *value)
{
    pNew = value;
}

Figure *Move::getAttackedFigure() const
{
    return attackedFigure;
}

void Move::setAttackedFigure(Figure *value)
{
    attackedFigure = value;
}

Figure *Move::getMovedFigure() const
{
    return movedFigure;
}

void Move::setMovedFigure(Figure *value)
{
    movedFigure = value;
}

Square *Move::getPNextForPawn() const
{
    return pNextForPawn;
}

void Move::setPNextForPawn(Square *value)
{
    pNextForPawn = value;
}

bool Move::getFirst() const
{
    return first;
}

int Move::getMode() const
{
    return mode;
}

void Move::setMode(int value)
{
    mode = value;
}

void Move::setMode(Figure *newFigure)
{
    if(newFigure->getName() == "knight")
    {
        Game::moves.at(Game::moves.size() - 1).setMode(4);
    }
    else if(newFigure->getName() == "rook")
    {
        Game::moves.at(Game::moves.size() - 1).setMode(3);
    }
    else if(newFigure->getName() == "bishop")
    {
        Game::moves.at(Game::moves.size() - 1).setMode(2);
    }
    else if(newFigure->getName() == "queen")
    {
        Game::moves.at(Game::moves.size() - 1).setMode(5);
    }
}


int Move::getMin() const
{
    return min;
}

void Move::setMin(int value)
{
    min = value;
}

int Move::getSec() const
{
    return sec;
}

void Move::setSec(int value)
{
    sec = value;
}
Move::Move()
{
    this->attackedFigure = NULL;
    this->pLast = NULL;
    this->pNew = NULL;
    this->mode = 0;
}


void Move::setNewMove(Square *pLast, Square *pNew, Figure *movedFigure,  Figure *attackedFigure, Square*pNext, bool first )
{
    this->pLast = pLast;
    this->attackedFigure = attackedFigure;
    this->movedFigure = movedFigure;
    this->pNew = pNew;
    this->pNextForPawn  = pNext;
    this->first = first;
}

Square *Move::getPLast() const
{
    return pLast;
}

void Move::setPLast(Square *value)
{
    pLast = value;
}
