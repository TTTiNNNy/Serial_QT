#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_COM1_portBox_currentTextChanged(const QString &arg1);
    void on_COM2_portBox_currentTextChanged(const QString &arg1);
    void on_COM3_portBox_currentTextChanged(const QString &arg1);
    void on_COM4_portBox_currentTextChanged(const QString &arg1);
    void on_COM5_portBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};



int task2(int);


#endif // MAINWINDOW_H
