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
    int task1(int);

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    int task3();
};



int task2(int);


#endif // MAINWINDOW_H
