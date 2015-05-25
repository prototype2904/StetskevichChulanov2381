#include "test.h"
#include"king.h"
#include"pawn.h"
#include"queen.h"
Test::Test()
{
}

void Test::testPawnEvolution(vector<Square*> &squares)
{
    Player zero, first, second;
    King *zeroKing, *firstKing, *secondKing;
    //Zero team(front)
    zero.setColor(0);
    zero.setPlay(true);

    squares[59] -> setPFigure(new Pawn(squares[59], squares[77], 0));
    zero.addFigure(squares[59] -> getPFigure());

    squares[17] -> setPFigure(new Queen(squares[17],0));
     zero.addFigure(squares[17] -> getPFigure());
    zeroKing = new King(squares[4],0);
    squares[4] -> setPFigure(zeroKing);
     zero.addFigure(squares[4] -> getPFigure());


    //First Team(left side);
     first.setColor(1);
     first.setPlay(true);

        squares[72] -> setPFigure(new Pawn(squares[72], squares[94], 1));
        squares[25] -> setPFigure(new Queen(squares[25],1));
         first.addFigure(squares[25] -> getPFigure());
 first.addFigure(squares[72] -> getPFigure());
    firstKing = new King(squares[74],1);
    squares[74] -> setPFigure(firstKing);


    first.addFigure(squares[74] -> getPFigure());

    //Second Team(right side);

    second.setColor(2);
    second.setPlay(true);

        squares[9] -> setPFigure(new Pawn(squares[9], squares[1], 2));
        second.addFigure(squares[9] -> getPFigure());
        squares[67] -> setPFigure(new Queen(squares[67],2));
         second.addFigure(squares[67] -> getPFigure());

    secondKing = new King(squares[92],2);
    squares[91] -> setPFigure(secondKing);
    second.addFigure(squares[91] -> getPFigure());

    Game::players.push_back(zero);
    Game::players.push_back(first);
    Game::players.push_back(second);


    Game::players[0].setKing(zeroKing);
    Game::players[1].setKing(firstKing);
    Game::players[2].setKing(secondKing);
}
