#include "knight.h"
#include "algoritm.h"

Knight::Knight():Figure()
{
    Figure::setName("knight");
}

vector<Square *> Knight::findMoves()
{

    King *king = Game::getKing();

    if(king->getCheck() == -1)
    {

        vector<Square*> moves;
        int num = 4;
        Square* squares[] = {this->getPSquare()->getPTop(),
                              this->getPSquare()->getPBottom(),
                              this->getPSquare()->getPLeft(),
                              this->getPSquare()->getPRight()};
        for(int i = 0; i < num; i++)
        {
            if(squares[i] != NULL )
            {
                Square*next = Algoritm::nextNearMove(this->getPSquare(), squares[i]);
                if(next != NULL)
                {
                    Square* sqNearNext[] = {  next->getPTop(),
                                              next->getPBottom(),
                                              next->getPLeft(),
                                              next->getPRight()};
                    for(int j = 0; j < 4; j++)
                    {
                        if(sqNearNext[j] != NULL && squares[i])
                        {
                            vector<Square*> diag = sqNearNext[j] -> getPDiag();
                            for(int k = 0; k < diag.size(); k++)
                            {
                                if(diag[k] != NULL && diag[k] == squares[i])
                                {
                                    if(sqNearNext[j]->getPFigure() != NULL && sqNearNext[j]->getPFigure()->getColor() == this->getColor())
                                    {
                                        sqNearNext[j]->setMark(getColor());
                                    }
                                    if(sqNearNext[j]->getPFigure() == NULL || sqNearNext[j]->getPFigure()->getColor() != this->getColor())
                                    moves.push_back(sqNearNext[j]);
                                    break;
                                }
                            }
                        }
                    }
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

