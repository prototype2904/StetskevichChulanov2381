#ifndef GAME_H
#define GAME_H
#include"time.h"
class Game
{
private:
    int movePlayer;
    time_t timer;

public:
    Game();



    int getMovePlayer() const;
    void setMovePlayer(int value);
    time_t getTimer() const;
    void setTimer(const time_t &value);
};

#endif // GAME_H
