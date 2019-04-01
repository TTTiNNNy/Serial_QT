#include <QtDebug>
#include <QString>

#include "serialtester.h"

SerialTester::SerialTester(QComboBox *portBox, QLabel *statusLabel, QCheckBox *activeBox, QLineEdit *transmittedData, QLineEdit *receivedData)
{
    this->portBox           =   portBox;
    this->activeBox         =   activeBox;
    this->statusLabel       =   statusLabel;
    this->transmittedData   =   transmittedData;
    this->receivedData      =   receivedData;

    this->rescanAvailablePorts();

    connect(portBox,   SIGNAL(currentTextChanged(QString)), this, SLOT(onPortBoxSelected(QString)) );
    connect(&port,     SIGNAL(readyRead()),                 this, SLOT(handleReadyRead())          );

}

void SerialTester::onPortBoxSelected(QString arg)
{
    if (port.isOpen())
    {
        port.close();
    }

    if (arg != "--")
    {
        port.setPortName(arg);
        port.open(QIODevice::ReadWrite);
    }
}

void SerialTester::rescanAvailablePorts()
{
    portBox->clear();
    portBox->addItem("--");

    for (QSerialPortInfo info : QSerialPortInfo::availablePorts())
    {
        portBox->addItem(info.portName());
    }
}

// ---------- Send ----------
void SerialTester::sendTestMessage()
{
    clearReceiveBox();
    if (activeBox->isChecked())
    {
        if (port.isOpen())
        {

            port.write(this->activeBox->text().toUtf8()+": "+this->transmittedData->text().toUtf8());
        }
        else
        {
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

void SerialTester::clearReceiveBox()
{
    this->receivedData->clear();
}
