#include "bishop.h"
#include "algoritm.h"
#include <QDebug>

Bishop::Bishop():Figure()
{
    Figure::setName("bishop");
}

vector<Square*> Bishop::findMoves()
{
    vector<Square*> moves;
    vector<Square*> squares;

    squares.push_back(this->getPSquare()->getPDiag()[0]);
    squares.push_back(this->getPSquare()->getPDiag()[1]);
    squares.push_back(this->getPSquare()->getPDiag()[2]);
    squares.push_back(this->getPSquare()->getPDiag()[3]);
    squares.push_back(this->getPSquare()->getPDiag()[4]);

    qDebug() << this->getPSquare()->getLetter();
    qDebug() << this->getPSquare()->getNumber();
    King *king = Game::getKing();

    if(king->getCheck() == -1)
    {
        Square *doubleLast;
        for(int i = 0; i < squares.size(); i++)
        {
            //check wiil be King under attack after move squares[i], or not


            Square* last = this->getPSquare();
            if(i == 5)
            {
                last = doubleLast;
            }
            //if not
            while(squares.at(i) != NULL)
            {

                if(squares[i]->getPFigure() == NULL)
                {
                    moves.push_back(squares[i]);
                    vector<Square*> next = Algoritm::nextDiagMove(last, squares[i]);
                    if(next.size() == 1)
                    {
                        last=squares[i];
                        squares[i] = next.at(0);
                        next.pop_back();
                    }
                    else if(next.size() == 2)
                    {
                        last=squares[i];
                        doubleLast = last;
                        squares[i] = next.at(1);
                        next.pop_back();
                        squares.push_back(next.at(0));
                        next.pop_back();
                    }
                    else
                    {
                        squares[i] = NULL;
                    }
                }
                else if(squares[i]->getPFigure()->getColor() != this->getColor())
                {
                    moves.push_back(squares[i]);
                    break;
                }
                else if(squares[i]->getPFigure()->getColor() == this->getColor())
                {
                    squares[i]->setMark(this->getColor());
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
    else
    {
        return vector<Square*>();
    }
}
