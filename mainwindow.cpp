#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Video File (*.mpg)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}


void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Pause");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stoped");
}
