#include "board.h"
#include "ui_board.h"
#include <QRadialGradient>
 #include <QtGui>
#include <QVBoxLayout>
#include<QGridLayout>
#include "queen.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include <time.h>
#include"test.h"
#include <fstream>
#include <QDesktopWidget>


void paintEvolutionOfPawn(QPainter &p, int number, int color);

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    variantSquares()
{
    click = false;
    pauseFlag = false;
    load1 = false;
    sec = 0;
    min = 0;

    t = new QTimer(this);
    label = new QLabel(this);
    labelCheckMate = new QLabel(this);
    lcdSeconds = new QLCDNumber(2, this);
    lcdMinutes = new QLCDNumber(3, this);

    lineEditInputLoadFile = new QLineEdit(this);

    undoButton = new QPushButton("undo", this);
    saveGameButton = new QPushButton("Save Game", this);
    loadGameButton = new QPushButton("Load Game", this);
    buttonStartGame = new QPushButton("Start Game", this);
    buttonModeNormal = new QPushButton("Start Normal Mode", this);
    buttonMode50 = new QPushButton("Start Mode 10 + 0",this);
    buttonMode55 = new QPushButton("Start Mode 10 + 5", this);
    buttonPause = new QPushButton("Pause", this);
    buttonBack = new QPushButton("Back", this);


    QDesktopWidget desktop;

    double p = desktop.geometry().height()/768.0;
    double k = desktop.geometry().width() / 1366.0;



    buttonModeNormal->setGeometry(QRect((int)(1000 * k),(int)(290*p), (int)(250*k),(int)(120*p)));
    buttonMode50-> setGeometry(QRect((int)(1000*k),(int)(410*p), (int)(250*k), (int)(120*p)));
    buttonMode55-> setGeometry(QRect((int)(1000*k),(int)(550*p), (int)(250*k), (int)(120*p)));
    undoButton->setGeometry(QRect((int)(1000*k),(int)(290*p), (int)(250*k),(int)(120*p)));
    saveGameButton -> setGeometry(QRect((int)(1000*k),(int)(410*p), (int)(250*k), (int)(120*p)));
    loadGameButton -> setGeometry(QRect((int)(1000*k),(int)(610*p), (int)(250*k), (int)(60*p)));
    buttonStartGame -> setGeometry(QRect((int)(1000*k),(int)(410*p), (int)(250*k), (int)(120*p)));
    buttonPause -> setGeometry(QRect((int)(1000*k), (int)(150*p), (int)(100*k),(int)(100*p)));
    buttonBack -> setGeometry(QRect((int)(1000*k), (int)(150*p), (int)(100*k), (int)(100*p)));
    labelCheckMate->setGeometry(QRect((int)(350*p), (int)(50*p), (int)(180*p), (int)(40*p)));


    lcdSeconds->setGeometry(QRect((int)(942*k),(int)(60*p), (int)(250*k),(int)(50*p)));
    lcdMinutes->setGeometry(QRect((int)(872*k),(int)(60*p), (int)(250*k),(int)(50*p)));

    lineEditInputLoadFile ->setGeometry(QRect((int)(872*k),(int)(550*p), (int)(250*k),(int)(60*p)));


    buttonBack -> setVisible(false);
    buttonPause -> setVisible(false);
    buttonMode50->setVisible(false);
    buttonMode55->setVisible(false);
    buttonModeNormal->setVisible(false);
    saveGameButton->setVisible(false);
    undoButton->setVisible(false);
    lcdMinutes->setVisible(false);
    lcdSeconds->setVisible(false);
    lineEditInputLoadFile->setVisible(false);
    labelCheckMate->setVisible(false);



    connect(buttonBack, SIGNAL(clicked()), this, SLOT(back()));
    connect(buttonPause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(undoButton, SIGNAL(clicked()), this, SLOT(undo()));
    connect(saveGameButton, SIGNAL(clicked()), this, SLOT(saveGame()));
    connect(loadGameButton, SIGNAL(clicked()), this, SLOT(loadGame()));
    connect(buttonStartGame, SIGNAL(clicked()), this, SLOT(chooseGame()));

    connect(buttonModeNormal, SIGNAL(clicked()), this, SLOT(startModeNormal()));
    connect(buttonMode50, SIGNAL(clicked()), this, SLOT(startMode50()));
    connect(buttonMode55, SIGNAL(clicked()), this, SLOT(startMode55()));

    connect(t, SIGNAL(timeout()), this, SLOT(start()));
    connect(this,SIGNAL(nextSec(int)), lcdSeconds, SLOT(display(int)));
    connect(this,SIGNAL(nextMin(int)), lcdMinutes, SLOT(display(int)));

    QVBoxLayout *box = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout(this);

//
 //   box->addWidget(undoButton);

    grid->addLayout(box,2,5,1,1);
    setLayout(grid);

    //label->setText(QApplication::applicationDirPath());
    //label->setGeometry(10,10, 1000,400);

//    connect(this, SLOT(nextSec(int)), ui->timer, SIGNAL(display(int)));

    selectedFigure = -1;
    vector<QString> files;

    QString path = QCoreApplication::applicationDirPath();
    files.push_back("/usr/share/icons/chess3/image/figure_black/");
    files.push_back("/usr/share/icons/chess3/image/figure_white/");
    files.push_back("/usr/share/icons/chess3/image/figure_blue/");
    for(int i = 0; i < 3; i++)
    {
        rook.push_back(QImage(files[i] + "rook.png"));
        bishop.push_back(QImage(files[i] + "bishop.png"));
        pawn.push_back(QImage(files[i] + "pawn.png"));
        king.push_back(QImage(files[i] + "king.png"));
        queen.push_back(QImage(files[i] + "queen.png"));
        knight.push_back(QImage(files[i] + "knight.png"));
    }

    Game::movePlayer = 0;


    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    resize(1200,700);
}

bool RectIn(int myPointX, int myPointY, vector<int> x, vector<int> y)
{
    //определяем, какие точки соединены линиями, а какие - нет
    if((x[0]+y[0] < myPointX+myPointY)&& (x[2]+y[2] > myPointX+myPointY))
    {
        if((x[3]-y[3] < myPointX+myPointY) && (x[1]-y[1] > myPointX+myPointY))
        {
            return true;
        }
    }
    return false;
}


void Board::setSquares(vector<Square*>sq)
{
    this->squares = sq;
}

void Board::start()
{
    if(Game::mode == 0)
    {
        sec++;
        if(sec >= 60)
        {
            sec = 0;
            min++;
            emit nextMin(min);
        }
        emit nextSec(sec);
    }
    else
    {
        Game::playersSecunds[Game::movePlayer] --;
        int secunds = Game::playersSecunds[Game::movePlayer];
        if(secunds < 0)
        {
            King*king=Game::players[Game::movePlayer].getKing();
            int i = (Game::movePlayer +1) % 3;
            if(Game::players[i].getPlay())
            {
                i = (Game::movePlayer +1) % 3;
            }
            king->setMate(i);
            Algoritm::takeAllFiguresToTheWinner(king);
            Algoritm::startNewMove();
            return;
        }
        int minutes = secunds / 60;
        secunds = secunds % 60;
        emit nextMin(minutes);
        emit nextSec(secunds);
    }
}

void Board::undo()
{
    if(Game::moves.size() != 0)
    {
        Square* last = Game::moves.at(Game::moves.size() - 1).getPLast();
        Square* pNew = Game::moves.at(Game::moves.size() - 1).getPNew();
        Figure *attacked = Game::moves.at(Game::moves.size() - 1).getAttackedFigure();
        Figure* moved = Game::moves.at(Game::moves.size() - 1).getMovedFigure();
        if(attacked != NULL)
        {
            attacked->setPSquare(pNew);
        }
        pNew->setPFigure(attacked);
        if(moved != NULL)
        {
            last->setPFigure(moved);
            moved->setPSquare(last);
            this->min = Game::moves.at(Game::moves.size()-1).getMin();
            this->sec = Game::moves.at(Game::moves.size()-1).getSec();
        }
        if(moved->getName() == "pawn")
        {
            Square *next = Game::moves.at(Game::moves.size() - 1).getPNextForPawn();
            bool first = Game::moves.at(Game::moves.size() - 1).getFirst();
            this->min = Game::moves.at(Game::moves.size()-1).getMin();
            this->sec = Game::moves.at(Game::moves.size()-1).getSec();
            moved->setPNext(next);
            if(first)
            {
                moved->setPFirst(first);
            }
        }

        Game::previousPlayer();
        Game::moves.pop_back();
    }
}

void Board::saveGame()
{
    if(Game::moves.size() > 0)
    {
        QTime time;
        time.currentTime();
        std::fstream file;
        QString path = QApplication::applicationDirPath();
        const string str = "/usr/share/icons/chess3/save/" + QTime::currentTime().toString("hh-mm-ss-zzz").toStdString() +".txt";
        file.open(str.c_str(), ios::out);
        int num =  Game::moves.size();
        file << num << std::endl;
        for(int i = 0; i < num; i++)
        {
            file << Game::moves[i].getMovedFigure()->getColor() << " "
                 << Game::moves[i].getPLast()->getLetter()<<  Game::moves[i].getPLast()->getNumber() << " "
                 <<Game::moves[i].getPNew()->getLetter()<<  Game::moves[i].getPNew()->getNumber() << " "
                <<Game::moves[i].getMode() << " "
                 << Game::moves[i].getMin() << " " <<
                    Game::moves[i].getSec() <<"\n";
        }
        file.close();
    }
}

void Board::loadGame()
{
    if(!load1)
    {
        this->buttonStartGame->setVisible(false);
        this->lineEditInputLoadFile->setVisible(true);
        buttonBack->setVisible(true);
        load1 = true;
    }
    else
    {
        pauseFlag = false;
        this->labelCheckMate->setVisible(false);
        Game::mode = 0;
        Game::evolution = false;
        Game::evolutionFigures.clear();
        Game::movePlayer = 0;
        Game::players.clear();
        Game::squares.clear();
        Game::theEnd = false;
        vector<Square*> squares;
        Algoritm::setSquaresOnBoard(squares);
        Algoritm::setFiguresOnBoard(squares);
        bool a = Algoritm::loadFiguresObBoard(squares, lineEditInputLoadFile->text().toStdString());
        Game::squares = squares;
        if(a)
        {
            load1 = false;
     //       this->buttonStartGame->setVisible(false);
            this->loadGameButton->setVisible(false);
            this->lineEditInputLoadFile->setVisible(false);
            this->undoButton->setVisible(true);
            this->saveGameButton->setVisible(true);

            Algoritm::startNewMove();
            t->start(1000);
            update();
        }
        else
        {
            load1 = false;
     //       this->buttonStartGame->setVisible(false);
            this->loadGameButton->setVisible(true);
            this->lineEditInputLoadFile->setVisible(false);
            this->undoButton->setVisible(false);
            this->saveGameButton->setVisible(false);
            this->buttonStartGame->setVisible(true);
        }
    }
    label->setVisible(false);
}

void Board::chooseGame()
{
    this->labelCheckMate->setVisible(false);
    this->buttonStartGame->setVisible(false);
    this->loadGameButton->setVisible(false);
    buttonMode50->setVisible(true);
    buttonMode55->setVisible(true);
    buttonModeNormal->setVisible(true);
    buttonBack->setVisible(true);
    update();
}

void Board::switchOff()
{
    lcdMinutes->setVisible(true);
    lcdSeconds->setVisible(true);
    buttonBack->setVisible(false);
    buttonPause->setVisible(true);
    undoButton->setVisible(true);
    saveGameButton->setVisible(true);
    buttonMode50->setVisible(false);
    buttonMode55->setVisible(false);
    buttonModeNormal->setVisible(false);
    this->lineEditInputLoadFile->setVisible(false);
    pauseFlag = false;
    t->start(1000);
    Game::theEnd = false;
    Game::movePlayer = 0;
    Game::evolution = false;
    Game::evolutionFigures.clear();
    Game::movePlayer = 0;
    Game::players.clear();
    Game::squares.clear();
    vector<Square*> squares;
    Algoritm::setSquaresOnBoard(squares);
    Algoritm::setFiguresOnBoard(squares);
    Game::squares = squares;
    Algoritm::startNewMove();
}

void Board::startModeNormal()
{
    Game::mode = 0;
    switchOff();
}

void Board::startMode55()
{
    Game::mode = 1;
    switchOff();
    Game::playersSecunds.push_back(600);
    Game::playersSecunds.push_back(600);
    Game::playersSecunds.push_back(600);
}

void Board::startMode50()
{
    Game::mode = 2;
    switchOff();
    Game::playersSecunds.push_back(600);
    Game::playersSecunds.push_back(600);
    Game::playersSecunds.push_back(600);
}

void Board::pause()
{
    if(pauseFlag)
    {
        labelCheckMate->setVisible(false);
        buttonStartGame->setVisible(false);
        loadGameButton->setVisible(false);
        undoButton->setVisible(true);
        saveGameButton->setVisible(true);
        t->start(1000);
        pauseFlag = false;
    }
    else
    {
        labelCheckMate->setText("PAUSE!");
        labelCheckMate->setStyleSheet("QLabel {font:20pt; background-color : black; color : white; }");
        labelCheckMate->setVisible(true);
        buttonStartGame->setVisible(true);
        loadGameButton->setVisible(true);
        undoButton->setVisible(false);
        saveGameButton->setVisible(false);
        pauseFlag = true;
        t->stop();
    }
}

void Board::back()
{
    this->load1 = false;

    buttonBack->setVisible(false);
    buttonMode50->setVisible(false);
    buttonMode55->setVisible(false);
    buttonModeNormal->setVisible(false);
    lineEditInputLoadFile->setVisible(false);
    buttonStartGame->setVisible(true);
    loadGameButton->setVisible(true);

}




void Board::mousePressEvent(QMouseEvent *me)
{
    int x = me->x();
    int y = me->y();


    //try to move figure
    if(Game::mode != -1 && !pauseFlag && !click)
    {
        click = true;
        if(!Game::evolution)
        {
            //ищем среди вариантов ходов клетку, на которую нажали
            for(int i = 0; i < variantSquares.size(); i++)
            {
                if(variantSquares.size() > 0 && variantSquares[i] != NULL && Algoritm::RectIn(x,y,variantSquares[i]->getX(),variantSquares[i]->getY()))
                {
                    /*selectedFigure = i;
                int maxX = 0, maxY = 0, minX = 800, minY = 800;
                for(int j = 0; j < 4; j++)
                {
                    if(variantSquares[i]->getX()[j] > maxX)
                    {
                        maxX = variantSquares[i]->getX()[j];
                    }

                    if(variantSquares[i]->getX()[j] < minX)
                    {
                         minX = variantSquares[i] ->getX()[j];
                    }
                    if(variantSquares[i]->getY()[j] > maxY)
                    {
                        maxY = variantSquares[i]->getY()[j];
                    }

                    if(variantSquares[i]->getY()[j] < minY)
                    {
                         minY = variantSquares[i]->getY()[j];
                    }
                }

                //смотрим попали ли мы в эту клетку?
                if(x > minX && x < maxX && y > minY && y < maxY)
                {*/
                    Figure * figure = squares[selectedFigure] -> getPFigure();
                    if(figure->getName() == "king")
                    {
                        int check = Game::players[Game::movePlayer].getKing()->getCheck();
                        if(check != -1)
                        {
                            labelCheckMate->setVisible(false);
                        }
                    }
                    if(mate != -1)
                    {
                        labelCheckMate->setVisible(false);
                        mate = -1;
                    }
                    figure -> moveFigure(variantSquares[i]);

                    Game::moves.at(Game::moves.size()-1).setSec(this->sec);
                    Game::moves.at(Game::moves.size()-1).setMin(this->min);
                    selectedFigure = -1;
                    variantSquares.clear();
                    vector<Figure*> f1 = Game::players[0].getFigures();
                    if(!Game::evolution)
                    {
                        Algoritm::startNewMove();
                    }
                    click = false;
                    return;
                }
            }
            selectedFigure = -1;

            //try to select figure
            for(int i = 0; i < squares.size(); i++)
            {
                if(squares[i] -> getPFigure() != NULL && squares[i] -> getPFigure() -> getColor() == Game::movePlayer && Algoritm::RectIn(x,y,squares[i]->getX(),squares[i]->getY()))
                    selectedFigure = i;
               /* if(squares[i] -> getPFigure() != NULL && squares[i] -> getPFigure() -> getColor() == Game::movePlayer)
                {

                    int maxX = 0, maxY = 0, minX = 800, minY = 800;
                    for(int j = 0; j < 4; j++)
                    {
                        if(squares[i]->getX()[j] > maxX)
                        {
                            maxX = squares[i]->getX()[j];
                        }

                        if(squares[i]->getX()[j] < minX)
                        {
                             minX = squares[i] ->getX()[j];
                        }
                        if(squares[i]->getY()[j] > maxY)
                        {
                            maxY = squares[i]->getY()[j];
                        }

                        if(squares[i]->getY()[j] < minY)
                        {
                             minY = squares[i]->getY()[j];
                        }
                    }

                    if(x > minX && x < maxX && y > minY && y < maxY)
                    {
            #ifdef TEST
                        if(squares[i] -> getPFigure() != NULL && squares[i] -> getPFigure() -> getColor() == Game::movePlayer)
                        {
            #endif
                            selectedFigure = i;
            #ifdef TEST
                        }
            #endif
                    }
                }*/
            }
        }
        else
        {
            for(int i = 1; i < Game::evolutionFigures.size(); i++)
            {
                int maxX = 0, maxY = 0, minX = 800, minY = 800;
                for(int j = 0; j < 4; j++)
                {
                    if( Game::evolutionFigures[i]->getX()[j] > maxX)
                    {
                        maxX =  Game::evolutionFigures[i]->getX()[j];
                    }

                    if( Game::evolutionFigures[i]->getX()[j] < minX)
                    {
                         minX =  Game::evolutionFigures[i] ->getX()[j];
                    }
                    if( Game::evolutionFigures[i]->getY()[j] > maxY)
                    {
                        maxY =  Game::evolutionFigures[i]->getY()[j];
                    }

                    if( Game::evolutionFigures[i]->getY()[j] < minY)
                    {
                         minY =  Game::evolutionFigures[i]->getY()[j];
                    }
                }

                if(x > minX && x < maxX && y > minY && y < maxY)
                {
                    Square* pawn = Game::evolutionFigures[0];
                    Figure* newFigure = Game::evolutionFigures[i] -> getPFigure();
                    string name = newFigure->getName();
                    int mode = 0;
                    if(name == "queen")
                    {
                        mode = 5;
                    }
                    else if(name == "rook")
                    {
                        mode = 3;
                    }
                    else if(name == "bishop")
                    {
                        mode = 2;
                    }
                    else if( name == "knight")
                    {
                        mode = 4;
                    }
                    Game::moves.at(Game::moves.size()-1).setMode(mode);
                    Game::moves.at(Game::moves.size()-1).setMin(this->min);
                    Game::moves.at(Game::moves.size()-1).setSec(this->sec);

                    vector<Figure*> figures = Game::players[Game::movePlayer].getFigures();
                    Figure *figure = pawn->getPFigure();


                    for(int i = 0; i < figures.size(); i++)
                    {
                        if(figures[i] == pawn->getPFigure())
                        {
                            pawn->setPFigure(newFigure);
                            newFigure->setPSquare(pawn);
                            figures[i] = newFigure;
                            break;
                        }
                    }

                    Game::players[Game::movePlayer].setFigures(figures);
                    vector<Figure*> figures2 = Game::players[Game::movePlayer].getFigures();
                    Game::evolution = false;
                    Game::nextPlayer();
                    Game::evolutionFigures.clear();
                    Algoritm::startNewMove();
                }
            }
        }
        click = false;
    }

}

QImage Board::paintFigure(Figure *figure, int color)
{
    if(figure != NULL && color <= 2 && color >= 0)
    {
        string name = figure->getName();

        if(name == "pawn")
            return pawn.at(color);
        if(name == "bishop")
            return bishop.at(color);
        if(name == "king")
            return king.at(color);
        if(name == "queen")
            return queen.at(color);
        if(name == "rook")
            return rook.at(color);
        if(name == "knight")
            return knight.at(color);
        else
            return QImage();
    }
    return QImage();
}


void Board::paintEvent(QPaintEvent *pe)
{


    Board::squares = Game::squares;
    //    connect(ui->Undo, SLOT(click()), this, SIGNAL(undo()));
    if(Game::mode != -1)
    {
        if(mate != -1)
        {
            labelCheckMate->setVisible(true);
            labelCheckMate->setText("MATE!!!");
            if(mate == 0)
            {
                 labelCheckMate->setStyleSheet("QLabel {font:20pt; background-color : black; color : white; }");
            }
            else if(mate== 1)
            {
                 labelCheckMate->setStyleSheet("QLabel {font:20pt; background-color : white; color : black; }");
            }
            else if(mate == 2)
            {
                 labelCheckMate->setStyleSheet("QLabel {font:20pt; background-color : blue; color : white; }");
            }
        }
        int check = Game::players[Game::movePlayer].getKing() -> getCheck();
        if(check != -1)
        {
            labelCheckMate->setVisible(true);
            labelCheckMate->setText("CHECK!");
            if(check == 0)
            {
                 labelCheckMate->setStyleSheet("QLabel {font:20pt; background-color : black; color : white; }");
            }
            else if(check== 1)
            {
                 labelCheckMate->setStyleSheet("QLabel {font:20pt; background-color : white; color : black; }");
            }
            else if(check == 2)
            {
                 labelCheckMate->setStyleSheet("QLabel {font:20pt; background-color : blue; color : white; }");
            }

        }
        QPainter p(this);

        QDesktopWidget desktop;
        double k = desktop.geometry().height() / 768.0;
        double P = desktop.geometry().width() / 1366.0;
        QRadialGradient gradient((int)(418*k), (int)(379*k), (int)(340*k), (int)(418*k),(int)(379*k));

        //draw boards circle
        if(Game::movePlayer == 0)
        {
            p.setBrush(Qt::black);
            gradient.setColorAt(0.85, QColor::fromRgbF(0, 0, 0, 1));
            gradient.setColorAt(0.98, QColor::fromRgbF(1, 1, 1, 0));

        }
        else if(Game::movePlayer == 1)
        {
            p.setBrush(Qt::white);
            gradient.setColorAt(0.75, QColor::fromRgbF(1, 1, 1, 1));
                gradient.setColorAt(0.98, QColor::fromRgbF(1, 0, 0, 0));
            }
            else if(Game::movePlayer == 2)
            {
                p.setBrush(Qt::blue);
                gradient.setColorAt(0.75, QColor::fromRgbF(0, 0, 1, 1));
                gradient.setColorAt(0.98, QColor::fromRgbF(1, 0, 0, 0));
            }
            else if(Game::movePlayer == 3)
            {

                //jbjkhkjnkl
            }

            //draw board!!!
            QString path = QCoreApplication::applicationDirPath();
            QImage im("/usr/share/icons/chess3/image/board.png");

            p.drawImage(desktop.geometry(),QImage("/usr/share/icons/chess3/image/wallpaper.png"));


            QBrush brush(gradient);
            p.setPen(QPen(QColor::fromRgbF(0,0,0,0)));
            p.setBrush(brush);
            p.drawEllipse((int)(418*k- 320*k), (int)(379*k-320*k), (int)(320*2*k), (int)(320*2*k));
            p.drawImage(QRect((int)(120*k),(int)(120*k),(int)(600*k),(int)(520*k)),im);


            //paint circles selected figure its moves and attack moves
            if(selectedFigure != -1 && squares[selectedFigure] -> getPFigure() != NULL)
            {
                    Figure *figure = squares[selectedFigure] -> getPFigure();


                    variantSquares = figure ->findMoves();
                    for(int i = 0; i < variantSquares.size(); i++)
                    {
                        vector<int> center = Algoritm::getCenterRect(variantSquares[i] -> getX(),variantSquares[i] -> getY());
                        QRadialGradient gr(center[0], center[1], 20, center[0], center[1]);
                        if(variantSquares[i] -> getPFigure() == NULL)
                        {
          //                  p.setBrush(Qt::green);
                            gr.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
                            gr.setColorAt(1, QColor::fromRgbF(1, 0, 0, 0));
                        }
                        else
                        {
          //                   p.setBrush(Qt::red);
                             gr.setColorAt(0, QColor::fromRgbF(1, 0, 0, 1));
                             gr.setColorAt(1, QColor::fromRgbF(1, 0, 0, 0));
                        }
                        QBrush br(gr);
                        p.setBrush(br);
                        p.drawEllipse(center[0]-20, center[1]-20, 40, 40);
                    }
                    vector<int> center = Algoritm::getCenterRect(squares[selectedFigure] -> getX(),squares[selectedFigure] -> getY());
                     QRadialGradient gr(center[0], center[1], 20, center[0], center[1]);
                     gr.setColorAt(0, QColor::fromRgbF(1, 1, 0, 1));
                     gr.setColorAt(1, QColor::fromRgbF(1, 0, 0, 0));
                     QBrush br(gr);
                     p.setBrush(br);
                     p.drawEllipse(center[0]-20, center[1]-20, 40, 40);

            }


            //draw figures images
            for(unsigned int i = 0; i < squares.size(); i++)
            {
                Figure *figure = squares[i] -> getPFigure();
                if(figure != NULL && figure->getColor() <= 2 && figure->getColor() >= 0)
                {
                    vector<int> center = Algoritm::getCenterRect(squares[i] -> getX(),squares[i] -> getY());
                    p.drawImage(QRect(center[0] - 20, center[1] - 20,40,40), paintFigure(figure, figure->getColor()));                }
            }


            if(Game::evolution)
            {
                paintEvolutionOfPawn(p, Game::evolutionFigures[0] -> getNumber(), Game::evolutionFigures[0] -> getPFigure() -> getColor());
            }
            update();
        }
if(!Game::theEnd)
{
}
    else
    {
        t->stop();
        undoButton->setVisible(false);
        saveGameButton->setVisible(false);
        buttonStartGame->setVisible(true);
        loadGameButton->setVisible(true);
        lcdMinutes->setVisible(false);
        lcdSeconds->setVisible(false);

        int number = 0;
        for(int i = 0; i < Game::players.size(); i++)
        {
            if(Game::players[i].getPlay())
            {
                number = i;
            }
        }
        if(number == 0)
        {
            label->setText(QString("Winner is black"));
        }
        else if(number == 1)
        {
            label->setText(QString("Winner is white"));
        }
        else
        {
            label->setText(QString("Winner is blue"));
        }



    }
}

void addVector(vector<int> &coord, int a, int b, int c, int d)
{
    coord.push_back(a);
    coord.push_back(b);
    coord.push_back(c);
    coord.push_back(d);
}

void Board::paintEvolutionOfPawn(QPainter &p, int number,int color)
{
    p.save();
    QRect rect(0,0,50,50);
    if(number ==8)
    {
        p.translate(143,215);
        p.rotate(-60);

    }
    else if(number == 12)
    {
        p.translate(689,211);
        p.rotate(60);

    }
    else if(number == 1)
    {
        p.translate(419,678);
    }
    else
    {
        p.restore();
        return;
    }
    p.setBrush(Qt::gray);
    p.drawRoundRect(-140, -20, 280, 50, 5, 5);
    p.translate(-140, -20);

    p.drawImage(rect,paintFigure(Game::evolutionFigures[1] -> getPFigure(), color));
    p.translate(77,0);
    p.drawImage(rect,paintFigure(Game::evolutionFigures[2]-> getPFigure(), color));
    p.translate(77,0);
    p.drawImage(rect,paintFigure(Game::evolutionFigures[3]-> getPFigure(), color));
    p.translate(77,0);
    p.drawImage(rect,paintFigure(Game::evolutionFigures[4]-> getPFigure(), color));
    p.translate(77,0);
    p.restore();
}

Board::~Board()
{
    delete ui;
}
