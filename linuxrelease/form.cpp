#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

void Form::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
//    painter.drawImage();
    painter.drawPixmap(0, 0, QPixmap(":/image/border.png"));
    QWidget::paintEvent(pe);
}

Form::~Form()
{
    delete ui;
}
