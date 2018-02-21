#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_A_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", "", "Audio File name (*.mp3)");
    on_actionStop_triggered();
    player->setMedia(QUrl::fromLocalFile(fileName));
    on_actionPlay_triggered();
    qDebug() << player->errorString();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("Paused...");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("Stopped");
}

void MainWindow::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}
