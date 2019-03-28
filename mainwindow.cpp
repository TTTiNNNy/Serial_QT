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

//    if(ui->checkBox->isChecked()){std::thread t1(SerialSend,ui->comboBox->currentText(),ui->plainTextEdit->toPlainText());}
//    if(ui->checkBox_2->isChecked()){std::thread t2(SerialSend);}
//    if(ui->checkBox_3->isChecked()){std::thread t3(SerialSend);}
//    if(ui->checkBox_4->isChecked()){std::thread t4(SerialSend);}
//    if(ui->checkBox_5->isChecked()){std::thread t5(SerialSend);}




    std::thread *test= new std::thread(task2,5);
   ui->label->setText(QString::number(a));
   ui->label->setText(QString::number(a));

}
int task1(int msg)
{
    for (int i=0;i<100;i++) {
        msg++;
    }

    return msg;
}
int task2(int msg)
{
    for (int i=0;i<100;i++) {
        msg--;
    }
    a=msg;
    return msg;
}
int task3()
{
    int msg=100;
    for (int i=0;i<100;i++) {
        msg--;
    }

    return msg;
}
//void SerialSend()
//{

//    QByteArray data = (ui.->text() + "\n").toUtf8();
//    serial.write(data);
//    }
//}
