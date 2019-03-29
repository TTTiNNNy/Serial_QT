#ifndef SERIALTESTER_H
#define SERIALTESTER_H

#include <QStringList>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialTester
{
public:
    SerialTester(int slotsNum);
    QStringList getAvailablePorts();
    void reconnectPort(int portSlot, QString portName);

private:
    QVector<QSerialPort> *serial;
};

#endif // SERIALTESTER_H
