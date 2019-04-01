#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <serialtester.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sendDataBtn_clicked();

private:
    Ui::MainWindow *ui;

    SerialTester *com1, *com2, *com3, *com4, *com5;
};



int task2(int);


#endif // MAINWINDOW_H
