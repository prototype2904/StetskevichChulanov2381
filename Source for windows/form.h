#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
