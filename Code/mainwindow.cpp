#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    setFixedSize(boardMarginDistance * 2 + blockSize * boardSize,  //width
                 boardMarginDistance * 2 + blockSize * boardSize); //height
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    std::vector<int> board_rel;
    for (int i = 0; i < boardSize + 1; ++i)
    {
        board_rel.push_back(i);
    }
    for (auto i : board_rel)
    {
        painter.drawLine(boardMarginDistance + blockSize * i,
                         boardMarginDistance,
                         boardMarginDistance + blockSize * i,
                         size().height() - boardMarginDistance);
        painter.drawLine(boardMarginDistance,
                         boardMarginDistance + blockSize * i,
                         size().width() - boardMarginDistance,
                         boardMarginDistance + blockSize * i);
    }
}

void MainWindow::mouseClick(QMouseEvent *event)
{
    if (event->x() >= boardMarginDistance && event->x() <= size().width() - boardMarginDistance &&
        event->y() >= boardMarginDistance &&
        event->y() <= size().height() - boardMarginDistance)
    {
        xPosGrid = std::round(double(event->x()) / double(blockSize));
        yPosGrid = std::round(double(event->y()) / double(blockSize));
    }
}
