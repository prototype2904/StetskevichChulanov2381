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
            if(direction->getPFigure()->getColor() != this->getColor())
            {
                //check under atack or not
                //return direction
            }

        }
        else
        {
            //check under atack or not
        }
    }
    else
    {
        return nullptr;
    }
    //then comment this!
    return direction;
}

vector<Square*> King::findMoves()
{
    vector<Square*> moves;
    if(mate == -1)
    {
        if(check == -1)
        {

            int num = 9;
            Square* squares[] = {this->getPSquare()->getPTop(), this->getPSquare()->getPBottom(),this->getPSquare()->getPLeft(),
                             this->getPSquare()->getPRight(),this->getPSquare()->getPDiag()[0],this->getPSquare()->getPDiag()[1],
                             this->getPSquare()->getPDiag()[2],this->getPSquare()->getPDiag()[3],this->getPSquare()->getPDiag()[4]};
            for(int i = 0; i < num; i++)
            {
                Square* tmp = findOneMove(squares[i]);
                if(tmp != nullptr)
                {
                    moves.push_back(tmp);
                }

            }


            //castling
        }
        else
        {
            //try to def
        }
    }
    else
    {
        //all figures of this player go to winner;
    }
    return moves;
}

