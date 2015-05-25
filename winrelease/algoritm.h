#ifndef ALGORITM_H
#define ALGORITM_H
#include "king.h"
#define TEST 1
#include "timer.h"
#include "move.h"
class Player;
class King;
class Algoritm
{
public:
    Algoritm();
    static vector<Square*> nextSquare(Square* last, Square* now);
    static void setFiguresOnBoard(vector<Square*> &squares);
    static void setSquaresOnBoard(vector<Square*> &sq);
    static vector<int> getCenterRect(vector<int>x, vector<int>y);
    static vector<Square*> nextDiagMove(Square *last, Square *cur);
    static Square* nextNearMove(Square *last, Square *cur);
    static bool RectIn(int myPointX, int myPointY, vector<int> x, vector<int> y);
    static Square *getSquare(char letter, int number);
    static Square *getSquare(vector<Square *> &squares, char letter, int number);
    static void markSquaresUnderAttack();
    static void clearSquares();
    static void startNewMove();
    static void takeAllFiguresToTheWinner(King *king);
    static bool loadFiguresObBoard(vector<Square *> &squares, string filename);
};

class Game
 {
 private:

 public:
    static int movePlayer;
    static vector<Square *> squares;
    static vector<Player> players;
    static vector<Move> moves;
    static bool evolution;
    static vector<Square*> evolutionFigures;
    static vector<int> playersSecunds;
    static int mode;
    static bool theEnd;

     Game(){}
     static King *getKing();
     static void nextPlayer();
     static void previousPlayer();
     static int saveGame();
     static int loadGame();
     static string toString();
};


class Player
{
private:
    vector<Figure*> figures;
    int color;
    King *king;
    bool play;
public:
    Player();
    vector<Figure *> getFigures() const;
    void setFigures(const vector<Figure *> &value);
    int getColor() const;
    void setColor(int value);
    bool getPlay() const;
    void setPlay(bool value);
    void clearFigures()
    {
        figures.clear();
    }

    void deleteFigure(Figure *value)
    {
        for(int i = 0; i < figures.size(); i++)
        {
            if(figures[i] == value)
            {
                figures.erase(figures.begin() + i);
                break;
            }
        }
    }

    void addFigure(Figure * value)
    {
        figures.push_back(value);
    }
    King* getKing() const;
    void setKing(King *king);

};

class History
{
private:
    Square* last;
    Square* next;
    string mode;
    QTimer time;
public:
    History();
    Square *getLast() const;
    void setLast(Square *value);
    Square *getNext() const;
    void setNext(Square *value);
    string getMode() const;
    void setMode(const string &value);
};


#endif // ALGORITM_H
