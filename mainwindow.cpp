#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtWidgets>

QSerialPort serial;

using namespace std;
int a;

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
    a=task3();
    std::thread *test = new std::thread(task2,5);
    ui->label->setText(QString::number(a));
    ui->label->setText(QString::number(a));
}


int MainWindow::task1(int msg)
{
    for (int i=0;i<100;i++) {
        msg++;
    }

    return msg;
}

int task2(int msg)
{
    for (int i = 0; i < 100; i++) {
        msg--;
    }

    a=msg;
    return msg;
}

int MainWindow::task3()
{
    int msg=100;
    for (int i=0;i<100;i++) {
        msg--;
    }

    return msg;
}
