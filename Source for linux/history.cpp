
#include "algoritm.h"

Square *History::getLast() const
{
    return last;
}

void History::setLast(Square *value)
{
    last = value;
}

Square *History::getNext() const
{
    return next;
}

void History::setNext(Square *value)
{
    next = value;
}

string History::getMode() const
{
    return mode;
}

void History::setMode(const string &value)
{
    mode = value;
}


History::History()
{
}
