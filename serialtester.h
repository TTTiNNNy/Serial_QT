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
    SerialTester(QComboBox*, QLabel*, QCheckBox*, QLineEdit*, QLineEdit*);
    void rescanAvailablePorts();
    void sendTestMessage();

private:
    enum serialStatus { CONNECTED, DISCONNECTED };
    void setStatus(enum serialStatus status);

    void clearReceiveBox();
    bool needSend = false;

    QSerialPort port;
    QComboBox *portBox;
    QCheckBox *activeBox;
    QLineEdit *transmittedData;
    QLineEdit *receivedData;
    QLabel *statusLabel;

private slots:
    void onPortBoxSelected(QString arg);
    void handleReadyRead();
    void handlePortError(QSerialPort::SerialPortError);
};

#endif // SERIALTESTER_H
