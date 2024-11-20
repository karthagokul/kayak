/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
 *******************************************************************
*/
#ifndef USBSERIALREADER_H
#define USBSERIALREADER_H

#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>

class USBSerialReader : public QObject
{
    Q_OBJECT
public:
    explicit USBSerialReader(QSerialPort *serialPort, QObject *parent = nullptr);

private slots:
    void onReadyRead();
    void onTimeout();
    void onError(QSerialPort::SerialPortError error);
signals:
    void dataReady(const QByteArray &data);
private:
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_readData;
    QTextStream m_standardOutput;
    QTimer m_timer;
};

#endif // USBSERIALREADER_H
