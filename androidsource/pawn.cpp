#include "pawn.h"
#include "algoritm.h"
#include "sqaure.h"
#include <QRect>
#include "queen.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include <QDebug>

Pawn::Pawn():Figure(-1, NULL, "pawn")
{
    firstMove = true;
}

vector<Square *> Pawn::findAttackForMark()
{

    vector<Square*> diag = this->getPSquare()->getPDiag();
    vector<Square*> attack;



    //check 5 diaganls, pawn attack at diag's
    for(int i = 0; i < 5; i++)
    {
        if(diag[i] != NULL)
        {


            if(diag[i]->getPLeft() == nextMove )
            {
                attack.push_back(diag[i]);
            }
            if(diag[i]->getPRight() == nextMove )
            {
                attack.push_back(diag[i]);
            }
            if(diag[i]->getPTop() == nextMove)
            {
                attack.push_back(diag[i]);
            }
            if(diag[i]->getPBottom() == nextMove)
            {
                attack.push_back(diag[i]);
            }
        }
    }
    return attack;
}

Pawn::Pawn(Square *sq, Square *nextMove, int color):Figure(color, sq, "pawn")
{
    this->nextMove = nextMove;
    firstMove = true;
}

void addVector2(vector<int> &coord, int a, int b, int c, int d)
{
    coord.push_back(a);
    coord.push_back(b);
    coord.push_back(c);
    coord.push_back(d);
}

void Pawn::evolution()
{
    int color = this->getColor();
    Game::evolutionFigures.clear();
    QRect rect(0,0,50,50);
    Square* knight = new Square();
    Square* rook = new Square();
    Square* bishop = new Square();
    Square* queen = new Square();
    int number = this->getPSquare()->getNumber();
    if(number == 8)
    {
        vector<int> knightX, knightY, rookX, rookY,bishopX, bishopY,queenX, queenY;
        addVector2(knightX, 98, 60,86,126);
        addVector2(knightY, 348,324,275,301);
        addVector2(bishopX, 137, 95,124,166);
        addVector2(bishopY, 282,261,209,235);
        addVector2(rookX, 175, 136,157,201);
        addVector2(rookY, 216,196,150,176);
        addVector2(queenX, 211, 170,194,238);
        addVector2(queenY, 150,124,84,109);

        knight->setX(knightX);
        knight->setY(knightY);
        bishop->setX(bishopX);
        bishop->setY(bishopY);
        rook->setX(rookX);
        rook->setY(rookY);
        queen->setX(queenX);
        queen->setY(queenY);

        knight->setPFigure(new Knight(knight, color));
        bishop->setPFigure(new Bishop(bishop, color));
        rook->setPFigure(new Rook(rook, color));
        queen->setPFigure(new Queen(queen, color));

    }
    else if(number == 12)
    {
        vector<int> knightX, knightY, rookX, rookY,bishopX, bishopY,queenX, queenY;
        addVector2(knightX, 593, 634,660,620);
        addVector2(knightY, 114,90,130,158);
        addVector2(bishopX, 631, 675,696,655);
        addVector2(bishopY, 181,156,193,222);
        addVector2(rookX, 670, 714, 735, 696);
        addVector2(rookY, 247,222,260,291);
        addVector2(queenX, 710, 749,775,734);
        addVector2(queenY, 314,287,331,356);

        knight->setX(knightX);
        knight->setY(knightY);
        bishop->setX(bishopX);
        bishop->setY(bishopY);
        rook->setX(rookX);
        rook->setY(rookY);
        queen->setX(queenX);
        queen->setY(queenY);

        knight->setPFigure(new Knight(knight, color));
        bishop->setPFigure(new Bishop(bishop, color));
        rook->setPFigure(new Rook(rook, color));
        queen->setPFigure(new Queen(queen, color));

    }
    else if(number == 1)
    {
        vector<int> X, knightY, rookY, bishopY, queenY;
        addVector2(X, 702, 662,662,702);
        addVector2(knightY, 281,281,334,334);
        addVector2(bishopY, 355,355,402,402);
        addVector2(rookY, 437,437,475,475);
        addVector2(queenY, 493,493,558,558);

        knight->setY(X);
        knight->setX(knightY);
        bishop->setY(X);
        bishop->setX(bishopY);
        rook->setY(X);
        rook->setX(rookY);
        queen->setY(X);
        queen->setX(queenY);

        knight->setPFigure(new Knight(knight, color));
        bishop->setPFigure(new Bishop(bishop, color));
        rook->setPFigure(new Rook(rook, color));
        queen->setPFigure(new Queen(queen, color));
    }
    else
    {
        return;
    }
    Game::evolutionFigures.push_back(this->getPSquare());
    Game::evolutionFigures.push_back(knight);
    Game::evolutionFigures.push_back(bishop);
    Game::evolutionFigures.push_back(rook);
    Game::evolutionFigures.push_back(queen);
    Game::evolution = true;
}

void Pawn::specialAttackFunction(Square *newSquare)
{
    Figure *thisFigure = this->getPSquare()->getPFigure();
    Figure *lastFigure = newSquare->getPFigure();
    int color = lastFigure->getColor();
    Game::players[color].deleteFigure(lastFigure);

    this -> getPSquare() -> setPFigure(NULL);
    this -> setPSquare(newSquare);
    this -> getPSquare()-> setPFigure(thisFigure);

    if(Game::mode == 1)
    {
        Game::playersSecunds[Game::movePlayer] += 5;
    }
    Game::nextPlayer();
}

void Pawn::moveFigure(Square *newSquare)
{
    Figure *lastFigure = newSquare->getPFigure();
    Figure *thisFigure = this->getPSquare()->getPFigure();

    Move move;
    move.setNewMove(this->getPSquare(), newSquare,thisFigure,lastFigure, nextMove, firstMove);
    Game::moves.push_back(move);
    qDebug() << "firstPoint";
    //if new square empty, we find next square
    if(newSquare->getPFigure() == NULL)
    {   
        Square* squares[] = {this->getPSquare()->getPTop(),
                              this->getPSquare()->getPBottom(),
                              this->getPSquare()->getPLeft(),
                              this->getPSquare()->getPRight()};


        for(int i = 0; i < 4; i++)
        {
            if(newSquare != squares[i])
            {
                qDebug() << "21Point";
                Square* squares2[] = {NULL,
                                     NULL,
                                     NULL,
                                     NULL};
                if(squares[i] != NULL)
                {
                    squares2[0] = squares[i]->getPTop();
                    squares2[1] = squares[i]->getPBottom();
                    squares2[2] = squares[i]->getPLeft(),
                    squares2[3] = squares[i]->getPRight();
                }

                qDebug() << "211Point";
                for(int j = 0; j < 4; j++)
                {

                    if(squares2[j] == newSquare)
                    {
                        qDebug() << "211Point";
                        Square*next = Algoritm::nextNearMove(squares[i], newSquare);
                        if(next != NULL)
                        {
                            qDebug() << "2111Point";
                            this->nextMove = next;
                            this->firstMove=false;
                            Figure *thisFigure = this->getPSquare()->getPFigure();
                            this -> getPSquare() -> setPFigure(NULL);
                            this -> setPSquare(newSquare);
                            this -> getPSquare()-> setPFigure(thisFigure);
                            if(Game::mode == 1)
                            {
                                Game::playersSecunds[Game::movePlayer] += 5;
                            }
                            Game::nextPlayer();
                            return;
                        }
                        else
                        {
                            qDebug() << "212Point";
                            Figure *thisFigure = this->getPSquare()->getPFigure();
                            this -> getPSquare() -> setPFigure(NULL);
                            this -> setPSquare(newSquare);
                            this -> getPSquare()-> setPFigure(thisFigure);
                            evolution();


                            return;
                        }
                    }
                }
            }
            else
            {
                qDebug() << "22Point";
                Square*next = Algoritm::nextNearMove(this->getPSquare(), newSquare);
                if(next != NULL)
                {
                    this->nextMove = next;
                    this->firstMove=false;
                    Figure *thisFigure = this->getPSquare()->getPFigure();
                    this -> getPSquare() -> setPFigure(NULL);
                    this -> setPSquare(newSquare);
                    this -> getPSquare()-> setPFigure(thisFigure);
                    Game::nextPlayer();
                    return;
                }
                else
                {
                    //EVOLUTION and there
                    Figure *thisFigure = this->getPSquare()->getPFigure();
                    this -> getPSquare() -> setPFigure(NULL);
                    this -> setPSquare(newSquare);
                    this -> getPSquare()-> setPFigure(thisFigure);
                    evolution();
                    return;
                }
            }
        }
    }
    //else we change line
    else
    {

        Square *cur = this->getPSquare();

        if(cur == Game::squares[28] && nextMove == Game::squares[38])
        {
            if(newSquare == Game::squares[37])
            {
                nextMove = Game::squares[51];

                specialAttackFunction(newSquare);
                return;
            }
            else if(newSquare == Game::squares[35])
            {
                nextMove = Game::squares[45];
                specialAttackFunction(newSquare);

                return;
            }
        }
        else if(cur == Game::squares[27] && nextMove == Game::squares[35])
        {
            if(newSquare == Game::squares[36])
            {
                nextMove = Game::squares[46];

                specialAttackFunction(newSquare);
                return;
            }
            else if(newSquare == Game::squares[38])
            {
                nextMove = Game::squares[52];
                specialAttackFunction(newSquare);

                return;
            }
        }
        else if(cur == Game::squares[35] && nextMove == Game::squares[27])
        {
            if(newSquare == Game::squares[28])
            {
                nextMove = Game::squares[20];

                specialAttackFunction(newSquare);
                return;
            }
            else if(newSquare == Game::squares[35])
            {
                nextMove = Game::squares[51];
                specialAttackFunction(newSquare);

                return;
            }
        }
        else if(cur == Game::squares[36] && nextMove == Game::squares[37])
        {
            if(newSquare == Game::squares[38])
            {
                nextMove = Game::squares[52];

                specialAttackFunction(newSquare);
                return;
            }
            else if(newSquare == Game::squares[27])
            {
                nextMove = Game::squares[19];
                specialAttackFunction(newSquare);

                return;
            }
        }
        else if(cur == Game::squares[37] && nextMove == Game::squares[36])
        {
            if(newSquare == Game::squares[35])
            {
                nextMove = Game::squares[45];

                specialAttackFunction(newSquare);
                return;
            }
            else if(newSquare == Game::squares[28])
            {
                nextMove = Game::squares[27];
                specialAttackFunction(newSquare);

                return;
            }
        }
        else if(cur == Game::squares[38] && nextMove == Game::squares[28])
        {
            if(newSquare == Game::squares[27])
            {
                nextMove = Game::squares[19];

                specialAttackFunction(newSquare);
                return;
            }
            else if(newSquare == Game::squares[36])
            {
                nextMove = Game::squares[46];
                specialAttackFunction(newSquare);

                return;
            }
        }

        qDebug() << "secondPoint";


        Square* squares[] = {newSquare->getPTop(),
                              newSquare->getPBottom(),
                              newSquare->getPLeft(),
                              newSquare->getPRight()};
        for(int i = 0; i < 4; i++)
        {

            if(squares[i] != NULL && squares[i]->getNumber() == this->getPSquare()->getNumber())
            {
                Square*next = Algoritm::nextNearMove(squares[i], newSquare);
                if(next != NULL)
                {
                    nextMove = next;
                    this->firstMove=false;
                    Figure *thisFigure = this->getPSquare()->getPFigure();
                    this -> getPSquare() -> setPFigure(NULL);
                    this -> setPSquare(newSquare);
                    if(Game::mode == 1)
                    {
                        Game::playersSecunds[Game::movePlayer] += 5;
                    }
                    Game::nextPlayer();
                    this -> getPSquare()-> setPFigure(thisFigure);
                    return;
                }
                else
                {
                    Figure *thisFigure = this->getPSquare()->getPFigure();
                    this -> getPSquare() -> setPFigure(NULL);
                    this -> setPSquare(newSquare);
                    this -> getPSquare()-> setPFigure(thisFigure);


                    //onlythere!!!!
                    //EVOLUTION!!!!

                    evolution();
                    return;
                }

            }
        }
    }
}

void Pawn::setPFirst(bool first)
{
    this->firstMove = first;
}

vector<Square *> Pawn::findMoves()
{
    vector<Square*> moves;
    vector<Square*> next;
    King *king = Game::getKing();

    if(king->getCheck() == -1)
    {
        if(this->nextMove == this->getPSquare())
        {
            //evolution

        }
        if(nextMove -> getPFigure() == NULL)
        {

            //check king nuder aatack or not!!!!
            //if not
            moves.push_back(nextMove);
            next = Algoritm::nextSquare(this->getPSquare(), nextMove);
            qDebug() << firstMove;
            qDebug() << (next.at(0) != NULL);
            qDebug() << (next.at(0) -> getPFigure() == NULL);
            if(firstMove && (next.at(0) != NULL) && (next.at(0) -> getPFigure() == NULL))
            {

                moves.push_back(next.at(0));
            }
            else if(next.size() == 0)
            {
                //end of board
                //EVOLUTION!!!
            }

        }
        qDebug() << nextMove->getLetter();
        qDebug() << nextMove->getNumber();
        qDebug() << next.at(0)->getLetter();
        qDebug() << next.at(0)->getNumber();

        next = this->findAttack();
        if(next.size() != 0)
        {
            while(next.size())
            {

                moves.push_back(next.at(next.size()-1));
                next.pop_back();
            }
        }
        return moves;
    }
    else
    {
        return vector<Square*>();
    }

}

void Pawn::setPNext(Square* pNext)
{
    this->nextMove = pNext;
}


//function which check, has pawn moves to attack, or has not
vector<Square *> Pawn::findAttack()
{
    vector<Square*> diag = this->getPSquare()->getPDiag();
    vector<Square*> attack;

    Square* cur = this->getPSquare();
    Square*next = this->nextMove;

    if(cur == Game::squares[28] && next == Game::squares[38])
    {
        if(Game::squares[39] -> getPFigure() != NULL)
            attack.push_back(Game::squares[39]);
        if(Game::squares[37] -> getPFigure() != NULL)
            attack.push_back(Game::squares[37]);
        if(Game::squares[35] -> getPFigure() != NULL)
            attack.push_back(Game::squares[35]);
        return attack;
    }
    else if(cur == Game::squares[27] && next == Game::squares[35])
    {
        if(Game::squares[34] -> getPFigure() != NULL)
            attack.push_back(Game::squares[34]);
        if(Game::squares[36] -> getPFigure() != NULL)
            attack.push_back(Game::squares[36]);
        if(Game::squares[28] -> getPFigure() != NULL)
            attack.push_back(Game::squares[28]);
        return attack;
    }
    else if(cur == Game::squares[27] && next == Game::squares[28])
    {
        if(Game::squares[20] -> getPFigure() != NULL
                && Game::squares[20]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[20]);
        if(Game::squares[38] -> getPFigure() != NULL
                && Game::squares[38]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[38]);
        if(Game::squares[36] -> getPFigure() != NULL
                && Game::squares[36]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[36]);
            return attack;
    }
    else if(cur == Game::squares[35] && next == Game::squares[27])
    {
        if(Game::squares[26] -> getPFigure() != NULL
                && Game::squares[26]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[26]);
        if(Game::squares[37] -> getPFigure() != NULL
                && Game::squares[37]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[37]);
        if(Game::squares[28] -> getPFigure() != NULL
                && Game::squares[28]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[28]);
            return attack;
    }
    else if(cur == Game::squares[36] && next == Game::squares[37])
    {
        if(Game::squares[38] -> getPFigure() != NULL
                && Game::squares[38]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[38]);
        if(Game::squares[27] -> getPFigure() != NULL
                && Game::squares[27]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[27]);
        if(Game::squares[49] -> getPFigure() != NULL
                && Game::squares[49]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[49]);
            return attack;
    }
    else if(cur == Game::squares[37] && next == Game::squares[36])
    {
        if(Game::squares[48] -> getPFigure() != NULL
                && Game::squares[48]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[48]);
        if(Game::squares[28] -> getPFigure() != NULL
                && Game::squares[28]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[28]);
        if(Game::squares[35] -> getPFigure() != NULL
                && Game::squares[35]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[35]);
            return attack;
    }
    else if(cur == Game::squares[38] && next == Game::squares[28])
    {
        if(Game::squares[29] -> getPFigure() != NULL
                && Game::squares[29]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[29]);
        if(Game::squares[27] -> getPFigure() != NULL
                && Game::squares[27]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[27]);
        if(Game::squares[36] -> getPFigure() != NULL
                && Game::squares[36]->getPFigure()->getColor() != getColor())
            attack.push_back(Game::squares[36]);
            return attack;
    }
    //check 5 diaganls, pawn attack at diag's
    for(int i = 0; i < 5; i++)
    {
        if(diag[i] != NULL)
        {
            if(diag[i]->getPLeft() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
            {
                attack.push_back(diag[i]);
            }
            if(diag[i]->getPRight() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
            {
                attack.push_back(diag[i]);
            }
            if(diag[i]->getPTop() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
            {
                attack.push_back(diag[i]);
            }
            if(diag[i]->getPBottom() == nextMove && diag[i]->getPFigure() != NULL && diag[i]->getPFigure()->getColor() != getColor())
            {
                attack.push_back(diag[i]);
            }
        }
    }
    return attack;
}

void Pawn::setNextMove()
{

}

