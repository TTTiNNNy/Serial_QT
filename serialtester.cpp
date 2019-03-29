#include "serialtester.h"
#include <QtDebug>

SerialTester::SerialTester(int slotsNum) {
//    for (int i = 0; i < slotsNum; i++) {

//    }
    //QSerialPort

    serial = new QVector(slotsNum);
}

QStringList SerialTester::getAvailablePorts() {
    QStringList list;

    for (QSerialPortInfo info : QSerialPortInfo::availablePorts()) {
        list << info.portName();
    }

    return list;
}

void SerialTester::reconnectPort(int portSlot, QString portName){

}
