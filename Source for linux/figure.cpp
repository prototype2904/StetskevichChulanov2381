
#include "algoritm.h"



vector<Square *> Figure::findAttackForMark()
{
    return vector<Square*>();
}

void Figure::moveFigure(Square *newSquare)
{
    Figure *lastFigure = newSquare->getPFigure();
    Figure *thisFigure = this->pSquare->getPFigure();

    //eat figure
    if(lastFigure != NULL)
    {
        int color = lastFigure->getColor();
        Game::players[color].deleteFigure(lastFigure);
    }

    Move move;
    move.setNewMove(this->getPSquare(), newSquare,thisFigure,lastFigure);
    Game::moves.push_back(move);


    this -> getPSquare() -> setPFigure(NULL);
    this -> setPSquare(newSquare);
    this -> getPSquare()-> setPFigure(thisFigure);

    if(Game::mode == 1)
    {
        Game::playersSecunds[Game::movePlayer] += 5;
    }
    if(name == "king" )
    {
        King *king = Game::players[Game::movePlayer].getKing();
        if(king->getCheck() != -1)
        {
            king->setCheck(-1);
        }
    }
    Game::nextPlayer();\
}

void Figure::setPNext(Square *pNext)
{

}

void Figure::setPFirst(bool first)
{

}




Square *Figure::getPSquare() const
{
    return pSquare;
}

void Figure::setPSquare(Square *value)
{
    pSquare = value;
}

string Figure::getName() const
{
    return name;
}

void Figure::setName(const string &value)
{
    name = value;
}

vector<Square *> Figure::findAttack()
{
    return vector<Square*>();
}

int Figure::getColor() const
{
    return color;
}

void Figure::setColor(int value)
{
    color = value;
}


