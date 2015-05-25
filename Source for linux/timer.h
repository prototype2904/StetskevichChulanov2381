#ifndef TIMER_H
#define TIMER_H
#include "QTimer"
#include "QObject"
class Timer : QObject
{
    Q_OBJECT

public:
    QTimer *timer;
    int sec;
    int min;
    Timer();
    void start();
    void pause();
public slots:
    void update();
};

#endif // TIMER_H
