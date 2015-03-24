#include "board.h"
#include "ui_board.h"
Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    resize(1200,700);
}
void Board::setSquares(vector<Square*>sq)
{
    this->squares = sq;
}

Board::~Board()
{
    delete ui;
}
