#ifndef ALGORITM_H
#define ALGORITM_H
#include "square.h"

class Algoritm
{
public:
    Algoritm();
    static vector<Square*> nextSquare(Square* last, Square* now);

};

#endif // ALGORITM_H
