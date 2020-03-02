#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
//#include <ranges>
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
    void paintEvent(QPaintEvent * event);


private slots:
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    const int board_size = 14;
    const int board_margin_distance = 30;
    const int block_size = 40;
};

#endif // MAINWINDOW_H
