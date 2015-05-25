#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include "pawn.h"
#include "algoritm.h"
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>


using namespace std;
namespace Ui {
class Form;
}
class Board : public QWidget
{
    Q_OBJECT

public slots:
    void start();
    void undo();
    void saveGame();
    void loadGame();
    void chooseGame();
    void startModeNormal();
    void startMode55();
    void startMode50();
    void pause();
    void back();
signals:
    void nextSec(int sec);
    void nextMin(int min);

public:
    explicit Board(QWidget *parent = 0);

    static int mate;



    void mousePressEvent(QMouseEvent *me);



    QImage paintFigure(Figure * figure, int color);

    void paintEvent(QPaintEvent *pe);

    ~Board();

    void setSquares(vector<Square *> sq);


    void paintEvolutionOfPawn(QPainter &p, int number, int color);
private:


    Ui::Form *ui;
    Timer *timer;
    QTimer *t;
    int min;
    int sec;
    //vector squares of board
    vector<Square*> squares;

    //variants of moves
    vector<Square*> variantSquares;


    //vectors of figures; 0 - player, 1 - player, 2 - player
    vector<QImage> pawn;
    vector<QImage> knight;
    vector<QImage> queen;
    vector<QImage> king;
    vector<QImage> bishop;
    vector<QImage> rook;

    int selectedFigure;
    int lastSelect;
    QLCDNumber *lcdSeconds;

    QLCDNumber *lcdMinutes;
    QPushButton *undoButton;
    QPushButton *saveGameButton;
    QPushButton *loadGameButton;
    QPushButton *buttonStartGame;
    QPushButton *buttonModeNormal;
    QPushButton *buttonMode55;
    QPushButton *buttonMode50;
    QPushButton *buttonBack;
    QPushButton *buttonPause;

    QLineEdit *lineEditInputLoadFile;
    QLabel *label;
    QLabel *labelCheckMate;

    bool load1;
    bool click;
    bool pauseFlag;
    void switchOff();
};

#endif // BOARD_H
