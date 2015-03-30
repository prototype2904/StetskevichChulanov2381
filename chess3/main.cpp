#include <QApplication>
#include <QQmlApplicationEngine>
#include "square.h"
#include "fstream"
#include "form.h"
#include "board.h"

int main(int argc, char *argv[])
{
    std::fstream file;
    file.open("C:\\Users\\Roman\\Documents\\QT\\chess3\\squares.txt");
    vector<Square*> sq;
    for(int i = 0; i < 96; i++)
    {
        Square *newSquare = new Square();
        sq.push_back(newSquare);
    }
    int num = 0;
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
            sq[num++]->set(squares[0], squares[1], squares[2], squares[3], pDiag, letter,number);
        }
    }
    file.close();
    file.open("C:\\Users\\Roman\\Documents\\QT\\chess3\\coord 1200 700 120,120,600,520.txt");
    if(file.is_open())
    {
        num = 0;
        int x1, y1, x2, y2;
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

    QApplication app(argc, argv);
    Board w;

    w.setSquares(sq);

    w.show();
 //   QQmlApplicationEngine engine;
 //   engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
