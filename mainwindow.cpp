#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <serialtester.h>

SerialTester serial(5);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList ports = serial.getAvailablePorts();
    ui->COM1_portBox->addItems(ports);
    ui->COM2_portBox->addItems(ports);
    ui->COM3_portBox->addItems(ports);
    ui->COM4_portBox->addItems(ports);
    ui->COM5_portBox->addItems(ports);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendDataBtn_clicked()
{
    // serial.sendSelected();
}

// ---------------------------- Port change events ----------------------------
void MainWindow::on_COM1_portBox_currentTextChanged(const QString &arg1) {
    serial.reconnectPort(1, arg1);
}

void MainWindow::on_COM2_portBox_currentTextChanged(const QString &arg1) {
    serial.reconnectPort(2, arg1);
}

void MainWindow::on_COM3_portBox_currentTextChanged(const QString &arg1) {
    serial.reconnectPort(3, arg1);
}

void MainWindow::on_COM4_portBox_currentTextChanged(const QString &arg1) {
    serial.reconnectPort(4, arg1);
}

void MainWindow::on_COM5_portBox_currentTextChanged(const QString &arg1) {
    serial.reconnectPort(5, arg1);
}
