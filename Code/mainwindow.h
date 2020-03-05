#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
//#include <ranges>
#include <cmath>
#include <vector>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mouseClick(QMouseEvent *event);

private slots:
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    int xPosGrid;
    int yPosGrid;
    const int boardSize = 16;
    const int boardMarginDistance = 30;
    const int blockSize = 40;
};

#endif // MAINWINDOW_H
