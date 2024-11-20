/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "usbserialreader.h"
#include <QSerialPort>
#include <QCoreApplication>

USBSerialReader::USBSerialReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &USBSerialReader::onReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &USBSerialReader::onError);
    connect(&m_timer, &QTimer::timeout, this, &USBSerialReader::onTimeout);

    m_timer.start(5000);
}

void USBSerialReader::onReadyRead()
{
    m_readData.append(m_serialPort->readAll());

    if (!m_timer.isActive())
        m_timer.start(5000);

    emit dataReady(m_readData);
}

void USBSerialReader::onTimeout()
{
    if (m_readData.isEmpty()) {
        m_standardOutput << QObject::tr("No data was currently available "
                                        "for reading from port %1")
                            .arg(m_serialPort->portName())
                         << "\n";
    } else {
        m_standardOutput << QObject::tr("Data successfully received from port %1")
                            .arg(m_serialPort->portName())
                         << "\n";
        m_standardOutput << m_readData << "\n";
    }

    QCoreApplication::quit();
}

void USBSerialReader::onError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading "
                                        "the data from port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << "\n";
        QCoreApplication::exit(1);
    }
}
