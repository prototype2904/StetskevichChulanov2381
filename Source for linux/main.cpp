#include <QApplication>
#include <QQmlApplicationEngine>
#include "form.h"
#include "board.h"
#include "test.h"
#include "fstream"
vector<Square*> Game::squares;
vector<Square*> Game::evolutionFigures;
vector<Player> Game::players;
vector<int> Game::playersSecunds;
int Game::mode = -1;
int Game::movePlayer;
vector<Move> Game::moves;
bool Game::theEnd = false;
bool Game::evolution = false;
int Board::mate = -1;
int main(int argc, char *argv[])
{
    qDebug() << QString( QCoreApplication::applicationDirPath());
    vector<Square*> sq;
   // Algoritm::setSquaresOnBoard(sq);
  //  Algoritm::setFiguresOnBoard(sq);
  //  Test::testPawnEvolution(sq);

    Game::squares = sq;
    QApplication app(argc, argv);
    Board w;
    w.setSquares(sq);
    w.show();
 //   QQmlApplicationEngine engine;
 //   engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
