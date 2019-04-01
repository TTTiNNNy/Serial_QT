#ifndef SERIALTESTER_H
#define SERIALTESTER_H

#include <QObject>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>

#include <QSerialPort>
#include <QSerialPortInfo>

class SerialTester : QObject
{
    Q_OBJECT

public:
    SerialTester(
            QComboBox *portBox_, QLabel *statusLabel_,
            QCheckBox *activeBox_, QLineEdit *receivedData_);

    void rescanAvailablePorts();
    void sendTestMessage(QString message);

private:
    bool needSend = false;

    QSerialPort port;
    QComboBox *portBox;
    QCheckBox *activeBox;
    QLineEdit *receivedData;
    QLabel *statusLabel;

private slots:
    void onPortBoxSelected(QString arg);
    void handleReadyRead();
};

#endif // SERIALTESTER_H
