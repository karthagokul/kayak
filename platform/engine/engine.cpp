/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "engine.h"
#include <QDebug>
#include "usbserialreader.h"
#include "usbserialwriter.h"

KayakEngine* KayakEngine::self=0;

COMSerialDevice::COMSerialDevice()
{
     connect(serialReader, &USBSerialReader::dataReady, this, &COMSerialDevice::dataReady);
}

void COMSerialDevice::write(const QByteArray &writeData)
{
    return serialWriter->write(writeData);
}

KayakEngine::KayakEngine()
{

}

KayakEngine *KayakEngine::instance()
{
    if(self==0)
        self= new KayakEngine();
    return self;
}

bool KayakEngine::startCOMDevice(const QString & device)
{
    qDebug()<<"Starting "<<device;
    return true;
}
QStringList KayakEngine::getCOMDevices()
{
    return QStringList()<<"USBCOM1"<<"USBCOM2";
}

QStringList KayakEngine::getCOMBaudRate()
{
    return QStringList()<<"116200"<<"234234";
}
