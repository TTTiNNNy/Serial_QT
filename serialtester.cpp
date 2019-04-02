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

    connect(&port,
        SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
        this,
        SLOT(handlePortError(QSerialPort::SerialPortError))
    );

    setStatus(DISCONNECTED);
}

void SerialTester::onPortBoxSelected(QString arg)
{
    if (port.isOpen())
    {
        port.close();
        setStatus(DISCONNECTED);
    }

    if (arg != "--")
    {
        port.setPortName(arg);
        if (port.open(QIODevice::ReadWrite)) {
            setStatus(CONNECTED);
        }
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

void SerialTester::setStatus(enum serialStatus status)
{
    QPalette palette = statusLabel->palette();

    switch(status) {
    case CONNECTED:
        palette.setColor(QPalette::WindowText, Qt::GlobalColor::darkGreen);
        statusLabel->setText("+");
        break;
    case DISCONNECTED:
        palette.setColor(QPalette::WindowText, Qt::GlobalColor::red);
        statusLabel->setText("-");
        break;
    }

    statusLabel->setPalette(palette);
}

void SerialTester::handlePortError(QSerialPort::SerialPortError error) {
    if (error == QSerialPort::ReadError ||
        error == QSerialPort::WriteError ||
        error == QSerialPort::ResourceError ||
        error == QSerialPort::UnknownError)
    {
        port.close();
        port.clearError();
        clearReceiveBox();
        portBox->setCurrentIndex(0);
        setStatus(DISCONNECTED);
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
            setStatus(CONNECTED);
            port.write(this->activeBox->text().toUtf8()+": "+this->transmittedData->text().toUtf8());
        }
        else
        {
            setStatus(DISCONNECTED);
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
