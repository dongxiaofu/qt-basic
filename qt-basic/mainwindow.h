#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void timerEvent(QTimerEvent *);

private slots:
    void timerUpdate();

private:
    Ui::MainWindow *ui;
    int id1, id2, id3;
};
#endif // MAINWINDOW_H
