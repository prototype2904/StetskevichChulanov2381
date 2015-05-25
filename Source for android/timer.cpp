#include "timer.h"

Timer::Timer()
{
    sec = 0;
    min = 0;
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void Timer::update()
{
    sec++;
    if(sec >= 60)
    {
        sec = 0;
        min++;
    }
}
