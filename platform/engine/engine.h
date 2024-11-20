/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef KAYAKENGINE_H
#define KAYAKENGINE_H

#include <QObject>
#include <QSerialPort>

class USBSerialReader;
class USBSerialWriter;
class CANInbox;
class CANOutbox;


class COMSerialDevice: public QObject {
    Q_OBJECT
private:
    bool active=false;
    QSerialPort serialPort;
    USBSerialWriter *serialWriter=0;
    USBSerialReader *serialReader=0;
public:
    explicit COMSerialDevice();

signals:
    void dataReady(const QByteArray &data);
public slots:
    void write(const QByteArray &writeData);
};

class KayakEngine:public QObject
{
private:
    KayakEngine();
    static KayakEngine *self;
    COMSerialDevice *activeDevice =0;
    CANInbox *cinbox=0;
    CANOutbox *coutbox=0;


public:
    COMSerialDevice* getCOMDevice()
    {
        return activeDevice;
    }
    CANInbox *inbox()
    {
        return cinbox;
    }

    CANOutbox *outbox()
    {
        return coutbox;
    }

    static KayakEngine *instance();
    QStringList getCOMDevices();
    QStringList getCOMBaudRate();
    bool startCOMDevice(const QString & device);
};

#endif // KAYAKENGINE_H
