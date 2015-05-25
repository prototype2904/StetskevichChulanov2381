#include "queen.h"
#include "algoritm.h"
Queen::Queen():Figure()
{
   Figure::setName("queen") ;

}

vector<Square *> Queen::findMoves()
{
    vector<Square*> moves;
    vector<Square*> squares;
    King *king = Game::getKing();

    if(king->getCheck() == -1)
    {
        squares.push_back(this->getPSquare()->getPDiag()[0]);
        squares.push_back(this->getPSquare()->getPDiag()[1]);
        squares.push_back(this->getPSquare()->getPDiag()[2]);
        squares.push_back(this->getPSquare()->getPDiag()[3]);
        squares.push_back(this->getPSquare()->getPDiag()[4]);
        Square* last;
        Square *doubleLast;
        for(int i = 0; i < squares.size(); i++)
        {
            //check wiil be King under attack after move squares[i], or not


            last = this->getPSquare();
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
                    squares[i]->setMark(this->getColor());
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
        last = NULL;
        int num = 4;
        Square* square[] = {this->getPSquare()->getPTop(),
                              this->getPSquare()->getPBottom(),
                              this->getPSquare()->getPLeft(),
                              this->getPSquare()->getPRight()};
        for(int i = 0; i < num; i++)
        {
            //check wiil be King under attack after move squares[i], or not

            //if not
            while(square[i] != NULL)
            {
                if(square[i]->getPFigure() == NULL)
                {
                    if(last == NULL)
                    {
                        last = getPSquare();
                    }
                    moves.push_back(square[i]);
                    Square* next = Algoritm::nextNearMove(last, square[i]);
                    if(next != NULL)
                    {
                        last = square[i];
                        square[i] = next;
                    }
                    else
                    {
                        square[i] = NULL;
                        last = NULL;
                    }
                }
                else if(square[i]->getPFigure()->getColor() != getColor())
                {
                    moves.push_back(square[i]);
                    square[i]->setMark(this->getColor());
                    last = NULL;
                    break;
                }
                else if(square[i]->getPFigure()->getColor() == getColor())
                {
                    last = NULL;
                    square[i]->setMark(this->getColor());
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

    if(king->getCheck())
    {
    }
    return vector<Square*>();

}

