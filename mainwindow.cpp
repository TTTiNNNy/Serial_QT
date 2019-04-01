#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString message = "Hello from ";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    com1 = new SerialTester(ui->COM1_portBox, ui->COM1_status, ui->COM1_activeBox, ui->COM1_receivedData);
    com2 = new SerialTester(ui->COM2_portBox, ui->COM2_status, ui->COM2_activeBox, ui->COM2_receivedData);
    com3 = new SerialTester(ui->COM3_portBox, ui->COM3_status, ui->COM3_activeBox, ui->COM3_receivedData);
    com4 = new SerialTester(ui->COM4_portBox, ui->COM4_status, ui->COM4_activeBox, ui->COM4_receivedData);
    com5 = new SerialTester(ui->COM5_portBox, ui->COM5_status, ui->COM5_activeBox, ui->COM5_receivedData);
}

MainWindow::~MainWindow()
{
    delete com1;
    delete com2;
    delete com3;
    delete com4;
    delete com5;

    delete ui;
}

void MainWindow::on_sendDataBtn_clicked()
{
    com1->sendTestMessage(message + "1");
    com2->sendTestMessage(message + "2");
    com3->sendTestMessage(message + "3");
    com4->sendTestMessage(message + "4");
    com5->sendTestMessage(message + "5");
}

void MainWindow::on_rescanPorts_clicked()
{
    com1->rescanAvailablePorts();
    com2->rescanAvailablePorts();
    com3->rescanAvailablePorts();
    com4->rescanAvailablePorts();
    com5->rescanAvailablePorts();
}
