/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef USBSERIALWRITER_H
#define USBSERIALWRITER_H

#include <QByteArray>
#include <QObject>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>

class USBSerialWriter : public QObject
{
    Q_OBJECT
public:
    explicit USBSerialWriter(QSerialPort *serialPort, QObject *parent = nullptr);
    void write(const QByteArray &writeData);

private slots:
    void onBytesWritten(qint64 bytes);
    void onTimeout();
    void onError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_writeData;
    QTextStream m_standardOutput;
    qint64 m_bytesWritten = 0;
    QTimer m_timer;
};

#endif // USBSERIALWRITER_H
