#include "pawn.h"
#include "algoritm.h"
Pawn::Pawn():Figure(-1, NULL, "pawn")
{
    firstMove = true;
}

vector<Square *> Pawn::findMoves()
{
    vector<Square*> moves;
    vector<Square*> next;
    if(nextMove -> getPFigure() == NULL)
    {

        //check king nuder aatack or not!!!!
        //if not
        moves.push_back(nextMove);
        next = Algoritm::nextSquare(this->getPSquare(), nextMove);
        if(firstMove)
        {
            firstMove = false;
            moves.push_back(next.at(0));
        }
        else if(next.size() == 0)
        {
            //end of board
            //EVOLUTION!!!
        }

    }

    next = this->findAttack();
    if(next.size() != 0)
    {
        while(next.size())
        {
            moves.push_back(next.at(next.size()-1));
            next.pop_back();
        }
    }
    return moves;

}


//function which check, has pawn moves to attack, or has not
vector<Square *> Pawn::findAttack()
{
    vector<Square*> diag = this->getPSquare()->getPDiag();
    vector<Square*> attack;

    //check 5 diaganls, pawn attack at diag's
    for(int i = 0; i < 5; i++)
    {
        if(diag[i]->getPLeft() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
        {
            attack.push_back(diag[i]);
        }
        if(diag[i]->getPRight() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
        {
            attack.push_back(diag[i]);
        }
        if(diag[i]->getPTop() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
        {
            attack.push_back(diag[i]);
        }
        if(diag[i]->getPBottom() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
        {
            attack.push_back(diag[i]);
        }
    }
    return attack;
}

void Pawn::setNextMove()
{

}

