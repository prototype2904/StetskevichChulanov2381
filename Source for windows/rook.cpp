#include "rook.h"
#include"algoritm.h"
Rook::Rook(Square *sq, int color) : Figure(color, sq, "rook")
{
    moved = false;
}

Rook::Rook():Figure()
{
    moved = false;
    Figure::setName("rook");
}

vector<Square*> Rook::findMoves()
{
    King *king = Game::getKing();

    if(king->getCheck() == -1)
    {


        vector<Square*> moves;
        Square* last = NULL;
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
                    if(last == NULL)
                    {
                        last = getPSquare();
                    }
                    moves.push_back(squares[i]);
                    Square* next = Algoritm::nextNearMove(last, squares[i]);
                    if(next != NULL)
                    {
                        last = squares[i];
                        squares[i] = next;
                    }
                    else
                    {
                        squares[i] = NULL;
                        last = NULL;
                    }
                }
                else if(squares[i]->getPFigure()->getColor() != getColor())
                {
                    moves.push_back(squares[i]);
                    last = NULL;
                    break;
                }
                else if(squares[i]->getPFigure()->getColor() == getColor())
                {
                    squares[i]-> setMark(this->getColor());
                    last = NULL;
                    break;
                }
                else
                {
                    last = NULL;
                    break;
                }
            }
        }
        return moves;
    }
    else
    {
        return vector<Square*>();
    }
}
