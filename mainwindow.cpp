#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtWidgets>

QSerialPort serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
