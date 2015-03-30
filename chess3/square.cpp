#include "square.h"


Square *Square::getPBottom() const
{
    return pBottom;
}

void Square::setPBottom(Square *value)
{
    if(this -> pBottom == nullptr)
    {
        this -> pBottom = new Square();
    }
    this -> pBottom = value;
}

Square *Square::getPRight() const
{
    return pRight;
}

void Square::setPRight(Square *value)
{
    if(this -> pRight == nullptr)
    {
        this -> pRight = new Square();
    }
    this -> pRight = value;
}

Square *Square::getPLeft() const
{
    return pLeft;
}

void Square::setPLeft(Square *value)
{
    if(this -> pLeft == nullptr)
    {
        this -> pLeft = new Square();
    }
    this -> pLeft = value;
}

vector<Square *> Square::getPDiag() const
{
    return pDiag;
}

void Square::setPDiag(vector<Square *> value)
{
    this->pDiag = value;
}

int Square::getLetter() const
{
    return letter;
}

void Square::setLetter(int value)
{
    letter = value;
}

int Square::getNumber() const
{
    return number;
}

void Square::setNumber(int value)
{
    number = value;
}

Figure *Square::getPFigure() const
{
    return pFigure;
}

void Square::setPFigure(Figure *value)
{
    if(this -> pFigure == NULL)
    {
        this -> pFigure = new Figure();
    }
    this -> pFigure = value;
}

bool Square::getColor() const
{
    return color;
}

void Square::setColor(bool value)
{
    color = value;
}

bool Square::getClick() const
{
    return click;
}

void Square::setClick(bool value)
{
    click = value;
}



vector<int> Square::getX() const
{
    return x;
}

void Square::setX(const vector<int> &value)
{
    x = value;
}

vector<int> Square::getY() const
{
    return y;
}

void Square::setY(const vector<int> &value)
{
    y = value;
}
Square *Square::getPTop() const
{
    return pTop;
}

void Square::setPTop(Square *value)
{
    if(this -> pTop == nullptr)
    {
        this -> pTop = new Square();
    }
    this -> pTop = value;
}

void Square::set(Square* pTop,
                Square* pBottom,
                Square* pRight,
                Square* pLeft,
                vector<Square*> pDiag,
                int letter,
                int number)
{
    this->setPTop(pTop);
    this -> setPBottom(pBottom);
    this->setPRight(pRight);
    this->setPLeft(pLeft);
    this->setLetter(letter);
    this->setNumber(number);
    this->pDiag = pDiag;
}

