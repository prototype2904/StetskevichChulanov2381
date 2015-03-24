#include "algoritm.h"

Algoritm::Algoritm()
{
}


//find next square after last and current square
vector<Square*> Algoritm::nextSquare(Square *last, Square *now)
{
   vector<Square*> sqNow;
   sqNow.push_back(now->getPTop());
   sqNow.push_back(now->getPBottom());
   sqNow.push_back(now->getPLeft());
   sqNow.push_back(now->getPRight());
   sqNow.push_back(now->getPDiag()[0]);
   sqNow.push_back(now->getPDiag()[1]);
   sqNow.push_back(now->getPDiag()[2]);
   sqNow.push_back(now->getPDiag()[3]);
   sqNow.push_back(now->getPDiag()[4]);

   vector<Square*> sqLast;
   sqLast.push_back(last->getPTop());
   sqLast.push_back(last->getPBottom());
   sqLast.push_back(last->getPLeft());
   sqLast.push_back(last->getPRight());
   sqLast.push_back(last->getPDiag()[0]);
   sqLast.push_back(last->getPDiag()[1]);
   sqLast.push_back(last->getPDiag()[2]);
   sqLast.push_back(last->getPDiag()[3]);
   sqLast.push_back(last->getPDiag()[4]);

    vector<Square*>squares;
    int number = -1;
    for(int i = 0; i < 8; i++)
    {
        if(sqLast[i] == now)
        {
            number = i;
        }
    }

    if(number >=4 && sqNow[8] != NULL)
    {
        squares.push_back(sqNow[8]);
    }

    if(number != -1)
        squares.push_back(sqNow[number]);
    return squares;
}


