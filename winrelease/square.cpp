#include "square.h"


Square *Square::getPBottom() const
{
    return pBottom;
}

void Square::setPBottom(Square *value)
{
    if(this -> pBottom == NULL)
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
    if(this -> pRight == NULL)
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
    if(this -> pLeft == NULL)
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

char Square::getLetter() const
{
    return letter;
}

void Square::setLetter(char value)
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
 /*   if(this -> pFigure == NULL)
    {
        this -> pFigure = new Figure();
    }*/
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

void Square::setMark(int player)
{
    if(player == 0)
    {
        zero = true;
    }
    else if(player == 1)
    {
        first = true;
    }
    else if(player == 2)
    {
        second = true;
    }
    else
    {
        return;
    }
}

bool Square::is_UnderAttack(int player)
{
    if(player == 0)
    {
        return (first || second);
    }
    else if(player == 1)
    {
        return (zero || second);
    }
    else if(player == 2)
    {
        return (zero || first);
    }
    else
    {
        return false;
    }
}

void Square::clearMark()
{
    zero = false;
    first = false;
    second = false;
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
int Square::getAttackPlayer()
{
    int color = this->pFigure->getColor();

    if(color == 0)
    {
        if(first)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if(color == 1)
    {
        if(zero)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
    else if( color == 2)
    {
        if(first)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

Square *Square::getPTop() const
{
    return pTop;
}

void Square::setPTop(Square *value)
{
    if(this -> pTop == NULL)
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
                char letter,
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

