/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "usbserialwriter.h"


#include <QCoreApplication>

USBSerialWriter::USBSerialWriter(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    m_timer.setSingleShot(true);
    connect(m_serialPort, &QSerialPort::bytesWritten,
            this, &USBSerialWriter::onBytesWritten);
    connect(m_serialPort, &QSerialPort::errorOccurred,
            this, &USBSerialWriter::onError);
    connect(&m_timer, &QTimer::timeout, this, &USBSerialWriter::onTimeout);
}

void USBSerialWriter::onBytesWritten(qint64 bytes)
{
    m_bytesWritten += bytes;
    if (m_bytesWritten == m_writeData.size()) {
        m_bytesWritten = 0;
        m_standardOutput << QObject::tr("Data successfully sent to port %1")
                            .arg(m_serialPort->portName()) << "\n";
        QCoreApplication::quit();
    }
}

void USBSerialWriter::onTimeout()
{
    m_standardOutput << QObject::tr("Operation timed out for port %1, error: %2")
                        .arg(m_serialPort->portName())
                        .arg(m_serialPort->errorString())
                     << "\n";
    QCoreApplication::exit(1);
}

void USBSerialWriter::onError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::WriteError) {
        m_standardOutput << QObject::tr("An I/O error occurred while writing"
                                        " the data to port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << "\n";
        QCoreApplication::exit(1);
    }
}

void USBSerialWriter::write(const QByteArray &writeData)
{
    m_writeData = writeData;

    const qint64 bytesWritten = m_serialPort->write(writeData);

    if (bytesWritten == -1) {
        m_standardOutput << QObject::tr("Failed to write the data to port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << "\n";
        QCoreApplication::exit(1);
    } else if (bytesWritten != m_writeData.size()) {
        m_standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << "\n";
        QCoreApplication::exit(1);
    }

    m_timer.start(5000);
}
