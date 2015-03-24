#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include "square.h"
#include "pawn.h"
using namespace std;
namespace Ui {
class Form;
}
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);


    bool RectIn(int myPointX, int myPointY, vector<int> x, vector<int> y)
    {
        //определяем, какие точки соединены линиями, а какие - нет
        if((x[0]+y[0] < myPointX+myPointY)&& (x[2]+y[2] > myPointX+myPointY))
        {
            if((x[3]-y[3] < myPointX+myPointY) && (x[1]-y[1] > myPointX+myPointY))
            {
                return true;
            }
        }
        return false;
    }

    void mousePressEvent(QMouseEvent *me)
    {
        int x = me->x();
        int y = me->y();
        for(int i = 0; i < squares.size(); i++)
        {
            int maxX = 0, maxY = 0, minX = 800, minY = 800;
            for(int j = 0; j < 4; j++)
            {
                if(squares[i]->getX()[j] > maxX)
                {
                    maxX = squares[i]->getX()[j];
                }

                if(squares[i]->getX()[j] < minX)
                {
                     minX = squares[i] ->getX()[j];
                }
                if(squares[i]->getY()[j] > maxY)
                {
                    maxY = squares[i]->getY()[j];
                }

                if(squares[i]->getY()[j] < minY)
                {
                     minY = squares[i]->getY()[j];
                }
            }

            if(x > minX && x < maxX && y > minY && y < maxY)
            {

 //               if(RectIn(x,y,squares[i] ->getX(), squares[i] -> getY()))
   //             {
                    qDebug() << "Letter = " << squares[i]->getLetter() << "and Number = " <<  squares[i]->getNumber();
                    break;
 //               }
            }
        }
    }

    void paintEvent(QPaintEvent *pe)
    {
        QPainter p(this);
        QImage im("C:/Users/Roman/Documents/QT/chess3/image/board.png");
        p.drawImage(0,0,QImage("C:/Users/Roman/Documents/QT/chess3/image/wallpaper.png"));
        p.drawImage(QRect(120,120,600,520),im);
        squares[0] -> setPFigure( new Pawn());

        squares[0] -> getPFigure()->getName();

        QImage fig("C:/Users/Roman/Documents/QT/chess3/image/figure_black/bishop.png");
         p.drawImage(QRect(266,137,40,40),fig);


    }
    ~Board();

    void setSquares(vector<Square *> sq);
private:
    Ui::Form *ui;
    vector<Square*> squares;

};

#endif // BOARD_H
