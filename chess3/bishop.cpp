#include "bishop.h"
#include "algoritm.h"

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

    for(int i = 0; i < squares.size(); i++)
    {
        //check wiil be King under attack after move squares[i], or not

        //if not
        while(squares.at(i) != NULL)
        {
            if(squares[i]->getPFigure() == NULL)
            {
                moves.push_back(squares[i]);
                vector<Square*> next = Algoritm::nextSquare(this->getPSquare(), squares[i]);
                if(next.size() == 1)
                {
                    squares[i] = next.at(0);
                    next.pop_back();
                }
                else if(next.size() == 2)
                {
                    squares[i] = next.at(1);
                    next.pop_back();
                    squares.push_back(next.at(0));
                    next.pop_back();
                }
            }
            else if(squares[i]->getPFigure()->getColor() != this->getColor())
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
