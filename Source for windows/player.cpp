#include "algoritm.h"


vector<Figure *> Player::getFigures() const
{
    return figures;
}

void Player::setFigures(const vector<Figure *> &value)
{
    figures = value;
}

int Player::getColor() const
{
    return color;
}

void Player::setColor(int value)
{
    color = value;
}

bool Player::getPlay() const
{
    return play;
}

void Player::setPlay(bool value)
{
    play = value;
}

King *Player::getKing() const
{
    return king;
}

void Player::setKing(King *king)
{
    this->king = king;
}
Player::Player()
{

}

