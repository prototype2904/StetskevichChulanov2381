#include "rook.h"
#include"algoritm.h"
Rook::Rook():Figure()
{
    moved = false;
    Figure::setName("rook");
}

vector<Square*> Rook::findMoves()
{
    vector<Square*> moves;
    int num = 4;
    Square* squares[] = {this->getPSquare()->getPTop(),
                          this->getPSquare()->getPBottom(),
                          this->getPSquare()->getPLeft(),
                          this->getPSquare()->getPRight()};
    for(int i = 0; i < num; i++)
    {
        //check wiil be King under attack after move squares[i], or not

        //if not
        while(squares[i] != NULL)
        {
            if(squares[i]->getPFigure() == NULL)
            {
                moves.push_back(squares[i]);
                vector<Square*> next = Algoritm::nextSquare(getPSquare(), squares[i]);
                if(next.size() != 0)
                {
                    squares[i] = next.at(next.size()-1);
                }
            }
            else if(squares[i]->getPFigure()->getColor() != getColor())
            {
                moves.push_back(squares[i]);
                break;
            }
            else
            {
                break;
            }
        }
    }
    return moves;
}
