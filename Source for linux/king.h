
#ifndef KING_H
#define KING_H
#include "square.h"

class King : public Figure
{
private:
    bool moved;
    int mate; //-1 - no Check; 0 - Zero player; 1 - First player; 2 - Second Player;
    int check; //-1 - no Check; 0 - Zero player; 1 - First player; 2 - Second Player;
public:
    King();
    King(Square* sq, int color): Figure(color, sq, "king"), mate(-1), check(-1), moved(false){}
    Square* findOneMove(Square* direction);
    vector<Square *> findMoves();
    void setCheck(int numberPlayer);
    int getCheck();
    int getMate() const;
    void setMate(int value);
    void castling();
};

#endif // KING_H
