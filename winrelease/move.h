#include <QString>

#ifndef MOVE_H
#define MOVE_H

class Square;
class Figure;
class Move
{
private:
    Square* pLast;
    Square* pNew;
    Figure* movedFigure;
    Figure* attackedFigure;
    Square* pNextForPawn;
    bool first;
    int mode;
    int min;
    int sec;
public:
    Move();
    void setNewMove(Square* pNew, Square* pLast, Figure* movedFigure, Figure* attackedFigure = NULL, Square*pNext = NULL, bool first = false);

    Square *getPLast() const;
    void setPLast(Square *value);
    Square *getPNew() const;
    void setPNew(Square *value);
    Figure *getAttackedFigure() const;
    void setAttackedFigure(Figure *value);
    Figure *getMovedFigure() const;
    void setMovedFigure(Figure *value);
    Square *getPNextForPawn() const;
    void setPNextForPawn(Square *value);
    bool getFirst() const;
    void setFirst(bool value);
    int getMode() const;
    void setMode(int value);
    void setMode(Figure  *newFigure);

    int getMin() const;
    void setMin(int value);
    int getSec() const;
    void setSec(int value);
};

#endif // MOVE_H
