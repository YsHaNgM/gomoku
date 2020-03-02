#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    setFixedSize(board_margin_distance * 2 + block_size * board_size, //width
                     board_margin_distance * 2.5 + block_size * board_size);
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
    for (int i = 0; i < board_size+1; ++i)
    {
        board_rel.push_back(i);
    }
    for (auto i : board_rel)
    {
        painter.drawLine(board_margin_distance + block_size * i,
                                 board_margin_distance * 1.5,
                                 board_margin_distance + block_size * i,
                                 size().height() - board_margin_distance);
        painter.drawLine(board_margin_distance,
                                 board_margin_distance * 1.5 + block_size * i,
                                 size().width() - board_margin_distance,
                                 board_margin_distance * 1.5 + block_size * i);
    }
}
