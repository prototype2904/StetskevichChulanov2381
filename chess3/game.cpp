#include "game.h"


int Game::getMovePlayer() const
{
    return movePlayer;
}

void Game::setMovePlayer(int value)
{
    movePlayer = value;
}

time_t Game::getTimer() const
{
    return timer;
}

void Game::setTimer(const time_t &value)
{
    timer = value;
}
Game::Game()
{

}
