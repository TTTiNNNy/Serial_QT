#include <QtDebug>
#include <QString>

#include "serialtester.h"

SerialTester::SerialTester(
        QComboBox *portBox_, QLabel *statusLabel_,
        QCheckBox *activeBox_, QLineEdit *receivedData_)
{
    portBox = portBox_;
    activeBox = activeBox_;
    statusLabel = statusLabel_;
    receivedData = receivedData_;

    this->rescanAvailablePorts();

    connect(portBox,   SIGNAL(currentTextChanged(QString)), this, SLOT(onPortBoxSelected(QString)) );
    connect(&port,     SIGNAL(readyRead()),                 this, SLOT(handleReadyRead())          );
}

void SerialTester::onPortBoxSelected(QString arg) {
    if (port.isOpen()) {
        port.close();
    }

    if (arg != "--") {
        port.setPortName(arg);
        port.open(QIODevice::ReadWrite);
    }
}

void SerialTester::rescanAvailablePorts()
{
    portBox->clear();
    portBox->addItem("--");

    for (QSerialPortInfo info : QSerialPortInfo::availablePorts()) {
        portBox->addItem(info.portName());
    }
}

// ---------- Send ----------
void SerialTester::sendTestMessage(QString message) {
    if (activeBox->isChecked()) {
        if (port.isOpen()) {
            QByteArray data = message.toUtf8();
            port.write(data);
        } else {
            //statusLabel->setText("Порт не открыт!");
        }
    }
}

// --------- Receive --------
void SerialTester::handleReadyRead()
{
    QString str(port.readAll());
    receivedData->setText(str);
}
