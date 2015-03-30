#include "square.h"


//NEED TEST!!!!
//move figure at new square

void Figure::moveFigure(Square *newSquare)
{
    Figure *thisFigure = this->pSquare->getPFigure();
    this -> getPSquare() -> setPFigure(NULL);
    this -> setPSquare(newSquare);
    this -> getPSquare()-> setPFigure(thisFigure);
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
int Figure::getColor() const
{
    return color;
}

void Figure::setColor(int value)
{
    color = value;
}


