#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    id1 = startTimer(1000);  // 开启一个1秒定时器，返回其ID
    id2 = startTimer(2000);
    id3 = startTimer(10000);

    QTimer *timer = new QTimer(this);
    //关联定时器溢出信号和相应的槽函数
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
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

void MainWindow::timerEvent(QTimerEvent *event)
{
   if (event->timerId() == id1) {       // 判断是哪个定时器
       ui->label->setText(tr("%1").arg(qrand()%10));
   }
   else if (event->timerId() == id2) {
       ui->label_2->setText(tr("hello world!"));
   }
   else {
       qApp->quit();
   }
}

void MainWindow::timerUpdate()
{
   //获取系统现在的时间
   QDateTime time = QDateTime::currentDateTime();
   //设置系统时间显示格式
   QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
   //在标签上显示时间
   ui->lineEdit->setText(str);

   int rand = qrand() % 300;            // 产生300以内的正整数
   ui->lineEdit->move(rand, rand);
}
