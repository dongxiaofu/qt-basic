#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
   ui->pushButton->setText(tr("(%1,%2)").arg(e->x()).arg(e->y()));
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
   int x = ui->pushButton->x();
   int y = ui->pushButton->y();
   switch (e->key())
   {
       case Qt::Key_W : ui->pushButton->move(x, y-10); break;
       case Qt::Key_S : ui->pushButton->move(x, y+10); break;
       case Qt::Key_A : ui->pushButton->move(x-10, y); break;
       case Qt::Key_D : ui->pushButton->move(x+10, y); break;
   }
}


void MainWindow::on_pushButton_clicked()
{

}
