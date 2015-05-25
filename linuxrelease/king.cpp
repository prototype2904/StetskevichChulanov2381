#include "king.h"


int King::getMate() const
{
    return mate;
}

void King::setMate(int value)
{
    mate = value;
}
King::King():Figure()
{
    mate = -1;
    check = -1;
    moved = false;
    Figure::setName("king");
}

Square* King::findOneMove(Square* direction)
{
    if(direction != NULL)
    {
        if(direction->getPFigure() != NULL)
        {
            if(direction->getPFigure()->getColor() != this->getColor() && !direction->is_UnderAttack(this->getColor()))
            {

                //check under atack or not
                return direction;
            }
            else
            {
                return NULL;
            }

        }
        else if(direction->is_UnderAttack(this->getColor()))
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
    //then comment this!
    return direction;
}

vector<Square*> King::findMoves()
{
    vector<Square*> moves;
    if(mate == -1)
    {
            int num = 9;
            Square* squares[] = {this->getPSquare()->getPTop(), this->getPSquare()->getPBottom(),this->getPSquare()->getPLeft(),
                             this->getPSquare()->getPRight(),this->getPSquare()->getPDiag()[0],this->getPSquare()->getPDiag()[1],
                             this->getPSquare()->getPDiag()[2],this->getPSquare()->getPDiag()[3],this->getPSquare()->getPDiag()[4]};
            for(int i = 0; i < num; i++)
            {
                Square* tmp = findOneMove(squares[i]);
                if(tmp != NULL )
                {
                    moves.push_back(tmp);
                }

            }

    }
    else
    {
        //all figures of this player go to winner;
    }
    return moves;
}

void King::setCheck(int numberPlayer)
{
    this->check = numberPlayer;
}

int King::getCheck()
{
    return this->check;
}

