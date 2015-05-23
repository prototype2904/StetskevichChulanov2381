
#include "pawn.h"
#include "king.h"
#include "knight.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "fstream"
#include "algoritm.h"
#include "board.h"
#include <QCoreApplication>
#include <QDebug>
Algoritm::Algoritm()
{
}


//algoritm to find next square at line
Square* Algoritm::nextNearMove(Square *last, Square *cur)
{
    int num = -1;
    vector<Square*> nearCur;
    nearCur.push_back(cur -> getPTop());
    nearCur.push_back(cur -> getPBottom());
    nearCur.push_back(cur -> getPLeft());
    nearCur.push_back(cur -> getPRight());
    for(int i = 0; i < nearCur.size(); i++)
    {
        if(nearCur[i] != NULL && nearCur[i] != last)
        {
            vector<Square*> nearDiag= nearCur[i]->getPDiag();
            for( int j = 0; j < nearDiag.size(); j++)
            {
                if(nearDiag[j] != NULL && nearDiag[j] == last)
                {
                    num = -1;
                    break;
                }
                else
                {
                    num = i;
                }
            }

            if(num != -1)
            {
                return nearCur[i];
            }
        }
    }
    return NULL;
}

//algoritm to find next square at diagonal
vector<Square*> Algoritm::nextDiagMove(Square *last, Square *cur)
{
    vector<Square*> nextCurDiag= cur->getPDiag();
    vector<Square*> nextMoves;

    if(Game::squares[35] == last)
    {
        if(Game::squares[37] == cur)
        {
            nextMoves.push_back(Game::squares[50]);
            return nextMoves;
        }
        else if(Game::squares[28] == cur)
        {
            nextMoves.push_back(Game::squares[21]);
            return nextMoves;
        }
    }
    else if(Game::squares[36] == last)
    {
        if(Game::squares[38] == cur)
        {
            nextMoves.push_back(Game::squares[53]);
            return nextMoves;
        }
        else if(Game::squares[27] == cur)
        {
            nextMoves.push_back(Game::squares[18]);
            return nextMoves;
        }
    }
    else if(Game::squares[37] == last)
    {
        if(Game::squares[28] == cur)
        {
            nextMoves.push_back(Game::squares[21]);
            return nextMoves;
        }
        else if(Game::squares[35] == cur)
        {
            nextMoves.push_back(Game::squares[44]);
            return nextMoves;
        }
    }
    else if(Game::squares[38] == last)
    {
        if(Game::squares[27] == cur)
        {
            nextMoves.push_back(Game::squares[18]);
            return nextMoves;
        }
        else if(Game::squares[36] == cur)
        {
            nextMoves.push_back(Game::squares[47]);
            return nextMoves;
        }
    }
    else if(Game::squares[27] == last)
    {
        if(Game::squares[36] == cur)
        {
            nextMoves.push_back(Game::squares[47]);
            return nextMoves;
        }
        else if(Game::squares[38] == cur)
        {
            nextMoves.push_back(Game::squares[53]);
            return nextMoves;
        }
    }
    else if(Game::squares[28] == last)
    {
        if(Game::squares[37] == cur)
        {
            nextMoves.push_back(Game::squares[50]);
            return nextMoves;
        }
        else if(Game::squares[35] == cur)
        {
            nextMoves.push_back(Game::squares[44]);
            return nextMoves;
        }
    }
    for(int i = 0; i < nextCurDiag.size(); i++)
    {
        int good = false;
        if(nextCurDiag[i] != NULL && nextCurDiag[i] != last)
        {

            vector<Square*> nearNextCurDiag;
            nearNextCurDiag.push_back(nextCurDiag[i] -> getPTop());
            nearNextCurDiag.push_back(nextCurDiag[i] -> getPBottom());
            nearNextCurDiag.push_back(nextCurDiag[i] -> getPLeft());
            nearNextCurDiag.push_back(nextCurDiag[i] -> getPRight());

            for(int j = 0; j < nearNextCurDiag.size(); j++)
            {
                if(nearNextCurDiag[j] != NULL)
                {
                    vector<Square*> nearNextCurDiag2;
                    nearNextCurDiag2.push_back(nearNextCurDiag[j] -> getPTop());
                    nearNextCurDiag2.push_back(nearNextCurDiag[j] -> getPBottom());
                    nearNextCurDiag2.push_back(nearNextCurDiag[j] -> getPLeft());
                    nearNextCurDiag2.push_back(nearNextCurDiag[j] -> getPRight());

                    for(int k = 0; k < nearNextCurDiag2.size(); k++)
                    {
                        if(nearNextCurDiag2[k] != NULL && nearNextCurDiag2[k] == last )
                        {
                            good = false;
                            break;
                        }
                        else
                        {
                            good = true;
                        }
                    }
                    if(!good)
                    {
                        break;
                    }
                }
            }
            if(good)
            {
                nextMoves.push_back(nextCurDiag[i]);
            }
        }
    }
    try{
        if(nextMoves.size() == 2)
        {
            int flag = 1;

            if(last == Game::squares[44] && cur == Game::squares[35])
            {
                flag = 2;
            }
            else if(last != Game::squares[44] && cur == Game::squares[35])
            {
                flag = 0;
            }


            if(last == Game::squares[47] && cur == Game::squares[36])
            {
                flag = 2;
            }
            else if(last != Game::squares[47] && cur == Game::squares[36])
            {
                flag = 0;
            }


            if(last == Game::squares[50] && cur == Game::squares[37])
            {
                flag = 2;
            }
            else if(last != Game::squares[50] && cur == Game::squares[37])
            {
                flag = 0;
            }

            if(last == Game::squares[53] && cur == Game::squares[38])
            {
                flag = 2;
            }
            else if(last != Game::squares[53] && cur == Game::squares[38])
            {
                flag = 0;
            }

            if(last == Game::squares[21] && cur == Game::squares[28])
            {
                flag = 2;
            }
            else if(last != Game::squares[21] && cur == Game::squares[28])
            {
                flag = 0;
            }

            if(last == Game::squares[18] && cur == Game::squares[27])
            {
                flag = 2;
            }
            else if(last != Game::squares[18] && cur == Game::squares[27])
            {
                flag = false;
            }

            if(flag == 0)
            {
                for( int i = 0; i < nextMoves.size(); i++)
                {
                    if(nextMoves[i] == Game::squares[27])
                    {
                        nextMoves.erase(nextMoves.begin() + i--);
                    }
                    else if(nextMoves[i] == Game::squares[28])
                    {
                        nextMoves.erase(nextMoves.begin() + i--);
                    }
                    else if(nextMoves[i] == Game::squares[38])
                    {
                        nextMoves.erase(nextMoves.begin() + i--);
                    }
                    else if(nextMoves[i] == Game::squares[37])
                    {
                        nextMoves.erase(nextMoves.begin() + i--);
                    }
                    else if(nextMoves[i] == Game::squares[36])
                    {
                        nextMoves.erase(nextMoves.begin() + i--);
                    }
                    else if(nextMoves[i] == Game::squares[35])
                    {
                        nextMoves.erase(nextMoves.begin() + i--);
                    }
                }
            }
        }

    }
    catch(...)
    {
        qDebug() << "vector";
    }
    return nextMoves;
}


//find next square after last and current square
vector<Square*> Algoritm::nextSquare(Square *last, Square *now)
{
   vector<Square*> sqNow;
   sqNow.push_back(now->getPTop());
   sqNow.push_back(now->getPBottom());
   sqNow.push_back(now->getPLeft());
   sqNow.push_back(now->getPRight());
   sqNow.push_back(now->getPDiag()[0]);
   sqNow.push_back(now->getPDiag()[1]);
   sqNow.push_back(now->getPDiag()[2]);
   sqNow.push_back(now->getPDiag()[3]);
   sqNow.push_back(now->getPDiag()[4]);

   vector<Square*> sqLast;
   sqLast.push_back(last->getPTop());
   sqLast.push_back(last->getPBottom());
   sqLast.push_back(last->getPLeft());
   sqLast.push_back(last->getPRight());
   sqLast.push_back(last->getPDiag()[0]);
   sqLast.push_back(last->getPDiag()[1]);
   sqLast.push_back(last->getPDiag()[2]);
   sqLast.push_back(last->getPDiag()[3]);
   sqLast.push_back(last->getPDiag()[4]);

    vector<Square*>squares;
    int number = -1;
    for(int i = 0; i < 8; i++)
    {
        if(sqLast[i] == now)
        {
            number = i;
        }
    }

    if(number >=4 && sqNow[8] != NULL)
    {
        squares.push_back(sqNow[8]);
    }

    if(number != -1)
        squares.push_back(sqNow[number]);
    return squares;
}


//algoritm to set figure on board
void Algoritm::setFiguresOnBoard(vector<Square *> &squares)
{
    Player zero, first, second;
    King *zeroKing, *firstKing, *secondKing;

    //Zero team(front)
    zero.setColor(0);
    zero.setPlay(true);
    for(int i = 8; i <= 15; i++)
    {
        squares[i] -> setPFigure(new Pawn(squares[i], squares[i + 8], 0));
        zero.addFigure(squares[i] -> getPFigure());
    }
    squares[0] -> setPFigure(new Rook(squares[0],0));
    zero.addFigure(squares[0] -> getPFigure());
    squares[7] -> setPFigure(new Rook(squares[7],0));
     zero.addFigure(squares[7] -> getPFigure());

    squares[1] -> setPFigure(new Knight(squares[1],0));
     zero.addFigure(squares[1] -> getPFigure());
    squares[6] -> setPFigure(new Knight(squares[6],0));
     zero.addFigure(squares[6] -> getPFigure());

    squares[2] -> setPFigure(new Bishop(squares[2],0));
     zero.addFigure(squares[2] -> getPFigure());
    squares[5] -> setPFigure(new Bishop(squares[5],0));
     zero.addFigure(squares[5] -> getPFigure());

    squares[3] -> setPFigure(new Queen(squares[3],0));
     zero.addFigure(squares[3] -> getPFigure());
     zeroKing = new King(squares[4],0);
    squares[4] -> setPFigure(zeroKing);
     zero.addFigure(squares[4] -> getPFigure());


    //First Team(left side);
     first.setColor(1);
     first.setPlay(true);
    for(int i = 56; i < 62; i++)
    {
        squares[i] -> setPFigure(new Pawn(squares[i], squares[i - 14], 1));
         first.addFigure(squares[i] -> getPFigure());
    }
    squares[62] -> setPFigure(new Pawn(squares[62], squares[63], 1));
    first.addFigure(squares[62] -> getPFigure());
    squares[82] -> setPFigure(new Pawn(squares[82], squares[83], 1));
    first.addFigure(squares[82] -> getPFigure());

    squares[74] -> setPFigure(new Rook(squares[74],1));
    first.addFigure(squares[74] -> getPFigure());
    squares[81] -> setPFigure(new Rook(squares[81],1));
    first.addFigure(squares[81] -> getPFigure());

    squares[75] -> setPFigure(new Knight(squares[75],1));
    first.addFigure(squares[75] -> getPFigure());
    squares[80] -> setPFigure(new Knight(squares[80],1));
    first.addFigure(squares[80] -> getPFigure());

    squares[76] -> setPFigure(new Bishop(squares[76],1));
    first.addFigure(squares[76] -> getPFigure());
    squares[79] -> setPFigure(new Bishop(squares[79],1));
    first.addFigure(squares[79] -> getPFigure());

    squares[78] -> setPFigure(new Queen(squares[78],1));
    first.addFigure(squares[78] -> getPFigure());
    firstKing = new King(squares[77],1);
    squares[77] -> setPFigure(firstKing);
    first.addFigure(squares[77] -> getPFigure());

    //Second Team(right side);

    second.setColor(2);
    second.setPlay(true);
    for(int i = 68; i < 74; i++)
    {
        squares[i] -> setPFigure(new Pawn(squares[i], squares[i - 18], 2));
        second.addFigure(squares[i] -> getPFigure());
    }
    squares[67] -> setPFigure(new Pawn(squares[67], squares[66], 2));
    second.addFigure(squares[67] -> getPFigure());
    squares[87] -> setPFigure(new Pawn(squares[87], squares[86], 2));
    second.addFigure(squares[87] -> getPFigure());

    squares[88] -> setPFigure(new Rook(squares[88],2));
    second.addFigure(squares[88] -> getPFigure());
    squares[95] -> setPFigure(new Rook(squares[95],2));
    second.addFigure(squares[95] -> getPFigure());

    squares[89] -> setPFigure(new Knight(squares[89],2));
    second.addFigure(squares[89] -> getPFigure());
    squares[94] -> setPFigure(new Knight(squares[94],2));
    second.addFigure(squares[94] -> getPFigure());

    squares[90] -> setPFigure(new Bishop(squares[90],2));
    second.addFigure(squares[90] -> getPFigure());
    squares[93] -> setPFigure(new Bishop(squares[93],2));
    second.addFigure(squares[93] -> getPFigure());

    squares[91] -> setPFigure(new Queen(squares[91],2));
    second.addFigure(squares[91] -> getPFigure());
    secondKing = new King(squares[92],2);
    squares[92] -> setPFigure(secondKing);
    second.addFigure(squares[92] -> getPFigure());

    Game::players.push_back(zero);
    Game::players.push_back(first);
    Game::players.push_back(second);

    Game::players[0].setKing(zeroKing);
    Game::players[1].setKing(firstKing);
    Game::players[2].setKing(secondKing);
}

//algoritm to set squares on board
void Algoritm::setSquaresOnBoard(vector<Square *> &sq)
{
    std::fstream file;
    QString path = QCoreApplication::applicationDirPath();
    string ss = path.toStdString() + "/squares/squares.txt";
    file.open(ss.c_str());

    for(int i = 0; i < 96; i++)
    {
        Square *newSquare = new Square();
        sq.push_back(newSquare);
    }
    int num = 0;
    char let[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
    if(file.is_open() )
    {

        while(!file.eof()&& num < 96)
        {

            vector<Square*> pDiag;
            vector<Square*> squares;
            int s, d, letter, number;

            for(int j = 0 ; j < 4; j++)
            {
                file >> s;
                if(s == -1)
                {
                    squares.push_back(NULL);
                }
                else
                {
                    squares.push_back(sq[s]);
                }
            }
           for(int j = 0; j < 5; j++)
            {
                file >> d;
                if(d == -1)
                {
                    pDiag.push_back(NULL);
                }
                else
                {
                    pDiag.push_back(sq[d]);
                }
            }
            file >> letter;
            file >> number;
            sq[num++]->set(squares[0], squares[1], squares[2], squares[3], pDiag, let[letter],number);
        }
    }
    else
    {
        Game::theEnd = true;
    }
    file.close();
    ss = path.toStdString() + "/squares/coord1200700120120600520.txt";
    file.open(ss.c_str());
    if(file.is_open())
    {
        num = 0;
        int x1, y1;
        while(num < 96)
        {
            for(int i = 0; i < 4; i++)
            {
                file >> x1 >> y1 ;

                sq[num] -> setCoord(x1, y1);
            }

            num++;
        }
    }
    else
    {
        Game::theEnd = true;
    }
}

//algoritm to get center of square if we have vectors their coordinates.
vector<int> Algoritm::getCenterRect(vector<int> x, vector<int> y)
{
    vector<int> center;
    center.push_back((x[0]+x[1]+x[2]+x[3])/4);
    center.push_back((y[0]+y[1]+y[2]+y[3])/4);
    return center;
}




bool Algoritm::RectIn(int myPointX, int myPointY,vector<int>x, vector<int>y)
{
    if(myPointX == x[0])
    {
        if((x[1]-x[0])*(x[3]-x[0])>0)
            return false;
    }
    else
    {
        if((y[1]-(myPointY-y[0])*(x[1]-x[0])/(myPointX-x[0])-y[0])*
                (y[3]-(myPointY-y[0])*(x[3]-x[0])/(myPointX-x[0])-y[0])>0)
            return false;
    }
    if(myPointX == x[2])
    {
        if((x[1]-x[2])*(x[3]-x[2])>0)
            return false;
    }
    else
    {
        if((y[1]-(myPointY-y[2])*(x[1]-x[2])/(myPointX-x[2])-y[2])*
                (y[3]-(myPointY-y[2])*(x[3]-x[2])/(myPointX-x[2])-y[2])>0)
            return false;
    }
    if(myPointX == x[1])
    {
        if((x[0]-x[1])*(x[2]-x[1])>0)
            return false;
    }
    else
    {
        if((y[0]-(myPointY-y[1])*(x[0]-x[1])/(myPointX-x[1])-y[1])*
                (y[2]-(myPointY-y[1])*(x[2]-x[1])/(myPointX-x[1])-y[1])>0)
            return false;
    }

    return true;

}

Square* Algoritm::getSquare(vector<Square *> &squares,char letter, int number)
{
    for(int i = 0; i < squares.size(); i++)
    {
        int num = squares[i]->getNumber();
        char let = squares[i]->getLetter();
        if(num == number && let == letter)
        {
            return squares[i];
        }
    }
    return NULL;
}


void Algoritm::markSquaresUnderAttack()
{
    for(int i = 0; i < Game::players.size(); i++)
    {
        if(Game::players[i].getPlay() && Game::movePlayer != i)
        {
            int color = Game::players[i].getColor();
            vector<Figure*> figures = Game::players[i].getFigures();
            for(int j = 0; j < figures.size(); j++)
            {
                Figure* figure = figures[j];
                vector<Square*> squares;
                if(figure->getName() !="pawn" && figure->getName() !="king")
                {
                    squares = figure->findMoves();
                }
                else if(figure->getName() =="pawn")
                {
                    squares = figure -> findAttackForMark();
                }

                for(int k = 0; k < squares.size(); k++)
                {
                    squares[k]->setMark(color);
                }
            }
        }

    }
    vector<Figure*> f1 = Game::players[0].getFigures();
    vector<Figure*> f2 = Game::players[1].getFigures();
    vector<Figure*> f3 = Game::players[2].getFigures();

    int a =  Game::players.size();
    for(int i = 0; i < Game::players.size(); i++)
    {
        if(Game::players[i].getPlay() && Game::movePlayer != i)
        {
             int color = Game::players[i].getColor();
             King *king = Game::players[i].getKing();
             vector<Square*> squares = king->findMoves();
             for(int k = 0; k < squares.size(); k++)
             {
                 squares[k]->setMark(color);
             }
        }
    }
}



void Algoritm::clearSquares()
{
    for(int i = 0; i < Game::squares.size(); i++)
    {
        Game::squares[i]->clearMark();
    }
}


bool are_there_any_players()
{
    int number = 0;
    for(int i = 0; i < Game::players.size(); i++)
    {
        if(Game::players[i].getPlay())
        {
            number++;
        }
    }
    if(number >= 2)
    {
        return true;
    }
    return false;

}

void Algoritm::takeAllFiguresToTheWinner(King *king)
{
    int color = king->getMate();
    vector<Figure*> figures = Game::players[Game::movePlayer].getFigures();

    Board::mate = color;
    for(int i = 0; i < figures.size(); i++)
    {
        if(figures[i] -> getName() != "king")
        {
            figures[i] -> setColor(color);

            Game::players[color].addFigure(figures[i]);
        }
        else
        {

        }
    }
    Game::players[Game::movePlayer].clearFigures();
    king->getPSquare()->setPFigure(NULL);
    if(!are_there_any_players())
    {
        Game::theEnd = true;
    }
}



void Algoritm::startNewMove()
{
    if(are_there_any_players())
    {
        clearSquares();

    //    markSquaresUnderAttack();
        int i = Game::movePlayer;
        King *king = Game::players[i].getKing();
        Square* sq = king->getPSquare();
        sq->setPFigure(NULL);
        markSquaresUnderAttack();
        sq->setPFigure(king);
        vector<Player> players = Game::players;
        king->setCheck(-1);

        if(king->getPSquare() -> is_UnderAttack(king->getColor()))
        {
            king->setCheck(king->getPSquare()->getAttackPlayer());
            vector<Square*> moves = king->findMoves();
            if(moves.size() == 0)
            {
                king->setMate(king->getPSquare()->getAttackPlayer());
                 Game::players[i].setPlay(false);
                takeAllFiguresToTheWinner(king);
                Game::nextPlayer();
            }
        }
        else
        {
            vector<Square*> moves = king->findMoves();
            vector<Figure*> f0 = players[Game::movePlayer].getFigures();
            bool pat = true;
            if(moves.size() == 0)
            {
                for(int i = 0; i < f0.size();i++)
                {
                    if(f0[i]->findMoves().size()>0)
                    {
                        pat = false;
                        break;
                    }
                }
                if(pat)
                {
                    int color = (Game::movePlayer + 1)%3;
                    if(!Game::players[color].getPlay())
                    {
                        color = (Game::movePlayer + 1)%3;
                    }
                    king->setMate(color);
                    takeAllFiguresToTheWinner(king);
                    Game::players[i].setPlay(false);
                    Game::nextPlayer();
                }
            }
        }
    }
    else
    {
        Game::theEnd = true;
    }
}

/*
Square* getSquare(Square *sq)
{
    vector<Figure*> figures = Game::players[sq->getColor()].getFigures();

    for(int i = 0; figures.size();i++)
    {
        Square* sq2 = figures[i] -> getPSquare();
        if(sq == sq2)
        {
            return sq->getPFigure();
        }
    }
}
*/
bool Algoritm::loadFiguresObBoard(vector<Square *> &squares, string filename)
{
    Game::squares.clear();

    std::fstream file;
    QString path = QCoreApplication::applicationDirPath();
    string str = path.toStdString()+ "/" + filename + ".txt";
    file.open(str.c_str());

    Game::moves.clear();
    int color;
    if(file.is_open())
    {
        try{
            int num = 0;
            file >> num;
            for(int i = 0 ; i < num; i++)
            {
                char lastL;
                int lastN;
                char newL;
                int newN;
                int mode;
                int min;
                int sec;
                file >> color >> lastL >> lastN >> newL >> newN >> mode >> min >> sec;
                if(color >= 0 && color < 3 && lastL >= 'a' && lastL <= 'l'
                        && newL >= 'a' && newL <= 'l' && lastN>=1 && lastN <=12
                        && newN >=1 && newN<=12 && mode >= 0 && mode <= 7)
                {
                    Game::movePlayer = color;
                    Square* pLast = getSquare(squares,lastL, lastN);
                    Square* pNew = getSquare(squares,newL, newN);
                    vector<Player> players = Game::players;

                    vector<Figure*> f0= Game::players[0].getFigures();
                    vector<Figure*> f1= Game::players[1].getFigures();
                    vector<Figure*> f2= Game::players[2].getFigures();



                    vector<Move> moves = Game::moves;
                    if(pLast != NULL && pNew != pLast)
                    {
                        Figure* figure = pLast->getPFigure();
                        if(mode == 0)
                        {
                            figure->moveFigure(pNew);
                        }
                        else if(mode == 1)
                        {
                            //CASTLING
                        }
                        else if(mode >= 2)
                        {
                            figure->moveFigure(pNew);

                            int a = 0;
                            vector<Figure*> figures = Game::players[figure->getColor()].getFigures();
                            for(int i = 0; i < figures.size(); i++)
                            {
                                if(figures[i] == figure)
                                {
                                    a = i;
                                }
                            }
                            Square* pawn = pNew;
                            Figure* newFigure;

                            if(mode == 2)
                            {
                                figure = new Bishop(pawn, figure->getColor());
                            }
                            else if(mode == 3)
                            {
                                figure = new Rook(pawn, figure->getColor());
                            }
                            else if(mode == 4)
                            {
                                figure = new Knight(pawn, figure->getColor());
                            }
                            else if(mode = 5)
                            {
                                figure = new Queen(pawn, figure->getColor());
                            }


                            pNew->setPFigure(figure);

                            Game::players[figure->getColor()].deleteFigure(figures[a]);
                            Game::players[figure->getColor()].addFigure(figure);
                            Game::evolution = false;
                            Game::evolutionFigures.clear();
                        }
                        else
                        {
                            break;
                        }
                        Game::moves.at(Game::moves.size()-1).setMin(min);
                        Game::moves.at(Game::moves.size()-1).setSec(sec);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if(Game::evolution == false)
            {
                Game::movePlayer = (color + 1) % 3;
            }
        }
        catch(...)
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}


//
King *Game::getKing()
{
    return Game::players[Game::movePlayer].getKing();
}

void Game::nextPlayer()
{
    movePlayer = (++movePlayer) % 3;

    if(!Game::players[movePlayer].getPlay())
    {
         movePlayer =(++movePlayer) % 3;
    }
    if(!Game::players[movePlayer].getPlay())
    {
         movePlayer =(++movePlayer) % 3;
    }
    //Winner
}


void Game::previousPlayer()
{
    movePlayer--;
    if(movePlayer == -1)
    {
        movePlayer = 2;
    }
}

int Game::saveGame()
{
    return 1;
}

string Game::toString()
{
    qDebug()<< "/n/n This is moves!!! \n";
    for(int i = 0; i < moves.size(); i++)
    {
        qDebug() << moves[i].getMovedFigure()->getColor()
                <<moves[i].getPLast()->getLetter()<<  moves[i].getPLast()->getNumber() << " "
                <<moves[i].getPNew()->getLetter()<<  moves[i].getPNew()->getNumber() << " "
               <<moves[i].getMode() << " " << moves[i].getMin()<< " " << moves[i].getSec();
    }
    return ";";
}

