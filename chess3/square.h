#ifndef SQAURES_H
#define SQAURES_H

#include "vector"
using namespace std;
class Figure;
//class of Square border of Chess for three players
class Square{
private:
    //squares near this one (9 different maximum variants).
    Square* pTop; 
    Square* pBottom; 
    Square* pRight; 
    Square* pLeft;
    vector<Square*>pDiag;

    //coordinates on screen
    vector<int> x;
    vector<int> y;

    //coordinates on board
    int letter;
    int number;
    
    //figure on this square
    Figure *pFigure;
    
    //color square
    bool color;
    
    //Can we click on square or can't?
    bool click;
    
public:
    Square():
        pTop(NULL),
        pBottom(NULL),
        pRight(NULL),
        pLeft(NULL),
        letter(-1), 
        number(-1), 
        pFigure(NULL),
        color(true), 
        click(false)
    {
        for(int i = 0; i < 5 ; i++)
            pDiag.push_back(NULL);
    }



    Square *getPTop() const;
    void setPTop(Square *value);
    
    Square *getPBottom() const;
    void setPBottom(Square *value);
    
    Square *getPRight() const;
    void setPRight(Square *value);
    
    Square *getPLeft() const;
    void setPLeft(Square *value);
    
    vector<Square *> getPDiag() const;
    void setPDiag(vector<Square*>value);

    int getLetter() const;
    void setLetter(int value);
    
    int getNumber() const;
    void setNumber(int value);
    
    Figure *getPFigure() const;
    void setPFigure(Figure *value);
    
    bool getColor() const;
    void setColor(bool value);
    
    bool getClick() const;
    void setClick(bool value);

    void set(Square* pTop,
                    Square* pBottom,
                    Square* pRight,
                    Square* pLeft,
                    vector<Square*> pDiag,
                    int letter,
                    int number);

    void setCoord(int x, int y)
    {
        this->x.push_back(x);
        this->y.push_back(y);
    }

    vector<int> getX() const;
    void setX(const vector<int> &value);
    vector<int> getY() const;
    void setY(const vector<int> &value);
};



//virtual superclass of figure.
class Figure
{
private:
    int color; //0 - Zero player, 1 - First player, 2 - Second player;
    Square* pSquare;    //square, where the figure is.
    string name;

public:
    Figure() :  color(-1), pSquare(NULL), name (""){}
    Figure(int color, Square* pSquare, string name) :
        color(color){
        this->pSquare = new Square();
        this->pSquare = pSquare;
        this->name = name;
    }
    void moveFigure(Square *newSquare);
    int getColor() const;
    void setColor(int value);
    Square *getPSquare() const;
    void setPSquare(Square *value);
    string getName() const;
    void setName(const string &value);
};
#endif // SQAURES_H
